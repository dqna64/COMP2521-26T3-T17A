// Run:
// clang 1-swap-correct.c && ./a.out

#include <stdio.h>

void swap(int *a, int *b);

int main(void) {
    int a = 5;
    int b = 7;
    swap(&a, &b);
    // What is the value
    // of a and b now?
}

void swap(int *pa, int *pb) {
    int tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}