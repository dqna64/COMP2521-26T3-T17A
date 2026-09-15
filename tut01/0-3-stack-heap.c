/**
 * Variable declarations and definitions and initialisation
 */

#include <stdlib.h>

int main() {
    int stackMemory = 74;
    int *ptrToHeapMemory = malloc(sizeof(int));

    int stackArray[5] = {1, 2, 3, 4, 5};
    int *ptrToHeapArray = malloc(5 * sizeof(int));
}