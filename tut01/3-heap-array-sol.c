#include <stdlib.h>
#include <stdio.h>
/**
 * Array allocated on the stack
 *
 */
void stackArray(void) {
    int a[5];
    for (int i = 0; i < 5; i++) {
        a[i] = 42;
    }
}

/**
 * Array allocated on the heap
 *
 */
void heapArray(void) {
    int *a = malloc(5 * sizeof(int));  // 5 * 4
    for (int i = 0; i < 5; i++) {
        // a[i] = 42;
        // i == 3
        // 0x468 + 3 * 4 = 0x47a
        *(a + i) = 42;
        printf("%p\n", a+i);
    }
}

int main(void) {
    stackArray();
    heapArray();
    return 0;
}