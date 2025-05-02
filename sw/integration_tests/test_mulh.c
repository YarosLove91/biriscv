#include "print_functions.h"

#define TEST_MULH(testnum, expected, rs1, rs2) do { \
    int32_t result = 0; \
    asm volatile( \
        "mulh %[res], %[src1], %[src2]\n\t" \
        : [res] "=r"(result) \
        : [src1] "r"(rs1), [src2] "r"(rs2) \
        : "memory" \
    ); \
    PRINT_RESULT("MULH", testnum, rs1, rs2, result, expected); \
} while (0)