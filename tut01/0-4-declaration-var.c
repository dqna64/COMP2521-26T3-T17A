/**
 * Variable declarations and definitions and initialisation
 *
 * On this program we can do preprocessing, compilation, assembly,
 * but cannot do linking and execution.
 *
 * First three steps:
 * ```
 * $ clang -c 0-4-declaration-var.c -o 0-4-declaration-var.o
 * OK
 * ```
 *
 * Last step:
 * ```
 * $ clang 0-4-declaration-var.o -o 0-4-declaration-var
 * Undefined symbols for architecture arm64:
 *   "_declaredVariable", referenced from:
 *       _main in program.o
 * ld: symbol(s) not found for architecture arm64
 * clang: error: linker command failed with exit code 1 (use -v to see
 * invocation)
 * ```
 */

#include <stdio.h>

// A variable declaration
// We have told the compiler there is a variable with type `int`
// and name `declaredVariable`
extern int declaredVariable;

// Another variable declaration
extern float *myFloatPtr;

int definedVariableGlobal;

int initialisedVariableGlobal = 48392;

int main() {
    printf("definedVariableGlobal: %d\n", definedVariableGlobal); // 0
    printf("initialisedVariableGlobal:   %d\n",
           initialisedVariableGlobal); // 48392

    int definedVariableLocal;
    printf("definedVariableLocal:  %d\n", definedVariableLocal);
    // ^^ definedVariableLocal will initially be some garbage value
    // that is already at the memory location e.g. 5874357

    // Cannot access a variable that is only declared but not defined
    // Comment this line out then this program will no longer encounter a
    // linker error!
    printf("%d\n", declaredVariable);
}