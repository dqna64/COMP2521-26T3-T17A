/**
 * Run:
 * $ clang 5_palindrome_sol.c && ./a.out
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isPalindrome(char *s) {
    int l = 0;             // 1
    int r = strlen(s) - 1; // 1

    while (l < r) {         // n/2
        if (s[l] != s[r]) { // n/2
            return false;   // 1
        }
        l++; // n/2
        r--; // n/2
    }

    return true; // 1
}

/**
 * Time complexity:
 *
 * 1 + 1 + n/2 + n/2 + 1 + n/2 + n/2 + 1 = 4*n/2 + 4
 *
 * O(4 * n/2 + 4)
 * = O(4 * n/2) + O(4)
 * = O(2 * n) + O(4 * 1)  -- remove constant factors
 * = O(n) + O(1)          -- remove lower order terms
 * = O(n)
 *
 */

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