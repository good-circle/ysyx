#include <stdio.h>
#include <assert.h>
#include <NDL.h>

int main()
{
    NDL_Init(0);
    
    uint32_t boot_time = NDL_GetTicks();

    int i = 1;

    while (1)
    {
        uint32_t current_time = NDL_GetTicks();
        if (current_time - boot_time >= i * 500)
        {
            printf("%d milliseconds", i * 500);
            i++;
        }
    }
}
