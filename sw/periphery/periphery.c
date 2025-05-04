#include <stdio.h>
#include <stdint.h>

int main(void) {
    printf("-Start periphery test-\n");

    volatile int a;

    a = 5;

    printf("a = %d\n", a);

    volatile uint32_t *rtc = (volatile uint32_t *) (0x80000000 + 0x1248);
    printf("Read rtc: %lx\n", *rtc);
    *rtc = 0x123;
    printf("Read rtc: %lx\n", *rtc);
    printf("-Start periphery test-\n");

    return 0;
}