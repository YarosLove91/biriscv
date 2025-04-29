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

// ========== ADD ==========

#define TEST_ADD(testnum, val1, val2, expected) do { \
    int32_t result; \
    register int32_t rs1 asm("t1") = (val1); \
    register int32_t rs2 asm("t2") = (val2); \
    asm volatile ("add %0, %1, %2" : "=r"(result) : "r"(rs1), "r"(rs2)); \
    PRINT_RESULT("ADD ",testnum, val1, val2, result, expected); \
} while (0)

// ========== SUB ==========

#define TEST_SUB(testnum, val1, val2, expected) do { \
    int32_t result; \
    register int32_t rs1 asm("t1") = (val1); \
    register int32_t rs2 asm("t2") = (val2); \
    asm volatile ("sub %0, %1, %2" : "=r"(result) : "r"(rs1), "r"(rs2)); \
    PRINT_RESULT("SUB", testnum, val1, val2, result, expected); \
} while (0)

// ========== OR ==========

#define TEST_OR(testnum, val1, val2, expected) do { \
    int32_t result; \
    register int32_t rs1 asm("t1") = (val1); \
    register int32_t rs2 asm("t2") = (val2); \
    asm volatile ("or %0, %1, %2" : "=r"(result) : "r"(rs1), "r"(rs2)); \
    PRINT_RESULT("OR ", testnum, val1, val2, result, expected); \
} while (0)

// ========== XOR ==========

#define TEST_XOR(testnum, val1, val2, expected) do { \
    int32_t result; \
    register int32_t rs1 asm("t1") = (val1); \
    register int32_t rs2 asm("t2") = (val2); \
    asm volatile ("xor %0, %1, %2" : "=r"(result) : "r"(rs1), "r"(rs2)); \
    PRINT_RESULT("XOR", testnum, val1, val2, result, expected); \
} while (0)

// ========== AND ==========

#define TEST_AND(testnum, val1, val2, expected) do { \
    int32_t result; \
    register int32_t rs1 asm("t1") = (val1); \
    register int32_t rs2 asm("t2") = (val2); \
    asm volatile ("and %0, %1, %2" : "=r"(result) : "r"(rs1), "r"(rs2)); \
    PRINT_RESULT("AND", testnum, val1, val2, result, expected); \
} while (0)

// ========== SLT ==========

#define TEST_SLT(testnum, val1, val2, expected) do { \
    int32_t result; \
    register int32_t rs1 asm("t1") = (val1); \
    register int32_t rs2 asm("t2") = (val2); \
    asm volatile ("slt %0, %1, %2" : "=r"(result) : "r"(rs1), "r"(rs2)); \
    PRINT_RESULT("SLT", testnum, val1, val2, result, expected); \
} while (0)

// ========== SLL ==========

#define TEST_SLL(testnum, val1, val2, expected) do { \
    int32_t result; \
    register int32_t rs1 asm("t1") = (val1); \
    register int32_t rs2 asm("t2") = (val2); \
    asm volatile ("sll %0, %1, %2" : "=r"(result) : "r"(rs1), "r"(rs2)); \
    PRINT_RESULT("SLL", testnum, val1, val2, result, expected); \
} while (0)

// ========== SRL ==========

#define TEST_SRL(testnum, val1, val2, expected) do { \
    int32_t result; \
    register int32_t rs1 asm("t1") = (val1); \
    register int32_t rs2 asm("t2") = (val2); \
    asm volatile ("srl %0, %1, %2" : "=r"(result) : "r"(rs1), "r"(rs2)); \
    PRINT_RESULT("SRL", testnum, val1, val2, result, expected); \
} while (0)

// ========== SRA ==========

#define TEST_SRA(testnum, val1, val2, expected) do { \
    int32_t result; \
    register int32_t rs1 asm("t1") = (val1); \
    register int32_t rs2 asm("t2") = (val2); \
    asm volatile ("sra %0, %1, %2" : "=r"(result) : "r"(rs1), "r"(rs2)); \
    PRINT_RESULT("SRA", testnum, val1, val2, result, expected); \
} while (0)

