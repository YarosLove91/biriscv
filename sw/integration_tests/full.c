#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

// ========== ADD ==========

void test_add(int testnum, uint32_t val1, uint32_t val2, uint32_t expected) {
    uint32_t result;
    register uint32_t rs1 asm("t1") = val1;
    register uint32_t rs2 asm("t2") = val2;

    asm volatile (
        "add %0, %1, %2"
        : "=r"(result)
        : "r"(rs1), "r"(rs2)
    );

    printf("Test %2d: 0x%08" PRIx32 " + 0x%08" PRIx32 " = 0x%08" PRIx32
           " (expected: 0x%08" PRIx32 ") %s\n",
           testnum, val1, val2, result, expected,
           (result == expected) ? "PASSED" : "FAILED");
}

// ========== SUB ==========

void test_sub(int testnum, uint32_t val1, uint32_t val2, uint32_t expected) {
    uint32_t result;
    register uint32_t rs1 asm("t1") = val1;
    register uint32_t rs2 asm("t2") = val2;

    asm volatile (
        "sub %0, %1, %2"
        : "=r"(result)
        : "r"(rs1), "r"(rs2)
    );

    printf("Test %2d: 0x%08x - 0x%08x = 0x%08x (expected: 0x%08x) %s\n",
           testnum, val1, val2, result, expected,
           (result == expected) ? "PASSED" : "FAILED");
}

void test_sub_src1_eq_dest(int testnum, uint32_t val1, uint32_t val2, uint32_t expected) {
    register uint32_t rs1 asm("t1") = val1;
    register uint32_t rs2 asm("t2") = val2;

    asm volatile (
        "sub %[v1], %[v1], %[v2]"
        : [v1] "+r"(rs1)
        : [v2] "r"(rs2)
    );

    printf("Test %2d: src1 == dest: result = 0x%08x (expected: 0x%08x) %s\n",
           testnum, rs1, expected,
           (rs1 == expected) ? "PASSED" : "FAILED");
}

void test_sub_src2_eq_dest(int testnum, uint32_t val1, uint32_t val2, uint32_t expected) {
    register uint32_t rs1 asm("t1") = val1;
    register uint32_t rs2 asm("t2") = val2;

    asm volatile (
        "sub %[v2], %[v1], %[v2]"
        : [v2] "+r"(rs2)
        : [v1] "r"(rs1)
    );

    printf("Test %2d: src2 == dest: result = 0x%08x (expected: 0x%08x) %s\n",
           testnum, rs2, expected,
           (rs2 == expected) ? "PASSED" : "FAILED");
}

void test_sub_src12_eq_dest(int testnum, uint32_t val, uint32_t expected) {
    register uint32_t r asm("t1") = val;

    asm volatile (
        "sub %[r], %[r], %[r]"
        : [r] "+r"(r)
    );

    printf("Test %2d: src1 == src2 == dest: result = 0x%08x (expected: 0x%08x) %s\n",
           testnum, r, expected,
           (r == expected) ? "PASSED" : "FAILED");
}

// ========== XOR ==========

void test_xor(int testnum, uint32_t val1, uint32_t val2, uint32_t expected) {
    uint32_t result;
    register uint32_t rs1 asm("t1") = val1;
    register uint32_t rs2 asm("t2") = val2;

    asm volatile (
        "xor %0, %1, %2"
        : "=r"(result)
        : "r"(rs1), "r"(rs2)
    );

    printf("Test %2d: 0x%08x ^ 0x%08x = 0x%08x (expected: 0x%08x) %s\n",
           testnum, val1, val2, result, expected,
           (result == expected) ? "PASSED" : "FAILED");
}

void test_xor_src1_eq_dest(int testnum, uint32_t val1, uint32_t val2, uint32_t expected) {
    register uint32_t rs1 asm("t1") = val1;
    register uint32_t rs2 asm("t2") = val2;

    asm volatile (
        "xor %[v1], %[v1], %[v2]"
        : [v1] "+r"(rs1)
        : [v2] "r"(rs2)
    );

    printf("Test %2d: src1 == dest: result = 0x%08x (expected: 0x%08x) %s\n",
           testnum, rs1, expected,
           (rs1 == expected) ? "PASSED" : "FAILED");
}

void test_xor_src2_eq_dest(int testnum, uint32_t val1, uint32_t val2, uint32_t expected) {
    register uint32_t rs1 asm("t1") = val1;
    register uint32_t rs2 asm("t2") = val2;

    asm volatile (
        "xor %[v2], %[v1], %[v2]"
        : [v2] "+r"(rs2)
        : [v1] "r"(rs1)
    );

    printf("Test %2d: src2 == dest: result = 0x%08x (expected: 0x%08x) %s\n",
           testnum, rs2, expected,
           (rs2 == expected) ? "PASSED" : "FAILED");
}

void test_xor_src12_eq_dest(int testnum, uint32_t val, uint32_t expected) {
    register uint32_t r asm("t1") = val;

    asm volatile (
        "xor %[r], %[r], %[r]"
        : [r] "+r"(r)
    );

    printf("Test %2d: src1 == src2 == dest: result = 0x%08x (expected: 0x%08x) %s\n",
           testnum, r, expected,
           (r == expected) ? "PASSED" : "FAILED");
}

// ========== AND ==========

