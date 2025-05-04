#include <stdio.h>
#include <stdint.h>
#include "periphery.h"

int main(void) {
    printf("-Start periphery test-\n");

    volatile int a;

    a = 5;

    printf("a = %d\n", a);

    volatile rtc_t *rtc = (rtc_t*) RTC_BA;

    uint32_t timer_period = 0x96;
    uint32_t timer_cfg = TIMER_CFG_EN_MASK | TIMER_CFG_RETRIG_MASK | ((timer_period << TIMER_CFG_TARGET_POS) & TIMER_CFG_TARGET_MASK);
    rtc->timer_cfg = timer_cfg;
    rtc->update = UPDATE_TIMER_MASK;

    uint32_t alarm_date = 0x20241215;
    uint32_t alarm_time = 0x12559;
    uint32_t alarm_flags = 0x0;
    uint32_t alarm_clock_val =  ( ALARM_CLOCK_EN_MASK | 
                                 ((alarm_time << ALARM_CLOCK_DATA_POS)      & ALARM_CLOCK_DATA_MASK) |
                                 ((alarm_flags << ALARM_CLOCK_MATCH_MSK_POS) & ALARM_CLOCK_MATCH_MSK_MASK)
                                );
    rtc->alarm_clock = alarm_clock_val;
    rtc->alarm_date = alarm_date;
    rtc->update = (UPDATE_ALARM_CLOCK_MASK | UPDATE_ALARM_DATE_MASK);


    uint32_t calibration_value = 9;
    rtc->calibre = calibration_value;
    rtc->update = UPDATE_CALIBRE_MASK;

    uint32_t initial_time = 0x12345;
    uint32_t initial_date = 0x20241215;

    rtc->init_clock = initial_time;
    rtc->update = UPDATE_CLOCK_MASK;

    rtc->init_date = initial_date;
    rtc->update = UPDATE_DATE_MASK;

    volatile uint32_t start_time = rtc->clock;
    printf("start_time raw: 0x%x", start_time);

    // dummy delay
    for (int i = 0; i++; i < 100)
    {
        uint32_t a = i + 1;
    }

    volatile uint32_t end_time = rtc->clock;
    printf("end_time raw: 0x%x", end_time);

    return 0;
}