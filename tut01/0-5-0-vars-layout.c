/**
 * Variable declarations and definitions and initialisation
 */

#include <stdlib.h>

double add(double a, double b);

int globalVar1;
int globalVar2 = 83;

static int globalVarStatic = 91;

int main() {
    int localVar1;
    int localVar2 = 47;
}

double add(double a, double b) { return a + b; }