void test_and(int testnum, uint32_t val1, uint32_t val2, uint32_t expected) {
    uint32_t result;
    register uint32_t rs1 asm("t1") = val1;
    register uint32_t rs2 asm("t2") = val2;

    asm volatile (
        "and %0, %1, %2"
        : "=r"(result)
        : "r"(rs1), "r"(rs2)
    );

    printf("Test %2d: 0x%08" PRIx32 " & 0x%08" PRIx32 " = 0x%08" PRIx32
           " (expected: 0x%08" PRIx32 ") %s\n",
           testnum, val1, val2, result, expected,
           (result == expected) ? "PASSED" : "FAILED");
}

// ========== BEQ ==========

void test_beq(int testnum, int32_t val1, int32_t val2, int taken_expected) {
    int taken_actual = 0;
    register int32_t rs1 asm("t1") = val1;
    register int32_t rs2 asm("t2") = val2;

    asm volatile (
        "li t0, 0\n\t"
        "beq %[v1], %[v2], 1f\n\t"
        "j 2f\n\t"
        "1:\n\t"
        "li t0, 1\n\t"
        "2:\n\t"
        "mv %[res], t0\n\t"
        : [res] "=r" (taken_actual)
        : [v1] "r" (rs1), [v2] "r" (rs2)
        : "t0"
    );

    printf("Test %2d: beq %11d == %11d → %s (expected: %s) %s\n",
           testnum, val1, val2,
           taken_actual ? "taken" : "not taken",
           taken_expected ? "taken" : "not taken",
           (taken_actual == taken_expected) ? "PASSED" : "FAILED");
}

// ========== SLT ==========

void test_slt(int testnum, int32_t val1, int32_t val2, int32_t expected) {
    int32_t result;

    asm volatile (
        "slt %[res], %[v1], %[v2]"
        : [res] "=r"(result)
        : [v1] "r"(val1), [v2] "r"(val2)
    );

    printf("Test %2d: slt(0x%08x, 0x%08x) = %d (expected: %d) %s\n",
           testnum, val1, val2, result, expected,
           (result == expected) ? "PASSED" : "FAILED");
}


// ========== OR ==========

void test_or(int test_num, int32_t expected, int32_t rs1, int32_t rs2)
{
    int32_t result = 0;
    asm volatile(
        "or %[res], %[src1], %[src2]\n\t"
        : [res] "=r"(result)
        : [src1] "r"(rs1), [src2] "r"(rs2)
        : "memory"
    );

    if (result == expected)
        printf("Test %2d: or(0x%08x, 0x%08x) -> 0x%08x PASSED\n", test_num, rs1, rs2, result);
    else
        printf("Test %2d: or(0x%08x, 0x%08x) -> 0x%08x FAILED (expected 0x%08x)\n",
               test_num, rs1, rs2, result, expected);
}

// ========== SLL ==========

void test_sll(int testnum, uint32_t expected, uint32_t val, uint32_t shamt) {
    register uint32_t rs1 asm("t1") = val;
    register uint32_t rs2 asm("t2") = shamt;
    register uint32_t rd asm("t0");

    asm volatile (
        "sll %[d], %[s1], %[s2]"
        : [d] "=r"(rd)
        : [s1] "r"(rs1), [s2] "r"(rs2)
    );

    printf("Test %2d: sll(0x%08x, %2d) = 0x%08x (expected: 0x%08x) %s\n",
           testnum, val, shamt, rd, expected,
           (rd == expected) ? "PASSED" : "FAILED");
}

// ========== SRL ==========

void test_srl(int testnum, uint32_t expected, uint32_t val, uint32_t shamt) {
    register uint32_t rs1 asm("t1") = val;
    register uint32_t rs2 asm("t2") = shamt;
    register uint32_t rd asm("t0");

    asm volatile (
        "srl %[d], %[s1], %[s2]"
        : [d] "=r"(rd)
        : [s1] "r"(rs1), [s2] "r"(rs2)
    );

    printf("Test %2d: srl(0x%08x, %2d) = 0x%08x (expected: 0x%08x) %s\n",
           testnum, val, shamt, rd, expected,
           (rd == expected) ? "PASSED" : "FAILED");
}

// ========== SRA ==========

void test_sra(int testnum, uint32_t expected, uint32_t val, uint32_t shamt) {
    register uint32_t rs1 asm("t1") = val;
    register uint32_t rs2 asm("t2") = shamt;
    register uint32_t rd asm("t0");

    asm volatile (
        "sra %[d], %[s1], %[s2]"
        : [d] "=r"(rd)
        : [s1] "r"(rs1), [s2] "r"(rs2)
    );

    printf("Test %2d: sra(0x%08x, %2d) = 0x%08x (expected: 0x%08x) %s\n",
           testnum, val, shamt, rd, expected,
           (rd == expected) ? "PASSED" : "FAILED");
}

// ========== BNE ==========

void test_bne(int test_num, int32_t rs1, int32_t rs2, int expected_taken)
{
    int taken = 0;
    asm volatile(
        "mv t0, %[rs1]\n\t"
        "mv t1, %[rs2]\n\t"
        "li t2, 0\n\t"
        "bne t0, t1, 1f\n\t"
        "j 2f\n\t"
        "1:\n\t"
        "li t2, 1\n\t"
        "2:\n\t"
        "mv %[taken], t2\n\t"
        : [taken] "=r"(taken)
        : [rs1] "r"(rs1), [rs2] "r"(rs2)
        : "t0", "t1", "t2"
    );

    if (taken == expected_taken)
    {
        printf("Test %2d: bne(rs1=%d, rs2=%d) -> %s (expected: %s) PASSED\n",
               test_num, rs1, rs2, taken ? "taken" : "not taken", expected_taken ? "taken" : "not taken");
    }
    else
    {
        printf("Test %2d: bne(rs1=%d, rs2=%d) -> %s (expected: %s) FAILED\n",
               test_num, rs1, rs2, taken ? "taken" : "not taken", expected_taken ? "taken" : "not taken");
    }
}

