/**
 * Run:
 * $ clang 5_palindrome_tut.c && ./a.out
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isPalindrome(char *s) {
    // TODO
    return false;
    // After implementing, evaluate time complexity
    // O(x)
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (isPalindrome(argv[1])) {
        printf("is a palindrome\n");
    } else {
        printf("not a palindrome\n");
    }
    return 0;
}
