/**
 * Variable declarations and definitions and initialisation
 */

double add(double a, double b);

// Global var in uninitialised segment
int globalVar1;
int globalVar2 = 83;

int main() {
    int localVar1;
    int localVar2 = 47;
}

double add(double a, double b) { return a + b; }