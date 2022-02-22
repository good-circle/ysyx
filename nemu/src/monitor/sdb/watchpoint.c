#include "sdb.h"

#define NR_WP 32

typedef struct watchpoint
{
    int NO;
    struct watchpoint *next;

    /* TODO: Add more members if necessary */
    char what[32];
    int value;
    int hit_time;
} WP;

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

void init_wp_pool()
{
    int i;
    for (i = 0; i < NR_WP; i++)
    {
        wp_pool[i].NO = i;
        wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
    }

    head = NULL;
    free_ = wp_pool;
}

/* TODO: Implement the functionality of watchpoint */
WP *new_wp()
{
    if (free_->next == NULL)
    {
        printf("No free watchpoints.\n");
    }

    WP *new_wp = free_;
    free_ = free_->next;
    new_wp->next = head;
    head = new_wp;
    return new_wp;
}

void free_wp(WP *wp)
{
    wp->next = free_;
    free_ = wp;
}

void wp_add(char *what)
{
    WP *wp = NULL;
    bool success;
    int value = expr(what, &success);
    if (success == false || (wp = new_wp()) == NULL)
    {
        return;
    }
    strcpy(wp->what, what);
    wp->value = value;
    wp->hit_time = 0;
}

void wp_del(int no)
{
    WP *wp, *prev = NULL;
    for (wp = head; wp != NULL; wp = wp->next)
    {
        if (wp->NO == no)
        {
            break;
        }
        prev = wp;
    }
    if (wp == NULL)
    {
        return;
    }

    if (prev == NULL)
    {
        head = wp->next;
    }
    else
    {
        prev->next = wp->next;
    }
}

int check_watchpoint()
{
    WP *wp = NULL;
    int count = 0;
    for (wp = head; wp != NULL; wp = wp->next)
    {
        bool success;
        int value = expr(wp->what, &success);
        if (value != wp->value)
        {
            printf("Watchpoint %d: %s\n", wp->NO, wp->what);
            printf("Old Value = 0x%x\n", wp->value);
            wp->value = value;
            printf("New Value = 0x%x\n", wp->value);
            wp->hit_time++;
            count++;
        }
    }
    if (count == 0)
    {
        return 0;
    }

    return 1;
}

void watchpoint_display()
{
    WP *wp = NULL;
    if (head == NULL)
    {
        printf("No watchpoints.\n");
    }
    else
    {
        printf("Num\t What\t\n");
        for (wp = head; wp != NULL; wp = wp->next)
        {
            printf("%d\t%s\n", wp->NO, wp->what);
            if (wp->hit_time > 0)
            {
                printf("breakpoint already hit %d time\n", wp->hit_time);
            }
        }
    }
}
