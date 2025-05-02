#include "all_tests.c"

__attribute__((naked)) int main() {
    asm volatile(
        "call all_tests\n\t"
        "li a0, 0\n\t"
        "ret\n\t"
    );
}