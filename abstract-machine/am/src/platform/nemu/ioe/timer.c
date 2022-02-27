#include <am.h>
#include <nemu.h>
#include <stdio.h>
static uint64_t start_time;
void __am_timer_init()
{
    start_time = inl(RTC_ADDR);
}

void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime)
{
    uptime->us = inl(RTC_ADDR) - start_time;
    printf("%d\n", uptime->us);
}

void __am_timer_rtc(AM_TIMER_RTC_T *rtc)
{
    rtc->second = 0;
    rtc->minute = 0;
    rtc->hour = 0;
    rtc->day = 0;
    rtc->month = 0;
    rtc->year = 1900;
}
