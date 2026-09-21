/**
 * Run:
 * $ clang 6_two_sum_sol.c && ./a.out
 */

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Test cases
 * Nums: 2 3 4
 * Target: 6
 * Output: true (2+4=6)
 *
 * Nums: 2 3 5
 * Target: 6
 * Output: false (3 cannot be used twice to make 3+3=6)
 *
 * Nums: 1 2 5
 * Target: 5
 * Output: false (5 alone cannot be used to sum to target 5)
 *
 * Nums: 2 2 5
 * Target: 4
 * Output: true (duplicate 2 can be used to make 2+2=4)
 *
 * Nums: 5
 * Target: 6
 * Output: false (not enough nums to find two that sum to 6)
 *
 * Nums: 5
 * Target: 5
 * Output: false (not enough nums to find two that sum to 5)
 *
 */

bool hasTwoSum(int nums[], int n, int target) {
    for (int i = 0; i < n; i++) {              // n
        for (int j = i + 1; j < n; j++) {      // (n-1) + (n-2) + ... + 1
            if (nums[i] + nums[j] == target) { // (n-1) + (n-2) + ... + 1
                return true;                   // 1
            }
        }
    }
    return false; // 1
}

void runTests() {
    assert(hasTwoSum((int[]){}, 0, 5) == false);
    assert(hasTwoSum((int[]){4}, 1, 4) == false);
    assert(hasTwoSum((int[]){4}, 1, 8) == false);
    assert(hasTwoSum((int[]){2, 3}, 2, 4) == false);
    assert(hasTwoSum((int[]){2, 3}, 2, 5) == true);
    assert(hasTwoSum((int[]){7, 4, 10, 4, 2}, 5, 8) == true);
    assert(hasTwoSum((int[]){7, 4, 10, 4, 2}, 5, 9) == true);
    assert(hasTwoSum((int[]){7, 4, 10, 4, 2}, 5, 11) == true);
    assert(hasTwoSum((int[]){7, 4, 10, 4, 2}, 5, 12) == true);
    assert(hasTwoSum((int[]){7, 4, 10, 4, 2}, 5, 17) == true);
    assert(hasTwoSum((int[]){7, 4, 10, 4, 2}, 5, 2) == false);
    assert(hasTwoSum((int[]){7, 4, 10, 4, 2}, 5, 4) == false);
    assert(hasTwoSum((int[]){7, 4, 10, 4, 2}, 5, 5) == false);
    assert(hasTwoSum((int[]){7, 4, 10, 4, 2}, 5, 15) == false);
    assert(hasTwoSum((int[]){7, 4, 10, 4, 2}, 5, 21) == false);
}

int main(int argc, char *argv[]) {
    /**
     * Ask the user for a list of numbers and dynamically allocate an array to
     * store them.
     */
    printf("How many numbers: ");
    int size = 0;
    scanf("%d", &size);

    printf("Enter a list of numbers: ");
    int *nums = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &nums[i]);
    }

    int target;
    printf("Enter a target sum: ");
    scanf("%d", &target);

    if (hasTwoSum(nums, size, target)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    runTests();

    return 0;
}