// ========== BEQ ==========

#define TEST_BEQ(testnum, val1, val2, expected_taken) \
    do { \
        int taken_actual = 0; \
        register int32_t rs1 asm("t1") = (val1); \
        register int32_t rs2 asm("t2") = (val2); \
        asm volatile ( \
            "li t0, 0\n\t" \
            "beq %[v1], %[v2], 1f\n\t" \
            "j 2f\n\t" \
            "1:\n\t" \
            "li t0, 1\n\t" \
            "2:\n\t" \
            "mv %[res], t0\n\t" \
            : [res] "=r" (taken_actual) \
            : [v1] "r" (rs1), [v2] "r" (rs2) \
            : "t0" \
        ); \
        PRINT_BRANCH_RESULT("BEQ", testnum, val1, val2, taken_actual, expected_taken); \
    } while(0)

// ========== BNE ==========

#define TEST_BNE(testnum, val1, val2, expected_taken) do { \
    int32_t taken_actual; \
    register int32_t rs1 asm("t1") = (val1); \
    register int32_t rs2 asm("t2") = (val2); \
    asm volatile ( \
        "li t0, 0\n\t" \
        "bne %[v1], %[v2], 1f\n\t" \
        "j 2f\n\t" \
        "1:\n\t" \
        "li t0, 1\n\t" \
        "2:\n\t" \
        "mv %[res], t0\n\t" \
        : [res] "=r" (taken_actual) \
        : [v1] "r" (rs1), [v2] "r" (rs2) \
        : "t0" \
    ); \
    PRINT_BRANCH_RESULT("BNE", testnum, val1, val2, taken_actual, expected_taken); \
} while (0)

// ========== BLT ==========

#define TEST_BLT(testnum, val1, val2, expected_taken) do { \
    int32_t taken_actual; \
    register int32_t rs1 asm("t1") = (val1); \
    register int32_t rs2 asm("t2") = (val2); \
    asm volatile ( \
        "li t0, 0\n\t" \
        "blt %[v1], %[v2], 1f\n\t" \
        "j 2f\n\t" \
        "1:\n\t" \
        "li t0, 1\n\t" \
        "2:\n\t" \
        "mv %[res], t0\n\t" \
        : [res] "=r" (taken_actual) \
        : [v1] "r" (rs1), [v2] "r" (rs2) \
        : "t0" \
    ); \
    PRINT_BRANCH_RESULT("BLT", testnum, val1, val2, taken_actual, expected_taken); \
} while (0)

// ========== BGE ==========

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

// ========== BGEU ==========

#define TEST_BGEU(testnum, val1, val2, expected_taken) do { \
    int32_t taken_actual; \
    register uint32_t rs1 asm("t1") = (val1); \
    register uint32_t rs2 asm("t2") = (val2); \
    asm volatile ( \
        "li t0, 0\n\t" \
        "bgeu %[v1], %[v2], 1f\n\t" \
        "j 2f\n\t" \
        "1:\n\t" \
        "li t0, 1\n\t" \
        "2:\n\t" \
        "mv %[res], t0\n\t" \
        : [res] "=r" (taken_actual) \
        : [v1] "r" (rs1), [v2] "r"(rs2) \
        : "t0" \
    ); \
    PRINT_BRANCH_RESULT("BGEU", testnum, val1, val2, taken_actual, expected_taken); \
} while (0)

// ========== BLTU ==========

#define TEST_BLTU(testnum, val1, val2, expected_taken) do { \
    int32_t taken_actual; \
    register uint32_t rs1 asm("t1") = (val1); \
    register uint32_t rs2 asm("t2") = (val2); \
    asm volatile ( \
        "li t0, 0\n\t" \
        "bltu %[v1], %[v2], 1f\n\t" \
        "j 2f\n\t" \
        "1:\n\t" \
        "li t0, 1\n\t" \
        "2:\n\t" \
        "mv %[res], t0\n\t" \
        : [res] "=r" (taken_actual) \
        : [v1] "r" (rs1), [v2] "r"(rs2) \
        : "t0" \
    ); \
    PRINT_BRANCH_RESULT("BLTU", testnum, val1, val2, taken_actual, expected_taken); \
} while (0)

