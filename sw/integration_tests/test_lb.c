#include "print_functions.h"

#define TEST_LB(testnum, expected, offset, base) do { \
    int32_t result = 0; \
    int8_t* addr = (int8_t*)(base) + (offset); \
    asm volatile( \
        "lb %[res], 0(%[addr])\n\t" \
        : [res] "=r"(result) \
        : [addr] "r"(addr) \
        : "memory" \
    ); \
    PRINT_LOAD_RESULT("LB", testnum, offset, result, expected); \
} while (0)