#ifndef PRINT_HELPERS_H
#define PRINT_HELPERS_H

#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

// ========== PRINT RESULT ==========

#define PRINT_RESULT(opname, testnum, val1, val2, result, expected) \
    printf("Test %2d: "opname " 0x%08" PRIx32 " op 0x%08" PRIx32 " = 0x%08" PRIx32 \
           " (expected: 0x%08" PRIx32 ") %s\n", \
           (testnum), (val1), (val2), (result), (expected), \
           ((result) == (expected)) ? "PASSED" : "FAILED")

// ========== PRINT BRANCH RESULT ==========

#define PRINT_BRANCH_RESULT(opname, testnum, val1, val2, result, expected) \
    printf(opname " Test %2d: %11" PRId32 " == %11" PRId32 " → %s (expected: %s) %s\n", \
        (testnum), (val1), (val2), \
        (result) ? "taken" : "not taken", \
        (expected) ? "taken" : "not taken", \
        ((result) == (expected)) ? "PASSED" : "FAILED")

// ========== PRINT LOAD RESULT ==========

#define PRINT_LOAD_RESULT(opname, testnum, offset, result, expected) do { \
    if ((result) == (expected)) \
        printf("Test %2d: " opname " (offset=%d) -> 0x%08x PASSED\n", (testnum), (offset), (result)); \
    else \
        printf("Test %2d: " opname " (offset=%d) -> 0x%08x FAILED (expected 0x%08x)\n", \
            (testnum), (offset), (result), (expected)); \
} while (0)

// ========== PRINT STORE RESULT ==========

#define PRINT_STORE_RESULT(opname, testnum, offset, value, result, expected) do { \
    if ((result) == (expected)) \
        printf("Test %2d: " opname " (offset=%d, value=0x%08x) -> 0x%08x PASSED\n", \
               (testnum), (offset), (value), (result)); \
    else \
        printf("Test %2d: " opname " (offset=%d, value=0x%08x) -> 0x%08x FAILED (expected 0x%08x)\n", \
               (testnum), (offset), (value), (result), (expected)); \
} while (0)

#endif