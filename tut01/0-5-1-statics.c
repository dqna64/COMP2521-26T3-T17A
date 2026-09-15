/**
 * Variable declarations and definitions and initialisation
 */

#include <stdlib.h>

double addWithBonus(double a, double b);
static double minus(double a, double b);

int globalVar1;
int globalVar2 = 83;

static int globalVarStatic = 91;

int main() {
    int localVar1;
    int localVar2 = 47;
}

double addWithBonus(double a, double b) {
    static int bonus = 4;
    return a + b + bonus;
}

double minus(double a, double b) { return a - b; }