// ========== LB ==========

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

// ========== LH ==========

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

// ========== LW ==========

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

// ========== SB ==========

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

// ========== SH ==========

#define TEST_SH(testnum, value, expected, offset, base) do { \
    int32_t result = 0; \
    uint8_t* addr = (uint8_t*)(base) + (offset); \
    asm volatile( \
        "sh %[val], 0(%[addr])\n\t" \
        : \
        : [val] "r"(value), [addr] "r"(addr) \
        : "memory" \
    ); \
    asm volatile( \
        "lh %[res], 0(%[addr])\n\t" \
        : [res] "=r"(result) \
        : [addr] "r"(addr) \
        : "memory" \
    ); \
    PRINT_STORE_RESULT("SH", testnum, offset, value, result, expected); \
} while (0)

// ========== SW ==========

#define TEST_SW(testnum, value, expected, offset, base) do { \
    int32_t result = 0; \
    uint8_t* addr = (uint8_t*)(base) + (offset); \
    asm volatile( \
        "sw %[val], 0(%[addr])\n\t" \
        : \
        : [val] "r"(value), [addr] "r"(addr) \
        : "memory" \
    ); \
    asm volatile( \
        "lw %[res], 0(%[addr])\n\t" \
        : [res] "=r"(result) \
        : [addr] "r"(addr) \
        : "memory" \
    ); \
    PRINT_STORE_RESULT("SW", testnum, offset, value, result, expected); \
} while (0)

// ========== MUL ==========

#define TEST_MUL(testnum, val1, val2, expected) do { \
    int32_t result; \
    register int32_t rs1 asm("t1") = (val1); \
    register int32_t rs2 asm("t2") = (val2); \
    asm volatile ("mul %0, %1, %2" : "=r"(result) : "r"(rs1), "r"(rs2)); \
    PRINT_RESULT("MUL", testnum, val1, val2, result, expected); \
} while (0)

// ========== MULH ==========

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

// ========== DIV ==========

#define TEST_DIV(testnum, val1, val2, expected) do { \
    int32_t result; \
    register int32_t rs1 asm("t1") = (val1); \
    register int32_t rs2 asm("t2") = (val2); \
    asm volatile ("div %0, %1, %2" : "=r"(result) : "r"(rs1), "r"(rs2)); \
    PRINT_RESULT("DIV", testnum, val1, val2, result, expected); \
} while (0)

// ========== REM ==========

#define TEST_REM(testnum, val1, val2, expected) do { \
    int32_t result; \
    register int32_t rs1 asm("t1") = (val1); \
    register int32_t rs2 asm("t2") = (val2); \
    asm volatile ("rem %0, %1, %2" : "=r"(result) : "r"(rs1), "r"(rs2)); \
    PRINT_RESULT("REM", testnum, val1, val2, result, expected); \
} while (0)

// ========== CLEAR REGISTERS ==========

#define CLEAR_TEMP_REGISTERS() do { \
    asm volatile ( \
        "mv t0, zero\n\t" \
        "mv t1, zero\n\t" \
        "mv t2, zero\n\t" \
        "mv t3, zero\n\t" \
        "mv t4, zero\n\t" \
        "mv t5, zero\n\t" \
        "mv t6, zero\n\t" \
    ); \
} while (0)

