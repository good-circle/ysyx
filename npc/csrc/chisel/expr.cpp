#include <regex.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include "common.h"

#define ARRLEN(arr) (int)(sizeof(arr) / sizeof(arr[0]))

extern uint64_t isa_reg_str2val(const char *s, bool *success);
extern u_int32_t memory_read(unsigned long long addr);

enum
{
    TK_NOTYPE = 256,
    TK_EQ,
    TK_NEQ,
    TK_AND,
    TK_OR,
    TK_HEX,
    TK_DEC,
    TK_REG,
    TK_MINUS,
    TK_DEREF,
};

enum
{
    PR_0,
    PR_1,
    PR_2,
    PR_3,
    PR_4,
    PR_MAX,
};

static char reg_rule[] = "\\$\\$0|"
                         "\\$ra|"
                         "\\$sp|"
                         "\\$gp|"
                         "\\$tp|"
                         "\\$t[0-6]|"
                         "\\$s[0-9]|"
                         "\\$s1[0-1]|"
                         "\\$a[0-7]|"
                         "\\$pc";

static struct rule
{
    const char *regex;
    int token_type;
} rules[] = {

    /* TODO: Add more rules.
   * Pay attention to the precedence level of different rules.
   */

    {" +", TK_NOTYPE},             // spaces
    {"==", TK_EQ},                 // equal
    {"!=", TK_NEQ},                // not equal
    {"\\+", '+'},                  // plus
    {"-", '-'},                    // minus
    {"\\*", '*'},                  // mul
    {"/", '/'},                    // div
    {"\\(", '('},                  // left
    {"\\)", ')'},                  // right
    {"&&", TK_AND},                // and
    {"\\|\\|", TK_OR},             // or
    {"0[xX][0-9a-fA-F]+", TK_HEX}, // hex number
    {"[0-9]+", TK_DEC},            // dec number
    {reg_rule, TK_REG},            // regs
};

#define NR_REGEX ARRLEN(rules)

static regex_t re[NR_REGEX] = {};

/* Rules are used for many times.
 * Therefore we compile them only once before any usage.
 */
void init_regex()
{
    int i;
    char error_msg[128];
    int ret;

    for (i = 0; i < NR_REGEX; i++)
    {
        ret = regcomp(&re[i], rules[i].regex, REG_EXTENDED);
        if (ret != 0)
        {
            regerror(ret, &re[i], error_msg, 128);
            assert(0);
        }
    }
}

typedef struct token
{
    int type;
    char str[32];
} Token;

static Token tokens[32] __attribute__((used)) = {};
static int nr_token __attribute__((used)) = 0;

static bool make_token(char *e)
{
    int position = 0;
    int i;
    regmatch_t pmatch;

    nr_token = 0;

    while (e[position] != '\0')
    {
        /* Try all rules one by one. */
        for (i = 0; i < NR_REGEX; i++)
        {
            if (regexec(&re[i], e + position, 1, &pmatch, 0) == 0 && pmatch.rm_so == 0)
            {
                char *substr_start = e + position;
                int substr_len = pmatch.rm_eo;

                printf(COLOR_BLUE "match rules[%d] = \"%s\" at position %d with len %d: %.*s\n" COLOR_NONE,
                    i, rules[i].regex, position, substr_len, substr_len, substr_start);

                position += substr_len;

                /* TODO: Now a new token is recognized with rules[i]. Add codes
                 * to record the token in the array `tokens'. For certain types
                 * of tokens, some extra actions should be performed.
                 */

                if (substr_len >= 32)
                {
                    printf("Substring is too long.\n");
                    return false;
                }

                switch (rules[i].token_type)
                {
                case TK_NOTYPE:
                    break;
                default:
                    tokens[nr_token].type = rules[i].token_type;
                    memcpy(tokens[nr_token].str, substr_start, substr_len);
                    tokens[nr_token].str[substr_len] = '\0';
                    nr_token++;
                }
                break;
            }
        }

        if (i == NR_REGEX)
        {
            printf(COLOR_BLUE "no match at position %d\n%s\n%*.s^\n" COLOR_NONE, position, e, position, "");
            return false;
        }
    }

    return true;
}

bool check_parentheses(int p, int q, bool *success)
{
    if (*success == false)
    {
        return false;
    }

    int left_count = 0;
    int right_count = 0;

    for (int i = p; i < q; i++)
    {
        if (tokens[i].type == '(')
        {
            left_count++;
        }
        else if (tokens[i].type == ')')
        {
            right_count++;
        }

        if (right_count > left_count)
        {
            *success = false;
            return false;
        }
    }

    *success = true;
    if (tokens[p].type == '(' && tokens[q].type == ')')
    {
        return true;
    }
    else
    {
        return false;
    }
}

