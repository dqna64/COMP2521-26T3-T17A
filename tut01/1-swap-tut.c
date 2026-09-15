#include <stdio.h>

void swapIncorrectly(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void swapCorrectly(int a, int b) {
    // TODO
}

int main(void) {
    int a = 5;
    int b = 7;

    printf("=== Incorrect ===\n");
    printf("Before swap: a = %d, b = %d\n", a, b);  // a=5, b=7
    swapIncorrectly(a, b);
    printf("After swap: a = %d, b = %d\n", a, b);  // a=5, b=7

    printf("=== Correct ===\n");
    printf("Before swap: a = %d, b = %d\n", a, b);  // a=5, b=7
    swapCorrectly(&a, &b);
    printf("After swap: a = %d, b = %d\n", a, b);  // a=7, b=5
}