// ========== BLT ==========

void test_blt(int test_num, int32_t rs1, int32_t rs2, int expected_taken)
{
    int taken = 0;
    asm volatile(
        "mv t0, %[rs1]\n\t"
        "mv t1, %[rs2]\n\t"
        "li t2, 0\n\t"
        "blt t0, t1, 1f\n\t"
        "j 2f\n\t"
        "1:\n\t"
        "li t2, 1\n\t"
        "2:\n\t"
        "mv %[taken], t2\n\t"
        : [taken] "=r"(taken)
        : [rs1] "r"(rs1), [rs2] "r"(rs2)
        : "t0", "t1", "t2"
    );

    if (taken == expected_taken)
    {
        printf("Test %2d: blt(rs1=%d, rs2=%d) -> %s (expected: %s) PASSED\n",
               test_num, rs1, rs2, taken ? "taken" : "not taken", expected_taken ? "taken" : "not taken");
    }
    else
    {
        printf("Test %2d: blt(rs1=%d, rs2=%d) -> %s (expected: %s) FAILED\n",
               test_num, rs1, rs2, taken ? "taken" : "not taken", expected_taken ? "taken" : "not taken");
    }
}

// ========== BGE ==========

void test_bge(int test_num, int32_t rs1, int32_t rs2, int expected_taken)
{
    int taken = 0;
    asm volatile(
        "mv t0, %[rs1]\n\t"
        "mv t1, %[rs2]\n\t"
        "li t2, 0\n\t"
        "bge t0, t1, 1f\n\t"
        "j 2f\n\t"
        "1:\n\t"
        "li t2, 1\n\t"
        "2:\n\t"
        "mv %[taken], t2\n\t"
        : [taken] "=r"(taken)
        : [rs1] "r"(rs1), [rs2] "r"(rs2)
        : "t0", "t1", "t2"
    );

    if (taken == expected_taken)
        printf("Test %2d: bge(rs1=%d, rs2=%d) -> %s PASSED\n",
               test_num, rs1, rs2, taken ? "taken" : "not taken");
    else
        printf("Test %2d: bge(rs1=%d, rs2=%d) -> %s FAILED (expected %s)\n",
               test_num, rs1, rs2, taken ? "taken" : "not taken", expected_taken ? "taken" : "not taken");
}

// ========== BGEU ==========

void test_bgeu(int test_num, uint32_t rs1, uint32_t rs2, int expected_taken)
{
    int taken = 0;
    asm volatile(
        "mv t0, %[rs1]\n\t"
        "mv t1, %[rs2]\n\t"
        "li t2, 0\n\t"
        "bgeu t0, t1, 1f\n\t"
        "j 2f\n\t"
        "1:\n\t"
        "li t2, 1\n\t"
        "2:\n\t"
        "mv %[taken], t2\n\t"
        : [taken] "=r"(taken)
        : [rs1] "r"(rs1), [rs2] "r"(rs2)
        : "t0", "t1", "t2"
    );

    if (taken == expected_taken)
        printf("Test %2d: bgeu(rs1=0x%08x, rs2=0x%08x) -> %s PASSED\n",
               test_num, rs1, rs2, taken ? "taken" : "not taken");
    else
        printf("Test %2d: bgeu(rs1=0x%08x, rs2=0x%08x) -> %s FAILED (expected %s)\n",
               test_num, rs1, rs2, taken ? "taken" : "not taken", expected_taken ? "taken" : "not taken");
}

// ========== BLTU ==========

void test_bltu(int test_num, uint32_t rs1, uint32_t rs2, int expected_taken)
{
    int taken = 0;
    asm volatile(
        "mv t0, %[rs1]\n\t"
        "mv t1, %[rs2]\n\t"
        "li t2, 0\n\t"
        "bltu t0, t1, 1f\n\t"
        "j 2f\n\t"
        "1:\n\t"
        "li t2, 1\n\t"
        "2:\n\t"
        "mv %[taken], t2\n\t"
        : [taken] "=r"(taken)
        : [rs1] "r"(rs1), [rs2] "r"(rs2)
        : "t0", "t1", "t2"
    );

    if (taken == expected_taken)
        printf("Test %2d: bltu(rs1=0x%08x, rs2=0x%08x) -> %s PASSED\n",
               test_num, rs1, rs2, taken ? "taken" : "not taken");
    else
        printf("Test %2d: bltu(rs1=0x%08x, rs2=0x%08x) -> %s FAILED (expected %s)\n",
               test_num, rs1, rs2, taken ? "taken" : "not taken", expected_taken ? "taken" : "not taken");
}

// ========== LB ==========

void test_lb(int test_num, int32_t expected, int offset, int32_t* base)
{
    int32_t result = 0;
    int8_t* addr = (int8_t*)base + offset;
    asm volatile(
        "lb %[res], 0(%[addr])\n\t"
        : [res] "=r"(result)
        : [addr] "r"(addr)
        : "memory"
    );

    if (result == expected)
        printf("Test %2d: lb(offset=%d) -> 0x%08x PASSED\n", test_num, offset, result);
    else
        printf("Test %2d: lb(offset=%d) -> 0x%08x FAILED (expected 0x%08x)\n",
               test_num, offset, result, expected);
}

