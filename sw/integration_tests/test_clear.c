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