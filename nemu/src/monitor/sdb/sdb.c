#include <isa.h>
#include <cpu/cpu.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <memory/vaddr.h>
#include "sdb.h"

static int is_batch_mode = false;

void init_regex();
void init_wp_pool();
void watchpoint_display();
void wp_add(char *what);
void wp_del(int no);

/* We use the `readline' library to provide more flexibility to read from stdin. */
static char *rl_gets()
{
    static char *line_read = NULL;

    if (line_read)
    {
        free(line_read);
        line_read = NULL;
    }

    line_read = readline("(nemu) ");

    if (line_read && *line_read)
    {
        add_history(line_read);
    }

    return line_read;
}

static int cmd_c(char *args)
{
    cpu_exec(-1);
    return 0;
}

static int cmd_q(char *args)
{
    nemu_state.state = NEMU_QUIT;
    return -1;
}

static int cmd_help(char *args);

static int cmd_si(char *args)
{
    if (args == NULL)
    {
        cpu_exec(1);
    }
    else
    {
        cpu_exec(atoi(args));
    }
    return 0;
}

static int cmd_info(char *args)
{
    if (args == NULL)
    {
        printf("Usage: info r to list information about registers\n"
               "info w to list information about watchpoints\n");
    }
    else
    {
        if (strcmp(args, "r") == 0)
        {
            isa_reg_display();
            return 0;
        }
        if (strcmp(args, "w") == 0)
        {
            watchpoint_display();
            return 0;
        }
        printf("Unknown command '%s'\n", args);
    }
    return 0;
}

static int cmd_x(char *args)
{
    if (args == NULL)
    {
        printf("Usage: x N EXPR\n");
        return 0;
    }
    char arg1[32], arg2[32];
    int i = 0;
    int j = 0;
    for (; args[i] != ' ' && i < strlen(args); i++)
    {
        arg1[i] = args[i];
    }
    arg1[i] = '\0';

    for (; i < strlen(args); i++)
    {
        arg2[j++] = args[i];
    }
    arg2[j] = '\0';

    if (i == 0 || j == 0)
    {
        printf("Usage: x N EXPR\n");
        return 0;
    }

    int N = atoi(arg1);
    bool success;
    int EXPR = expr(arg2, &success);
    if (success == false)
    {
        return 0;
    }

    for (i = 0; i < N; i++)
    {
        if (i % 4 == 0)
        {
            printf("0x%x: ", EXPR + i);
        }
        printf("0x%08x    ", (uint32_t)vaddr_read(EXPR + 4 * i, 4));
        if (i % 4 == 3)
        {
            printf("\n");
        }
    }
    if (i % 4 != 3)
    {
        printf("\n");
    }
    return 0;
}

static int cmd_p(char *args)
{
    bool success;
    int EXPR = expr(args, &success);
    if (success == false)
    {
        return 0;
    }

    printf("0x%x\n", EXPR);
    return 0;
}

static int cmd_w(char *args)
{
    wp_add(args);
    return 0;
}

static int cmd_d(char *args)
{
    wp_del(atoi(args));
    return 0;
}

static struct
{
    const char *name;
    const char *description;
    int (*handler)(char *);
} cmd_table[] = {
    {"help", "Display informations about all supported commands", cmd_help},
    {"c", "Continue the execution of the program", cmd_c},
    {"q", "Exit NEMU", cmd_q},
    {"si", "Steps through a single instruction", cmd_si},
    {"info", "Lists information about the argument", cmd_info},
    {"x", "Examines the data located in memory at address", cmd_x},
    {"p", "Prints the value which the indicated expression", cmd_p},
    {"w", "Stop execution when the value of an expression changes", cmd_w},
    {"d", "Delete the watchpoint number N", cmd_d},
};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char *args)
{
    /* extract the first argument */
    char *arg = strtok(NULL, " ");
    int i;

    if (arg == NULL)
    {
        /* no argument given */
        for (i = 0; i < NR_CMD; i++)
        {
            printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        }
    }
    else
    {
        for (i = 0; i < NR_CMD; i++)
        {
            if (strcmp(arg, cmd_table[i].name) == 0)
            {
                printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
                return 0;
            }
        }
        printf("Unknown command '%s'\n", arg);
    }
    return 0;
}

void sdb_set_batch_mode()
{
    is_batch_mode = true;
}

void sdb_mainloop()
{
    if (is_batch_mode)
    {
        cmd_c(NULL);
        return;
    }

    for (char *str; (str = rl_gets()) != NULL;)
    {
        char *str_end = str + strlen(str);

        /* extract the first token as the command */
        char *cmd = strtok(str, " ");
        if (cmd == NULL)
        {
            continue;
        }

        /* treat the remaining string as the arguments,
         * which may need further parsing
         */
        char *args = cmd + strlen(cmd) + 1;
        if (args >= str_end)
        {
            args = NULL;
        }

#ifdef CONFIG_DEVICE
        extern void sdl_clear_event_queue();
        sdl_clear_event_queue();
#endif

        int i;
        for (i = 0; i < NR_CMD; i++)
        {
            if (strcmp(cmd, cmd_table[i].name) == 0)
            {
                if (cmd_table[i].handler(args) < 0)
                {
                    return;
                }
                break;
            }
        }

        if (i == NR_CMD)
        {
            printf("Unknown command '%s'\n", cmd);
        }
    }
}

void init_sdb()
{
    /* Compile the regular expressions. */
    init_regex();

    /* Initialize the watchpoint pool. */
    init_wp_pool();
}
