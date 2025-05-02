#include "print_functions.h"

#define TEST_SLL(testnum, val1, val2, expected) do { \
    int32_t result; \
    register int32_t rs1 asm("t1") = (val1); \
    register int32_t rs2 asm("t2") = (val2); \
    asm volatile ("sll %0, %1, %2" : "=r"(result) : "r"(rs1), "r"(rs2)); \
    PRINT_RESULT("SLL", testnum, val1, val2, result, expected); \
} while (0)