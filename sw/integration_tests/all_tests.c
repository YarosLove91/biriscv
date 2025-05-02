#include "test_and.c"
#include "test_xor.c"
#include "test_sub.c"
#include "test_add.c"
#include "test_beq.c"
#include "test_slt.c"
#include "test_or.c"
#include "test_sll.c"
#include "test_srl.c"
#include "test_sra.c"
#include "test_bne.c"
#include "test_blt.c"
#include "test_bge.c"
#include "test_bgeu.c"
#include "test_bltu.c"
#include "test_lb.c"
#include "test_lh.c"
#include "test_lw.c"
#include "test_sb.c"
#include "test_sh.c"
#include "test_sw.c"
#include "test_mul.c"
#include "test_mulh.c"
#include "test_div.c"
#include "test_rem.c"
#include "test_clear.c"

__attribute__((naked)) void all_tests() {
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

    TEST_DIV(  1,          6,           2,  3 );
    TEST_DIV(  2,         -6,          -2,  3 );
    TEST_DIV(  3,          6,          -2, -3 );
    TEST_DIV(  4,         -6,           2, -3 );
    TEST_DIV(  5,         10,           5,  2 );
    TEST_DIV(  6,      12345,       12345,  1 );
    TEST_DIV(  7,     -12345,       12345, -1 );
    TEST_DIV(  8,    -214748,     -214748,  1 );
    TEST_DIV(  9,         -1,         123,  0 );

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
    TEST_REM( 11,     -214748,   -1,  0 );
    TEST_REM( 12,         123,  123,  0 );
    TEST_REM( 13,        -123, -123,  0 );
    TEST_REM( 14,           0,    0,  0 );
    TEST_REM( 15,  0x7fffffff,    2,  1 );
    TEST_REM( 16,  0x80000000,    2,  0 );

    abort();
}