// ========== LH ==========

void test_lh(int test_num, int32_t expected, int offset, int32_t* base)
{
    int32_t result = 0;
    int16_t* addr = (int16_t*)((uint8_t*)base + offset);
    asm volatile(
        "lh %[res], 0(%[addr])\n\t"
        : [res] "=r"(result)
        : [addr] "r"(addr)
        : "memory"
    );

    if (result == expected)
        printf("Test %2d: lh(offset=%d) -> 0x%08x PASSED\n", test_num, offset, result);
    else
        printf("Test %2d: lh(offset=%d) -> 0x%08x FAILED (expected 0x%08x)\n",
               test_num, offset, result, expected);
}

// ========== LW ==========

void test_lw(int test_num, int32_t expected, int offset, int32_t* base)
{
    int32_t result = 0;
    int32_t* addr = (int32_t*)((uint8_t*)base + offset);
    asm volatile(
        "lw %[res], 0(%[addr])\n\t"
        : [res] "=r"(result)
        : [addr] "r"(addr)
        : "memory"
    );

    if (result == expected)
        printf("Test %2d: lw(offset=%d) -> 0x%08x PASSED\n", test_num, offset, result);
    else
        printf("Test %2d: lw(offset=%d) -> 0x%08x FAILED (expected 0x%08x)\n",
               test_num, offset, result, expected);
}

// ========== SB ==========

void test_sb(int test_num, int32_t value, int32_t expected, int offset, int32_t* base)
{
    int32_t result = 0;
    uint8_t* addr = (uint8_t*)base + offset;

    asm volatile(
        "sb %[val], 0(%[addr])\n\t"
        :
        : [val] "r"(value), [addr] "r"(addr)
        : "memory"
    );

    asm volatile(
        "lb %[res], 0(%[addr])\n\t"
        : [res] "=r"(result)
        : [addr] "r"(addr)
        : "memory"
    );

    if (result == expected)
        printf("Test %2d: sb(offset=%d, value=0x%08x) -> 0x%08x PASSED\n", test_num, offset, value, result);
    else
        printf("Test %2d: sb(offset=%d, value=0x%08x) -> 0x%08x FAILED (expected 0x%08x)\n",
               test_num, offset, value, result, expected);
}

// ========== SH ==========

void test_sh(int test_num, int32_t value, int32_t expected, int offset, int32_t* base)
{
    int32_t result = 0;
    uint8_t* addr = (uint8_t*)base + offset;

    asm volatile(
        "sh %[val], 0(%[addr])\n\t"
        :
        : [val] "r"(value), [addr] "r"(addr)
        : "memory"
    );

    asm volatile(
        "lh %[res], 0(%[addr])\n\t"
        : [res] "=r"(result)
        : [addr] "r"(addr)
        : "memory"
    );

    if (result == expected)
        printf("Test %2d: sh(offset=%d, value=0x%08x) -> 0x%08x PASSED\n", test_num, offset, value, result);
    else
        printf("Test %2d: sh(offset=%d, value=0x%08x) -> 0x%08x FAILED (expected 0x%08x)\n",
               test_num, offset, value, result, expected);
}

// ========== SW ==========

void test_sw(int test_num, int32_t value, int32_t expected, int offset, int32_t* base)
{
    int32_t result = 0;
    uint8_t* addr = (uint8_t*)base + offset;

    asm volatile(
        "sw %[val], 0(%[addr])\n\t"
        :
        : [val] "r"(value), [addr] "r"(addr)
        : "memory"
    );

    asm volatile(
        "lw %[res], 0(%[addr])\n\t"
        : [res] "=r"(result)
        : [addr] "r"(addr)
        : "memory"
    );

    if (result == expected)
        printf("Test %2d: sw(offset=%d, value=0x%08x) -> 0x%08x PASSED\n", test_num, offset, value, result);
    else
        printf("Test %2d: sw(offset=%d, value=0x%08x) -> 0x%08x FAILED (expected 0x%08x)\n",
               test_num, offset, value, result, expected);
}

// ========== MUL ==========

void test_mul(int test_num, int32_t expected, int32_t rs1, int32_t rs2)
{
    int32_t result = 0;

    asm volatile(
        "mul %[res], %[src1], %[src2]\n\t"
        : [res] "=r"(result)
        : [src1] "r"(rs1), [src2] "r"(rs2)
        : "memory"
    );

    if (result == expected)
        printf("Test %2d: mul(%d, %d) -> 0x%08x PASSED\n", test_num, rs1, rs2, result);
    else
        printf("Test %2d: mul(%d, %d) -> 0x%08x FAILED (expected 0x%08x)\n",
               test_num, rs1, rs2, result, expected);
}

// ========== MULH ==========

void test_mulh(int test_num, int32_t expected, int32_t rs1, int32_t rs2)
{
    int32_t result = 0;

    asm volatile(
        "mulh %[res], %[src1], %[src2]\n\t"
        : [res] "=r"(result)
        : [src1] "r"(rs1), [src2] "r"(rs2)
        : "memory"
    );

    if (result == expected)
        printf("Test %2d: mulh(%d, %d) -> 0x%08x PASSED\n", test_num, rs1, rs2, result);
    else
        printf("Test %2d: mulh(%d, %d) -> 0x%08x FAILED (expected 0x%08x)\n",
               test_num, rs1, rs2, result, expected);
}

