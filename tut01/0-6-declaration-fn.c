/**
 * Function declarations and definitions
 *
 * On this program we can do preprocessing, compilation, assembly,
 * but cannot do linking and execution.
 *
 * First three steps:
 * ```
 * $ clang -c 0-6-declaration-fn.c -o 0-6-declaration-fn.o
 * OK
 * ```
 *
 * Last step:
 * ```
 * $ clang 0-6-declaration-fn.o -o 0-6-declaration-fn
 * Undefined symbols for architecture arm64:
 *   "_functionDeclaration", referenced from:
 *       _main in a.out
 * ld: symbol(s) not found for architecture arm64
 * clang: error: linker command failed with exit code 1 (use -v to see
 * invocation)
 * ```
 */

#include <stdio.h>

// Function declaration (i.e. function prototype)
void functionDeclaration(int a, int b);

// Function definition
void functionDefinition(int a, int b) {
    printf("%d + %d = %d\n", a, b, a + b);
    return;
}

int main() {
    // We can invoke a function that has been defined
    functionDefinition(3, 4);

    // The compiler allows you to call a declared function by its name
    // But the linker will fail, it cannot find where `functionDeclaration` is
    // defined. Comment this line out then this program will no longer encounter
    // a linker error!
    functionDeclaration(6, 7);
    // ^error: linker command failed with exit code 1
    // Undefined symbols for architecture arm64: "_functionDeclaration"
}

void functionDeclaration(int a, int b) { return; }