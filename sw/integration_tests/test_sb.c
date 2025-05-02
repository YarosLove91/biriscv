#include "print_functions.h"

#define TEST_SB(testnum, value, expected, offset, base) do { \
    int32_t result = 0; \
    uint8_t* addr = (uint8_t*)(base) + (offset); \
    asm volatile( \
        "sb %[val], 0(%[addr])\n\t" \
        : \
        : [val] "r"(value), [addr] "r"(addr) \
        : "memory" \
    ); \
    asm volatile( \
        "lb %[res], 0(%[addr])\n\t" \
        : [res] "=r"(result) \
        : [addr] "r"(addr) \
        : "memory" \
    ); \
    PRINT_STORE_RESULT("SB", testnum, offset, value, result, expected); \
} while (0)