// ========== DIV ==========

void test_div(int test_num, int32_t expected, int32_t rs1, int32_t rs2)
{
    int32_t result = 0;
    asm volatile(
        "div %[res], %[src1], %[src2]\n\t"
        : [res] "=r"(result)
        : [src1] "r"(rs1), [src2] "r"(rs2)
        : "memory"
    );

    if (result == expected)
        printf("Test %2d: div(%d, %d) -> 0x%08x PASSED\n", test_num, rs1, rs2, result);
    else
        printf("Test %2d: div(%d, %d) -> 0x%08x FAILED (expected 0x%08x)\n",
               test_num, rs1, rs2, result, expected);
}

// ========== REM ==========

void test_rem(int test_num, int32_t expected, int32_t rs1, int32_t rs2)
{
    int32_t result = 0;
    asm volatile(
        "rem %[res], %[src1], %[src2]\n\t"
        : [res] "=r"(result)
        : [src1] "r"(rs1), [src2] "r"(rs2)
        : "memory"
    );

    if (result == expected)
        printf("Test %2d: rem(%d, %d) -> 0x%08x PASSED\n", test_num, rs1, rs2, result);
    else
        printf("Test %2d: rem(%d, %d) -> 0x%08x FAILED (expected 0x%08x)\n",
               test_num, rs1, rs2, result, expected);
}

static inline void clear_temp_registers() {
    asm volatile (
        "mv t0, zero\n\t"
        "mv t1, zero\n\t"
        "mv t2, zero\n\t"
        "mv t3, zero\n\t"
        "mv t4, zero\n\t"
        "mv t5, zero\n\t"
        "mv t6, zero"
    );
}