int main() {

    TEST_AND( 1, 0x0f000f00, 0xff00ff0f, 0x0f000f00 );
    TEST_AND( 2, 0x0f000f00, 0xff00ff00, 0x0f000f00 );
    TEST_AND( 3, 0x00f000f0, 0x0ff00ff0, 0x00f000f0 );
    TEST_AND( 4, 0x000f000f, 0x00ff00ff, 0x000f000f );
    TEST_AND( 5, 0xf000f000, 0xf00ff00f, 0xf000f000 );

    CLEAR_TEMP_REGISTERS();

    TEST_XOR( 1, 0xf00ff00f, 0xff00fff0, 0x0f0f0fff );
    TEST_XOR( 2, 0xf00ff00f, 0xff00ff00, 0x0f0f0f0f );
    TEST_XOR( 3, 0xff00ff00, 0x0ff00ff0, 0xf0f0f0f0 );
    TEST_XOR( 4, 0x0ff00ff0, 0x00ff00ff, 0x0f0f0f0f );
    TEST_XOR( 5, 0x00ff00ff, 0xf00ff00f, 0xf0f0f0f0 );
    TEST_XOR( 6, 0xf00ff00f, 0xff00ff00, 0x0f0f0f0f );
    TEST_XOR( 7, 0xf00ff00f, 0xff00ff00, 0x0f0f0f0f );

    CLEAR_TEMP_REGISTERS();

    TEST_SUB(  1, 0x00000000, 0x00000000, 0x00000000 );
    TEST_SUB(  2, 0x00000000, 0x00000000, 0x00000000 );
    TEST_SUB(  3, 0x00000001, 0x00000001, 0x00000000 );
    TEST_SUB(  4, 0x00000003, 0x00000007, 0xfffffffc );
    TEST_SUB(  5, 0x00000000, 0x00008000, 0x00008000 );
    TEST_SUB(  6, 0x80000000, 0x80000000, 0x00000000 );
    TEST_SUB(  7, 0x80000000, 0x00008000, 0x80008000 );
    TEST_SUB(  8, 0x00000000, 0x00007fff, 0x80000001 );
    TEST_SUB(  9, 0x7fffffff, 0x7fffffff, 0x00000000 );
    TEST_SUB( 10, 0x7fffffff, 0x00007fff, 0x7fff8000 );
    TEST_SUB( 11, 0x80000000, 0x00007fff, 0x7fff8001 );
    TEST_SUB( 12, 0x7fffffff, 0x80008000, 0x80007fff );
    TEST_SUB( 13, 0x00000000, 0xffffffff, 0x00000001 );
    TEST_SUB( 14, 0xffffffff, 0x00000001, 0xfffffffe );
    TEST_SUB( 15, 0xffffffff, 0xffffffff, 0x00000000 );
    TEST_SUB( 16, 13, 2, 11 );
    TEST_SUB( 17, 14, 3, 11 );

    CLEAR_TEMP_REGISTERS();

    TEST_ADD(  1, 0x00000000, 0x00000000, 0x00000000 );
    TEST_ADD(  2, 0x00000000, 0x00000000, 0x00000000 );
    TEST_ADD(  3, 0x00000001, 0x00000001, 0x00000002 );
    TEST_ADD(  4, 0x00000003, 0x00000007, 0x0000000a );
    TEST_ADD(  5, 0x00000000, 0xffff8000, 0xffff8000 );
    TEST_ADD(  6, 0x80000000, 0x00000000, 0x80000000 );
    TEST_ADD(  7, 0x80000000, 0xffff8000, 0x7fff8000 );
    TEST_ADD(  8, 0x00000000, 0x00007fff, 0x00007fff );
    TEST_ADD(  9, 0x7fffffff, 0x00000000, 0x7fffffff );
    TEST_ADD( 10, 0x7fffffff, 0x00007fff, 0x80007ffe );
    TEST_ADD( 11, 0x80000000, 0x00007fff, 0x80007fff );
    TEST_ADD( 12, 0x7fffffff, 0xffff8000, 0x7fff7fff );
    TEST_ADD( 13, 0x00000000, 0xffffffff, 0xffffffff );
    TEST_ADD( 14, 0xffffffff, 0x00000001, 0x00000000 );
    TEST_ADD( 15, 0xffffffff, 0xffffffff, 0xfffffffe );
    TEST_ADD( 16, 0x00000001, 0x7fffffff, 0x80000000 );

    CLEAR_TEMP_REGISTERS();

    TEST_BEQ( 2,  0,  0, 1 );
    TEST_BEQ( 3,  1,  1, 1 );
    TEST_BEQ( 4, -1, -1, 1 );
    TEST_BEQ( 5,  0,  1, 0 );
    TEST_BEQ( 6,  1,  0, 0 );
    TEST_BEQ( 7, -1,  1, 0 );
    TEST_BEQ( 8,  1, -1, 0 );

    CLEAR_TEMP_REGISTERS();

    TEST_SLT(  1,  0x00000000, 0x00000000, 0 );
    TEST_SLT(  2,  0x00000001, 0x00000001, 0 );
    TEST_SLT(  3,  0x00000003, 0x00000007, 1 );
    TEST_SLT(  4,  0x00000007, 0x00000003, 0 );
    TEST_SLT(  5,  0x00000000, 0x00008000, 0 );
    TEST_SLT(  6,  0x80000000, 0x00000000, 1 );
    TEST_SLT(  7,  0x80000000, 0x00008000, 1 );
    TEST_SLT(  8,  0x00000000, 0x00007fff, 1 );
    TEST_SLT(  9,  0x7fffffff, 0x00000000, 0 );
    TEST_SLT( 10,  0x7fffffff, 0x00007fff, 0 );
    TEST_SLT( 11,  0x80000000, 0x00007fff, 1 );
    TEST_SLT( 12,  0x7fffffff, 0x00008000, 0 );
    TEST_SLT( 13,  0x00000000, 0xffffffff, 0 );
    TEST_SLT( 14,  0xffffffff, 0x00000001, 1 );
    TEST_SLT( 15,  0xffffffff, 0xffffffff, 0 );

    CLEAR_TEMP_REGISTERS();

    TEST_OR(  1, 0x00000000, 0x00000000, 0x00000000 );
    TEST_OR(  2, 0xffffffff, 0xffffffff, 0xffffffff );
    TEST_OR(  3, 0xffffffff, 0x00000000, 0xffffffff );
    TEST_OR(  4, 0xffffffff, 0xffffffff, 0xffffffff );
    TEST_OR(  5, 0x00ff00ff, 0x00ff0000, 0x00ff00ff );
    TEST_OR(  6, 0xff00ffff, 0xff0000ff, 0xff00ffff );
    TEST_OR(  7, 0xffffffff,         -1, 0xffffffff );
    TEST_OR(  8, 0x80000000, 0x80000000, 0x80000000 );
    TEST_OR(  9, 0x8000ffff, 0x80000000, 0x8000ffff );
    TEST_OR( 10, 0x7fffffff, 0x7fff0000, 0x7fffffff );
    TEST_OR( 11, 0xffffffff, 0x12345678, 0xffffffff );
    TEST_OR( 12, 0x0fffffff, 0x0f0f0f0f, 0x0fffffff );

    CLEAR_TEMP_REGISTERS();

    TEST_SLL(  1, 0x00000001,  0, 0x00000001 );
    TEST_SLL(  2, 0x00000001,  1, 0x00000002 );
    TEST_SLL(  3, 0x00000001,  7, 0x00000080 );
    TEST_SLL(  4, 0x00000001, 14, 0x00004000 );
    TEST_SLL(  5, 0x00000001, 31, 0x80000000 );
    TEST_SLL(  6, 0xffffffff,  0, 0xffffffff );
    TEST_SLL(  7, 0xffffffff,  1, 0xfffffffe );
    TEST_SLL(  8, 0xffffffff,  7, 0xffffff80 );
    TEST_SLL(  9, 0xffffffff, 14, 0xffffc000 );
    TEST_SLL( 10, 0xffffffff, 31, 0x80000000 );
    TEST_SLL( 11, 0x21212121,  0, 0x21212121 );
    TEST_SLL( 12, 0x21212121,  1, 0x42424242 );
    TEST_SLL( 13, 0x21212121,  7, 0x90909080 );
    TEST_SLL( 14, 0x21212121, 14, 0x48484000 );
    TEST_SLL( 15, 0x21212121, 31, 0x80000000 );

    CLEAR_TEMP_REGISTERS();

    TEST_SRL(  1, 0x00000001,  1, 0x00000000 );
    TEST_SRL(  2, 0x00000002,  1, 0x00000001 );
    TEST_SRL(  3, 0x00000080,  7, 0x00000001 );
    TEST_SRL(  4, 0x00004000, 14, 0x00000001 );
    TEST_SRL(  5, 0x80000000, 31, 0x00000001 );
    TEST_SRL(  6, 0x00010000, 16, 0x00000001 );
    TEST_SRL(  7, 0x00000300,  8, 0x00000003 );
    TEST_SRL(  8, 0x00000300,  6, 0x0000000c );
    TEST_SRL(  9, 0x0000ff00,  8, 0x000000ff );
    TEST_SRL( 10, 0x00000f00,  8, 0x0000000f );
    TEST_SRL( 11, 0x0f000000, 12, 0x0000f000 );
    TEST_SRL( 12, 0x00000000,  5, 0x00000000 );
    TEST_SRL( 13, 0xffff0000, 16, 0x0000ffff );
    TEST_SRL( 14, 0x7e000000,  8, 0x007e0000 );
    TEST_SRL( 15, 0x00008000, 15, 0x00000001 );

    CLEAR_TEMP_REGISTERS();

    TEST_SRA(  1, 0xffffffff,  0, 0xffffffff );
    TEST_SRA(  2, 0xffffffff,  1, 0xffffffff );
    TEST_SRA(  3, 0xffffffff,  7, 0xffffffff );
    TEST_SRA(  4, 0xffffffff, 14, 0xffffffff );
    TEST_SRA(  5, 0xffffffff, 31, 0xffffffff );
    TEST_SRA(  6, 0x7fffffff,  0, 0x7fffffff );
    TEST_SRA(  7, 0x7fffffff,  1, 0x3fffffff );
    TEST_SRA(  8, 0x7fffffff,  8, 0x007fffff );
    TEST_SRA(  9, 0x7fffffff, 15, 0x0000ffff );
    TEST_SRA( 10, 0x7fffffff, 25, 0x0000003f );
    TEST_SRA( 11, 0x7fffffff, 30, 0x00000001 );
    TEST_SRA( 12, 0x80000000,  0, 0x80000000 );
    TEST_SRA( 13, 0x80000000,  1, 0xc0000000 );
    TEST_SRA( 14, 0x80000000, 17, 0xffffc000 );
    TEST_SRA( 15, 0xffffffff,  0, 0xffffffff );

    CLEAR_TEMP_REGISTERS();

    TEST_BNE( 1,  0,  1, 1 );
    TEST_BNE( 2,  1,  0, 1 );
    TEST_BNE( 3, -1,  1, 1 );
    TEST_BNE( 4,  1, -1, 1 );
    TEST_BNE( 5,  0,  0, 0 );
    TEST_BNE( 6,  1,  1, 0 );
    TEST_BNE( 7, -1, -1, 0 );

    CLEAR_TEMP_REGISTERS();

    TEST_BLT( 1,  0,  1, 1 );
    TEST_BLT( 2, -1,  1, 1 );
    TEST_BLT( 3, -2, -1, 1 );
    TEST_BLT( 4,  1,  0, 0 );
    TEST_BLT( 5,  1, -1, 0 );
    TEST_BLT( 6, -1, -2, 0 );
    TEST_BLT( 7,  1, -2, 0 );

    CLEAR_TEMP_REGISTERS();

    TEST_BGE(  1,  0,  0, 1 );
    TEST_BGE(  2,  1,  1, 1 );
    TEST_BGE(  3, -1, -1, 1 );
    TEST_BGE(  4,  1,  0, 1 );
    TEST_BGE(  5,  1, -1, 1 );
    TEST_BGE(  6, -1, -2, 1 );
    TEST_BGE(  7,  0,  1, 0 );
    TEST_BGE(  8, -1,  1, 0 );
    TEST_BGE(  9, -2, -1, 0 );
    TEST_BGE( 10, -2,  1, 0 );

    
    CLEAR_TEMP_REGISTERS();


    TEST_BGEU(  1, 0x00000000, 0x00000000, 1 );
    TEST_BGEU(  2, 0x00000001, 0x00000001, 1 );
    TEST_BGEU(  3, 0xffffffff, 0xffffffff, 1 );
    TEST_BGEU(  4, 0x00000001, 0x00000000, 1 );
    TEST_BGEU(  5, 0xffffffff, 0xfffffffe, 1 );
    TEST_BGEU(  6, 0xffffffff, 0x00000000, 1 );
    TEST_BGEU(  7, 0x00000000, 0x00000001, 0 );
    TEST_BGEU(  8, 0xfffffffe, 0xffffffff, 0 );
    TEST_BGEU(  9, 0x00000000, 0xffffffff, 0 );
    TEST_BGEU( 10, 0x7fffffff, 0x80000000, 0 );

    CLEAR_TEMP_REGISTERS();

    TEST_BLTU( 1, 0x00000000, 0x00000001, 1 );
    TEST_BLTU( 2, 0xfffffffe, 0xffffffff, 1 );
    TEST_BLTU( 3, 0x00000000, 0xffffffff, 1 );
    TEST_BLTU( 4, 0x00000001, 0x00000000, 0 );
    TEST_BLTU( 5, 0xffffffff, 0xfffffffe, 0 );
    TEST_BLTU( 6, 0xffffffff, 0x00000000, 0 );
    TEST_BLTU( 7, 0x80000000, 0x7fffffff, 0 );

    CLEAR_TEMP_REGISTERS();

    volatile int32_t data0 = 0x00ff00ff;
    volatile int32_t data1 = 0xff00ff00;
    volatile int32_t data2 = 0x0ff00ff0;
    volatile int32_t data3 = 0xf00ff00f;

    TEST_LB( 1, 0xffffffff,  0, &data0 );
    TEST_LB( 2, 0x00000000,  1, &data0 );
    TEST_LB( 3, 0xffffffff,  2, &data0 );
    TEST_LB( 4, 0x00000000,  3, &data0 );
    TEST_LB( 5, 0x0000000f, -3, &data3 );
    TEST_LB( 6, 0xfffffff0, -2, &data3 );
    TEST_LB( 7, 0x0000000f, -1, &data3 );
    TEST_LB( 8, 0x0000000f,  0, &data3 );

    CLEAR_TEMP_REGISTERS();

    TEST_LH( 1, 0x000000ff,  0, &data0 );
    TEST_LH( 2, 0x000000ff,  2, &data0 );
    TEST_LH( 3, 0x00000ff0,  4, &data1 );
    TEST_LH( 4, 0x00000ff0,  6, &data1 );
    TEST_LH( 5, 0xffffff00, -6, &data3 );
    TEST_LH( 6, 0x00000ff0, -4, &data3 );
    TEST_LH( 7, 0x00000ff0, -2, &data3 );
    TEST_LH( 8, 0xfffff00f,  0, &data3 );

    CLEAR_TEMP_REGISTERS();

    TEST_LW( 1, 0x00ff00ff,   0, &data0 );
    TEST_LW( 2, 0xff00ff00,   4, &data0 );
    TEST_LW( 3, 0x0ff00ff0,   8, &data0 );
    TEST_LW( 4, 0xf00ff00f,  12, &data0 );
    TEST_LW( 5, 0x00ff00ff, -12, &data3 );
    TEST_LW( 6, 0xff00ff00,  -8, &data3 );
    TEST_LW( 7, 0x0ff00ff0,  -4, &data3 );
    TEST_LW( 8, 0xf00ff00f,   0, &data3 );

    CLEAR_TEMP_REGISTERS();

    volatile int32_t buffer[4] = {0};
    
    TEST_SB( 1, 0x000000ff, 0xffffffff, 0, buffer );
    TEST_SB( 2, 0x0000007f, 0x0000007f, 1, buffer );
    TEST_SB( 3, 0x00000080, 0xffffff80, 2, buffer );
    TEST_SB( 4, 0x0000000f, 0x0000000f, 3, buffer );
    
    CLEAR_TEMP_REGISTERS();

    TEST_SH( 1, 0x0000ffff, 0xffffffff, 0, buffer );
    TEST_SH( 2, 0x00007fff, 0x00007fff, 2, buffer );
    TEST_SH( 3, 0x00008000, 0xffff8000, 0, buffer );
    TEST_SH( 4, 0x00000f0f, 0x00000f0f, 2, buffer );
    
    CLEAR_TEMP_REGISTERS();

    TEST_SW( 1, 0x12345678, 0x12345678,  0, buffer );
    TEST_SW( 2, 0xffffffff, 0xffffffff,  4, buffer );
    TEST_SW( 3, 0x0ff00ff0, 0x0ff00ff0,  8, buffer );
    TEST_SW( 4, 0x80000000, 0x80000000, 12, buffer );

    CLEAR_TEMP_REGISTERS();

    TEST_MUL(  1,           2,           3,          6 );
    TEST_MUL(  2,         123,           0,          0 );
    TEST_MUL(  3,           0,        -456,          0 );
    TEST_MUL(  4,          -2,           3,         -6 );
    TEST_MUL(  5,           7,          -2,        -14 );
    TEST_MUL(  6,  0x7fffffff,  0xfffffffe, 0x00000002 );
    TEST_MUL(  7, -0x40000000,  0x00000000, 0x00000000 );
    TEST_MUL(  8,          -1, -0x7fffffff, 0x7fffffff );
    TEST_MUL(  9,  0x80000000,  0x00000000, 0x00000000 );
    TEST_MUL( 10,  0x7fffffff,  0x00000001, 0x7fffffff );

    CLEAR_TEMP_REGISTERS();

    TEST_MULH(  1,          0,           2,          3 );
    TEST_MULH(  2,          0,         123,          0 );
    TEST_MULH(  3,          0,           0,       -456 );
    TEST_MULH(  4,          0,          -2,         -3 );
    TEST_MULH(  5, 0xffffffff,           7,         -2 );
    TEST_MULH(  6, 0x00000000,  0x7fffffff,          2 );
    TEST_MULH(  7, 0x00000001, -0x40000000,         -4 );
    TEST_MULH(  8, 0xffffffff,          -1, 0x7fffffff );
    TEST_MULH(  9, 0xffffffff,  0x80000000,          2 );
    TEST_MULH( 10, 0x3fffffff,  0x7fffffff, 0x7fffffff );

    CLEAR_TEMP_REGISTERS();

    TEST_DIV(  1,          6,           2,  3 );
    TEST_DIV(  2,         -6,          -2,  3 );
    TEST_DIV(  3,          6,          -2, -3 );
    TEST_DIV(  4,         -6,           2, -3 );
    TEST_DIV(  5,         10,           5,  2 );
    TEST_DIV(  6,      12345,       12345,  1 );
    TEST_DIV(  7,     -12345,       12345, -1 );
    TEST_DIV(  8,    -214748,     -214748,  1 );
    TEST_DIV(  9,         -1,         123,  0 );
    TEST_DIV( 10,         -1,        -123,  0 );
    TEST_DIV( 11,          0,          -1,  0 );
    TEST_DIV( 12, 0x7fffffff,  0x3fffffff,  2 );
    TEST_DIV( 13, 0x80000000, -0x40000000,  2 );

    CLEAR_TEMP_REGISTERS();

    TEST_REM(  1,           6,    3,  0 );
    TEST_REM(  2,          -6,    3,  0 );
    TEST_REM(  3,           6,   -3,  0 );
    TEST_REM(  4,          -6,   -3,  0 );
    TEST_REM(  5,           7,    1,  0 );
    TEST_REM(  6,          -7,    1,  0 );
    TEST_REM(  7,           7,   -3,  1 );
    TEST_REM(  8,          -7,   -3, -1 );
    TEST_REM(  9,       12345,    1,  0 );
    TEST_REM( 10,       12345,   -1,  0 );
    TEST_REM( 11, -2147483648,   -1,  0 );
    TEST_REM( 12,         123,  123,  0 );
    TEST_REM( 13,        -123, -123,  0 );
    TEST_REM( 14,           0,    0,  0 );
    TEST_REM( 15,  0x7fffffff,    2,  1 );
    TEST_REM( 16,  0x80000000,    2,  0 );

    return 0;
}