uint64_t find_main_op(int p, int q, bool *success)
{
    //printf("find: p=%d, q=%d\n",p,q);
    if (*success == false)
    {
        return 0;
    }

    int prior = PR_MAX;
    int position = 0;
    int cnt = 0;
    int cur_prior = PR_MAX;
    for (int i = p; i < q; i++)
    {
        /* main operator is not between () */
        if (tokens[i].type == '(')
        {
            cnt++;
        }
        else if (tokens[i].type == ')')
        {
            cnt--;
        }
        if (cnt != 0)
        {
            continue;
        }

        /* determain main operator according to priority */
        if (tokens[i].type == TK_AND || tokens[i].type == TK_OR)
        {
            cur_prior = PR_0;
        }
        else if (tokens[i].type == TK_EQ || tokens[i].type == TK_NEQ)
        {
            cur_prior = PR_1;
        }
        else if (tokens[i].type == '+' || tokens[i].type == '-')
        {
            cur_prior = PR_2;
        }
        else if (tokens[i].type == '*' || tokens[i].type == '/')
        {
            cur_prior = PR_3;
        }
        else if (tokens[i].type == TK_MINUS || tokens[i].type == TK_DEREF)
        {
            cur_prior = PR_4;
        }
        else
        {
            cur_prior = PR_MAX;
        }

        if (cur_prior < prior)
        {
            prior = cur_prior;
            position = i;
            //printf("1, pos:%d, pri=%d\n", position, prior);
        }
        else if (cur_prior == prior)
        {
            // unary operators is right to left
            position = prior == PR_4 ? position : i;
            //printf("2, pos:%d, pri=%d\n", position, prior);
        }
    }

    if (prior == PR_MAX)
    {
        *success = false;
        return 0;
    }

    *success = true;
    //printf("find: position=%d prior=%d\n", position, prior);
    return position;
}

uint64_t eval(int p, int q, bool *success)
{
    if (*success == false)
    {
        return 0;
    }

    if (p > q)
    {
        /* Bad expression */
        //printf("p:%d q:%d\n", p, q);
        printf("Wrong expression1.\n");
        *success = false;
        return 0;
    }
    else if (p == q)
    {
        /* Single token.
         * For now this token should be a number.
         * Return the value of the number.
         */
        switch (tokens[p].type)
        {
        case TK_HEX:
            return (uint64_t)strtol(tokens[p].str, NULL, 16);
        case TK_DEC:
            return (uint64_t)strtol(tokens[p].str, NULL, 10);
        case TK_REG:
            return isa_reg_str2val(tokens[p].str + 1, success);
        default:
            printf("Wrong expression2.\n");
            *success = false;
            return 0;
        }
    }
    else if (check_parentheses(p, q, success) == true)
    {
        /* The expression is surrounded by a matched pair of parentheses.
         * If that is the case, just throw away the parentheses.
         */
        return eval(p + 1, q - 1, success);
    }
    else
    {
        //printf("p=%d, q=%d\n", p, q);
        //printf("ptoken=%d, qtoken=%d\n",tokens[p].type, tokens[q].type);
        uint64_t op = find_main_op(p, q, success);
        //printf("op=%d token=%d\n",op, tokens[op].type);
        uint64_t val1 = 0;
        uint64_t val2 = 0;
        if (op >= p + 1)
        {
            val1 = eval(p, op - 1, success);
        }
        if (q >= op + 1)
        {
            val2 = eval(op + 1, q, success);
        }

        switch (tokens[op].type)
        {
        case TK_AND:
            return val1 && val2;
        case TK_OR:
            return val1 || val2;
        case TK_EQ:
            return val1 == val2;
        case TK_NEQ:
            return val1 != val2;
        case '+':
            return val1 + val2;
        case '-':
            return val1 - val2;
        case '*':
            return val1 * val2;
        case '/':
            if (val2 != 0)
            {
                return val1 / val2;
            }
            else
            {
                printf("Cannot divide zero.\n");
                *success = false;
                return 0;
            }
        case TK_MINUS:
            return -val2;
        case TK_DEREF:
            return memory_read(val2);
        default:
            //printf("op=%d token=%d\n",op, tokens[op].type);
            printf("Wrong expression3.\n");
            *success = false;
            return 0;
        }
    }
}

#define CER_TYPE tokens[i - 1].type == TK_EQ ||        \
                     tokens[i - 1].type == TK_NEQ ||   \
                     tokens[i - 1].type == '+' ||      \
                     tokens[i - 1].type == '-' ||      \
                     tokens[i - 1].type == '*' ||      \
                     tokens[i - 1].type == '/' ||      \
                     tokens[i - 1].type == '(' ||      \
                     tokens[i - 1].type == TK_AND ||   \
                     tokens[i - 1].type == TK_OR ||    \
                     tokens[i - 1].type == TK_MINUS || \
                     tokens[i - 1].type == TK_DEREF

uint64_t expr(char *e, bool *success)
{
    if (!make_token(e))
    {
        *success = false;
        return 0;
    }

    for (int i = 0; i < nr_token; i++)
    {
        if (tokens[i].type == '*' && (i == 0 || CER_TYPE))
        {
            tokens[i].type = TK_DEREF;
        }
        else if (tokens[i].type == '-' && (i == 0 || CER_TYPE))
        {
            tokens[i].type = TK_MINUS;
        }
    }

    *success = true;
    return eval(0, nr_token - 1, success);
}