int main() {

    printf("== Testing AND ==\n");

    test_and( 1, 0x0f000f00, 0xff00ff0f, 0x0f000f00 );
    test_and( 2, 0x0f000f00, 0xff00ff00, 0x0f000f00 );
    test_and( 3, 0x00f000f0, 0x0ff00ff0, 0x00f000f0 );
    test_and( 4, 0x000f000f, 0x00ff00ff, 0x000f000f );
    test_and( 5, 0xf000f000, 0xf00ff00f, 0xf000f000 );

    clear_temp_registers();

    printf("== Testing XOR ==\n");

    test_xor( 1, 0xf00ff00f, 0xff00fff0, 0x0f0f0fff );
    test_xor( 2, 0xf00ff00f, 0xff00ff00, 0x0f0f0f0f );
    test_xor( 3, 0xff00ff00, 0x0ff00ff0, 0xf0f0f0f0 );
    test_xor( 4, 0x0ff00ff0, 0x00ff00ff, 0x0f0f0f0f );
    test_xor( 5, 0x00ff00ff, 0xf00ff00f, 0xf0f0f0f0 );
    test_xor_src1_eq_dest( 6, 0xf00ff00f, 0xff00ff00, 0x0f0f0f0f );
    test_xor_src2_eq_dest( 7, 0xf00ff00f, 0xff00ff00, 0x0f0f0f0f );
    test_xor_src12_eq_dest( 8, 0xff00ff00, 0x00000000 );

    clear_temp_registers();

    printf("== Testing SUB ==\n");

    test_sub(  1, 0x00000000, 0x00000000, 0x00000000 );
    test_sub(  2, 0x00000000, 0x00000000, 0x00000000 );
    test_sub(  3, 0x00000001, 0x00000001, 0x00000000 );
    test_sub(  4, 0x00000003, 0x00000007, 0xfffffffc );
    test_sub(  5, 0x00000000, 0x00008000, 0x00008000 );
    test_sub(  6, 0x80000000, 0x80000000, 0x00000000 );
    test_sub(  7, 0x80000000, 0x00008000, 0x80008000 );
    test_sub(  8, 0x00000000, 0x00007fff, 0x80000001 );
    test_sub(  9, 0x7fffffff, 0x7fffffff, 0x00000000 );
    test_sub( 10, 0x7fffffff, 0x00007fff, 0x7fff8000 );
    test_sub( 11, 0x80000000, 0x00007fff, 0x7fff8001 );
    test_sub( 12, 0x7fffffff, 0x80008000, 0x80007fff );
    test_sub( 13, 0x00000000, 0xffffffff, 0x00000001 );
    test_sub( 14, 0xffffffff, 0x00000001, 0xfffffffe );
    test_sub( 15, 0xffffffff, 0xffffffff, 0x00000000 );
    test_sub_src1_eq_dest( 16, 13, 2, 11 );
    test_sub_src2_eq_dest(17, 14, 3, 11);
    test_sub_src12_eq_dest(18, 13, 0);

    clear_temp_registers();

    printf("== Testing ADD ==\n");

    test_add(  1, 0x00000000, 0x00000000, 0x00000000 );
    test_add(  2, 0x00000000, 0x00000000, 0x00000000 );
    test_add(  3, 0x00000001, 0x00000001, 0x00000002 );
    test_add(  4, 0x00000003, 0x00000007, 0x0000000a );
    test_add(  5, 0x00000000, 0xffff8000, 0xffff8000 );
    test_add(  6, 0x80000000, 0x00000000, 0x80000000 );
    test_add(  7, 0x80000000, 0xffff8000, 0x7fff8000 );
    test_add(  8, 0x00000000, 0x00007fff, 0x00007fff );
    test_add(  9, 0x7fffffff, 0x00000000, 0x7fffffff );
    test_add( 10, 0x7fffffff, 0x00007fff, 0x80007ffe );
    test_add( 11, 0x80000000, 0x00007fff, 0x80007fff );
    test_add( 12, 0x7fffffff, 0xffff8000, 0x7fff7fff );
    test_add( 13, 0x00000000, 0xffffffff, 0xffffffff );
    test_add( 14, 0xffffffff, 0x00000001, 0x00000000 );
    test_add( 15, 0xffffffff, 0xffffffff, 0xfffffffe );
    test_add( 16, 0x00000001, 0x7fffffff, 0x80000000 );

    clear_temp_registers();

    printf("== Testing BEQ ==\n");

    test_beq( 2,  0,  0, 1 );
    test_beq( 3,  1,  1, 1 );
    test_beq( 4, -1, -1, 1 );

    test_beq( 5,  0,  1, 0 );
    test_beq( 6,  1,  0, 0 );
    test_beq( 7, -1,  1, 0 );
    test_beq( 8,  1, -1, 0 );

    clear_temp_registers();

    printf("== Testing SLT ==\n");

    test_slt(  1,  0x00000000, 0x00000000, 0 );
    test_slt(  2,  0x00000001, 0x00000001, 0 );
    test_slt(  3,  0x00000003, 0x00000007, 1 );
    test_slt(  4,  0x00000007, 0x00000003, 0 );
    test_slt(  5,  0x00000000, 0x00008000, 0 );
    test_slt(  6,  0x80000000, 0x00000000, 1 );
    test_slt(  7,  0x80000000, 0x00008000, 1 );
    test_slt(  8,  0x00000000, 0x00007fff, 1 );
    test_slt(  9,  0x7fffffff, 0x00000000, 0 );
    test_slt( 10,  0x7fffffff, 0x00007fff, 0 );
    test_slt( 11,  0x80000000, 0x00007fff, 1 );
    test_slt( 12,  0x7fffffff, 0x00008000, 0 );
    test_slt( 13,  0x00000000, 0xffffffff, 0 );
    test_slt( 14,  0xffffffff, 0x00000001, 1 );
    test_slt( 15,  0xffffffff, 0xffffffff, 0 );

    clear_temp_registers();

    printf("== Testing OR ==\n");

    test_or(  1, 0x00000000, 0x00000000, 0x00000000 );
    test_or(  2, 0xffffffff, 0xffffffff, 0x00000000 );
    test_or(  3, 0xffffffff, 0x00000000, 0xffffffff );
    test_or(  4, 0xffffffff, 0xffffffff, 0xffffffff );
    test_or(  5, 0x00ff00ff, 0x00ff0000, 0x000000ff );
    test_or(  6, 0xff00ffff, 0xff0000ff, 0x0000ffff );
    test_or(  7, 0xffffffff,         -1, 0x0000ffff );
    test_or(  8, 0x80000000, 0x80000000, 0x00000000 );
    test_or(  9, 0x8000ffff, 0x80000000, 0x0000ffff );
    test_or( 10, 0x7fffffff, 0x7fff0000, 0x0000ffff );
    test_or( 11, 0xffffffff, 0x12345678, 0xedcba987 );
    test_or( 12, 0x0fffffff, 0x0f0f0f0f, 0x00f0f0f0 );

    clear_temp_registers();

    printf("== Testing SLL ==\n");

    test_sll(  1, 0x00000001, 0x00000001,  0 );
    test_sll(  2, 0x00000002, 0x00000001,  1 );
    test_sll(  3, 0x00000080, 0x00000001,  7 );
    test_sll(  4, 0x00004000, 0x00000001, 14 );
    test_sll(  5, 0x80000000, 0x00000001, 31 );
    test_sll(  6, 0xffffffff, 0xffffffff,  0 );
    test_sll(  7, 0xfffffffe, 0xffffffff,  1 );
    test_sll(  8, 0xffffff80, 0xffffffff,  7 );
    test_sll(  9, 0xffffc000, 0xffffffff, 14 );
    test_sll( 10, 0x80000000, 0xffffffff, 31 );
    test_sll( 11, 0x21212121, 0x21212121,  0 );
    test_sll( 12, 0x42424242, 0x21212121,  1 );
    test_sll( 13, 0x90909080, 0x21212121,  7 );
    test_sll( 14, 0x48484000, 0x21212121, 14 );
    test_sll( 15, 0x80000000, 0x21212121, 31 );

    clear_temp_registers();

    printf("== Testing SRL ==\n");

    test_srl(  1, 0x00000000, 0x00000001,  1 );
    test_srl(  2, 0x00000000, 0x00000001,  2 );
    test_srl(  3, 0x00000001, 0x00000080,  7 );
    test_srl(  4, 0x00000001, 0x00004000, 14 );
    test_srl(  5, 0x00000001, 0x80000000, 31 );
    test_srl(  6, 0x00000001, 0x00010000, 16 );
    test_srl(  7, 0x00000003, 0x00000300,  8 );
    test_srl(  8, 0x0000000c, 0x00000300,  6 );
    test_srl(  9, 0x000000ff, 0x0000ff00,  8 );
    test_srl( 10, 0x0000000f, 0x00000f00,  8 );
    test_srl( 11, 0x0000f000, 0x0f000000, 12 );
    test_srl( 12, 0x00000000, 0x00000000,  5 );
    test_srl( 13, 0x0000ffff, 0xffff0000, 16 );
    test_srl( 14, 0x007e0000, 0x7e000000,  8 );
    test_srl( 15, 0x00000001, 0x00008000, 15 );

    clear_temp_registers();

    printf("== Testing SRA ==\n");

    test_sra(  1, 0xffffffff, 0xffffffff,  0 );
    test_sra(  2, 0xffffffff, 0xffffffff,  1 );
    test_sra(  3, 0xffffffff, 0xffffffff,  7 );
    test_sra(  4, 0xffffffff, 0xffffffff, 14 );
    test_sra(  5, 0xffffffff, 0xffffffff, 31 );
    test_sra(  6, 0x7fffffff, 0x7fffffff,  0 );
    test_sra(  7, 0x3fffffff, 0x7fffffff,  1 );
    test_sra(  8, 0x007fffff, 0x7fffffff,  8 );
    test_sra(  9, 0x0000ffff, 0x7fffffff, 15 );
    test_sra( 10, 0x0000003f, 0x7fffffff, 25 );
    test_sra( 11, 0x00000001, 0x7fffffff, 30 );
    test_sra( 12, 0x80000000, 0x80000000,  0 );
    test_sra( 13, 0xc0000000, 0x80000000,  1 );
    test_sra( 14, 0xffffc000, 0x80000000, 17 );
    test_sra( 15, 0xffffffff, 0xffffffff,  0 );

    clear_temp_registers();

    printf("== Testing BNE ==\n");

    test_bne( 1,  0,  1, 1 );
    test_bne( 2,  1,  0, 1 );
    test_bne( 3, -1,  1, 1 );
    test_bne( 4,  1, -1, 1 );
    test_bne( 5,  0,  0, 0 );
    test_bne( 6,  1,  1, 0 );
    test_bne( 7, -1, -1, 0 );

    clear_temp_registers();

    printf("== Testing BLT ==\n");

    test_blt( 1,  0,  1, 1 );
    test_blt( 2, -1,  1, 1 );
    test_blt( 3, -2, -1, 1 );
    test_blt( 4,  1,  0, 0 );
    test_blt( 5,  1, -1, 0 );
    test_blt( 6, -1, -2, 0 );
    test_blt( 7,  1, -2, 0 );

    clear_temp_registers();

    printf("== Testing BGE ==\n");

    test_bge(  1,  0,  0, 1 );
    test_bge(  2,  1,  1, 1 );
    test_bge(  3, -1, -1, 1 );
    test_bge(  4,  1,  0, 1 );
    test_bge(  5,  1, -1, 1 );
    test_bge(  6, -1, -2, 1 );
    test_bge(  7,  0,  1, 0 );
    test_bge(  8, -1,  1, 0 );
    test_bge(  9, -2, -1, 0 );
    test_bge( 10, -2,  1, 0 );

    
    clear_temp_registers();

    printf("== Testing BGEU ==\n");

    test_bgeu(  1, 0x00000000, 0x00000000, 1 );
    test_bgeu(  2, 0x00000001, 0x00000001, 1 );
    test_bgeu(  3, 0xffffffff, 0xffffffff, 1 );
    test_bgeu(  4, 0x00000001, 0x00000000, 1 );
    test_bgeu(  5, 0xffffffff, 0xfffffffe, 1 );
    test_bgeu(  6, 0xffffffff, 0x00000000, 1 );
    test_bgeu(  7, 0x00000000, 0x00000001, 0 );
    test_bgeu(  8, 0xfffffffe, 0xffffffff, 0 );
    test_bgeu(  9, 0x00000000, 0xffffffff, 0 );
    test_bgeu( 10, 0x7fffffff, 0x80000000, 0 );

    clear_temp_registers();

    printf("== Testing BLTU ==\n");

    test_bltu(  1, 0x00000000, 0x00000001, 1 );
    test_bltu(  2, 0xfffffffe, 0xffffffff, 1 );
    test_bltu(  3, 0x00000000, 0xffffffff, 1 );
    test_bltu(  4, 0x00000001, 0x00000000, 0 );
    test_bltu(  5, 0xffffffff, 0xfffffffe, 0 );
    test_bltu(  6, 0xffffffff, 0x00000000, 0 );
    test_bltu(  7, 0x80000000, 0x7fffffff, 0 );

    clear_temp_registers();

    volatile int32_t data0 = 0x00ff00ff;
    volatile int32_t data1 = 0xff00ff00;
    volatile int32_t data2 = 0x0ff00ff0;
    volatile int32_t data3 = 0xf00ff00f;

    printf("== Testing LB ==\n");

    test_lb( 1, 0xffffffff,  0, &data0 );
    test_lb( 2, 0x00000000,  1, &data0 );
    test_lb( 3, 0xffffffff,  2, &data0 );
    test_lb( 4, 0x00000000,  3, &data0 );
    test_lb( 5, 0x0000000f, -3, &data3 );
    test_lb( 6, 0xfffffff0, -2, &data3 );
    test_lb( 7, 0x0000000f, -1, &data3 );
    test_lb( 8, 0x0000000f,  0, &data3 );

    clear_temp_registers();

    printf("== Testing LH ==\n");

    test_lh( 1, 0x000000ff,  0, &data0 );
    test_lh( 2, 0x000000ff,  2, &data0 );
    test_lh( 3, 0x00000ff0,  4, &data1 );
    test_lh( 4, 0x00000ff0,  6, &data1 );
    test_lh( 5, 0xffffff00, -6, &data3 );
    test_lh( 6, 0x00000ff0, -4, &data3 );
    test_lh( 7, 0x00000ff0, -2, &data3 );
    test_lh( 8, 0xfffff00f,  0, &data3 );

    clear_temp_registers();

    printf("== Testing LW ==\n");

    test_lw( 1, 0x00ff00ff,   0, &data0 );
    test_lw( 2, 0xff00ff00,   4, &data0 );
    test_lw( 3, 0x0ff00ff0,   8, &data0 );
    test_lw( 4, 0xf00ff00f,  12, &data0 );
    test_lw( 5, 0x00ff00ff, -12, &data3 );
    test_lw( 6, 0xff00ff00,  -8, &data3 );
    test_lw( 7, 0x0ff00ff0,  -4, &data3 );
    test_lw( 8, 0xf00ff00f,   0, &data3 );

    clear_temp_registers();

    printf("== Testing SB ==\n");

    volatile int32_t buffer[4] = {0};
    
    test_sb( 1, 0x000000ff, 0xffffffff, 0, buffer );
    test_sb( 2, 0x0000007f, 0x0000007f, 1, buffer );
    test_sb( 3, 0x00000080, 0xffffff80, 2, buffer );
    test_sb( 4, 0x0000000f, 0x0000000f, 3, buffer );
    
    clear_temp_registers();

    printf("== Testing SH ==\n");

    test_sh( 1, 0x0000ffff, 0xffffffff, 0, buffer );
    test_sh( 2, 0x00007fff, 0x00007fff, 2, buffer );
    test_sh( 3, 0x00008000, 0xffff8000, 0, buffer );
    test_sh( 4, 0x00000f0f, 0x00000f0f, 2, buffer );
    
    clear_temp_registers();

    printf("== Testing SW ==\n");

    test_sw( 1, 0x12345678, 0x12345678,  0, buffer );
    test_sw( 2, 0xffffffff, 0xffffffff,  4, buffer );
    test_sw( 3, 0x0ff00ff0, 0x0ff00ff0,  8, buffer );
    test_sw( 4, 0x80000000, 0x80000000, 12, buffer );

    clear_temp_registers();

    printf("== Testing MUL ==\n");

    test_mul(  1,           6,           2,          3 );
    test_mul(  2,           0,         123,          0 );
    test_mul(  3,           0,           0,       -456 );
    test_mul(  4,           6,          -2,         -3 );
    test_mul(  5,         -14,           7,         -2 );
    test_mul(  6,  0xfffffffe,  0x7fffffff,          2 );
    test_mul(  7,  0x00000000, -0x40000000,         -4 );
    test_mul(  8, -0x7fffffff,          -1, 0x00000001 );
    test_mul(  9,  0x00000000,  0x80000000,          2 );
    test_mul( 10,  0x00000001,  0x7fffffff, 0x7fffffff );

    clear_temp_registers();

    printf("== Testing MULH ==\n");

    test_mulh(  1,          0,           2,          3 );
    test_mulh(  2,          0,         123,          0 );
    test_mulh(  3,          0,           0,       -456 );
    test_mulh(  4,          0,          -2,         -3 );
    test_mulh(  5, 0xffffffff,           7,         -2 );
    test_mulh(  6, 0x00000000,  0x7fffffff,          2 );
    test_mulh(  7, 0x00000001, -0x40000000,         -4 );
    test_mulh(  8, 0xffffffff,          -1, 0x7fffffff );
    test_mulh(  9, 0xffffffff,  0x80000000,          2 );
    test_mulh( 10, 0x3fffffff,  0x7fffffff, 0x7fffffff );

    clear_temp_registers();

    printf("== Testing DIV ==\n");

    test_div(  1,            2,           6,  3 );
    test_div(  2,           -2,          -6,  3 );
    test_div(  3,           -2,           6, -3 );
    test_div(  4,            2,          -6, -3 );
    test_div(  5,            0,           1,  2 );
    test_div(  6,        12345,       12345,  1 );
    test_div(  7,       -12345,       12345, -1 );
    test_div(  8,  -2147483648, -2147483648, -1 );
    test_div(  9,           -1,         123,  0 );
    test_div( 10,           -1,        -123,  0 );
    test_div( 11,           -1,           0,  0 );
    test_div( 12, 0x7fffffff/2,  0x7fffffff,  2 );
    test_div( 13,  -0x40000000,  0x80000000,  2 );

    clear_temp_registers();

    printf("== Testing REM ==\n");

    test_rem(  1,    0,           6,  3 );
    test_rem(  2,    0,          -6,  3 );
    test_rem(  3,    0,           6, -3 );
    test_rem(  4,    0,          -6, -3 );
    test_rem(  5,    1,           7,  3 );
    test_rem(  6,    1,          -7,  3 );
    test_rem(  7,    1,           7, -3 );
    test_rem(  8,   -1,          -7, -3 );
    test_rem(  9,    0,       12345,  1 );
    test_rem( 10,    0,       12345, -1 );
    test_rem( 11,    0, -2147483648, -1 );
    test_rem( 12,  123,         123,  0 );
    test_rem( 13, -123,        -123,  0 );
    test_rem( 14,    0,           0,  0 );
    test_rem( 15,    1,  0x7fffffff,  2 );
    test_rem( 16,    0,  0x80000000,  2 );

    return 0;
}