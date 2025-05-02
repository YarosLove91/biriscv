#include "print_functions.h"

#define TEST_LH(testnum, expected, offset, base) do { \
    int32_t result = 0; \
    int16_t* addr = (int16_t*)((uint8_t*)(base) + (offset)); \
    asm volatile( \
        "lh %[res], 0(%[addr])\n\t" \
        : [res] "=r"(result) \
        : [addr] "r"(addr) \
        : "memory" \
    ); \
    PRINT_LOAD_RESULT("LH", testnum, offset, result, expected); \
} while (0)