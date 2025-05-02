#include "print_functions.h"

#define TEST_BGE(testnum, val1, val2, expected_taken) do { \
    int32_t taken_actual; \
    register int32_t rs1 asm("t1") = (val1); \
    register int32_t rs2 asm("t2") = (val2); \
    asm volatile ( \
        "li t0, 0\n\t" \
        "bge %[v1], %[v2], 1f\n\t" \
        "j 2f\n\t" \
        "1:\n\t" \
        "li t0, 1\n\t" \
        "2:\n\t" \
        "mv %[res], t0\n\t" \
        : [res] "=r" (taken_actual) \
        : [v1] "r" (rs1), [v2] "r"(rs2) \
        : "t0" \
    ); \
    PRINT_BRANCH_RESULT("BGE", testnum, val1, val2, taken_actual, expected_taken); \
} while (0)