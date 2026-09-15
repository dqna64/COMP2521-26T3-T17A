#include <stdlib.h>

/**
 * Definitions demo.
 * Which are also declarations.
 *
 * Run:
 * ```
 * $ clang 0-8-definition.c && ./a.out
 * ```
 */

#include <stdio.h>

// A function definition
int myFunc(int a, int b) { return a + b; }

int main() {
  // Calling a defined function
  myFunc(5, 7);

  // `myStackInt` has been defined
  // it has a type, name, and even has been allocated memory
  int myStackInt;
  printf("%d\n", myStackInt);

  // Another variable definition (is also a declaration)
  float *myFloatPtr;
  printf("%p\n", myFloatPtr);

  // A variable initialisation (is a definition, is a declaration)
  // `myStackDouble` has been declared and also defined
  double myStackDouble = 4392.34;
  printf("%lf\n", myStackDouble);

  // Another variable initialisation
  float *myDoublePtr = malloc(sizeof(double));
  printf("%p\n", myDoublePtr);
}