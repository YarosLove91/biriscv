#include "print_functions.h"

#define TEST_LW(testnum, expected, offset, base) do { \
    int32_t result = 0; \
    int32_t* addr = (int32_t*)((uint8_t*)(base) + (offset)); \
    asm volatile( \
        "lw %[res], 0(%[addr])\n\t" \
        : [res] "=r"(result) \
        : [addr] "r"(addr) \
        : "memory" \
    ); \
    PRINT_LOAD_RESULT("LW", testnum, offset, result, expected); \
} while (0)