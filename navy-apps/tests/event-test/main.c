#include <stdio.h>
#include <NDL.h>

int main()
{
    NDL_Init(0);
    while (1)
    {
        char buf[64];
        if (NDL_PollEvent(buf, sizeof(buf)))
        {
            /* we do not need '\n' here as there has been a '\n' in buf */
            printf("receive event: %s", buf);
        }
    }
    return 0;
}
