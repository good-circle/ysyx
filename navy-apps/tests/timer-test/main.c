#include <stdio.h>
#include <assert.h>
#include <sys/time.h>

int main()
{
    struct timeval tv;
    struct timezone tz;

    assert(gettimeofday(&tv, &tz) == 0);

    struct timeval new_tv;
    struct timezone new_tz;

    int i = 1;

    while (1)
    {
        gettimeofday(&new_tv, &new_tz);
        time_t pass = (tv.tv_sec - new_tv.tv_sec) * 1000000 + tv.tv_usec - new_tv.tv_usec;
        if (pass >= i * 500000)
        {
            i++;
            printf("%d milliseconds", i * 500);
        }
    }
}