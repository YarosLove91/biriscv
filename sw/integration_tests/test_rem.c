#include "print_functions.h"


#define TEST_REM(testnum, val1, val2, expected) do { \
    int32_t result; \
    register int32_t rs1 asm("t1") = (val1); \
    register int32_t rs2 asm("t2") = (val2); \
    asm volatile ("rem %0, %1, %2" : "=r"(result) : "r"(rs1), "r"(rs2)); \
    PRINT_RESULT("REM", testnum, val1, val2, result, expected); \
} while (0)