/**
 * @file sort-ops-sol.c
 * @author Gordon Huang COMP2521
 * @brief Demo fundamental operations of sorting algorithms - compare and swap
 * @date 2025-03-04
 *
 * Execute:
 * $ clang sort-ops-sol.c && ./a.out
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef int Item;

/**
 * The operation of comparing two values is an important
 * fundamental operation in sorting algorithms.
 *
 * Given two values a and b:
 *
 * - if a is less than b    -> return -1
 * - if a is larger than b  -> return 1
 * - else a is same as b    -> return 0
 *
 * Example 1:
 * a=4, b=7 -> -1
 *
 * Example 2:
 * a=5, b=2 -> 1
 *
 * Example 3:
 * a=3, b=3 -> 0
 */
int compare(Item a, Item b) {
  if (a < b) {
    return -1;
  } else if (a > b) {
    return 1;
  } else {
    return 0;
  }
}

/**
 * The operation of swapping two values in an array
 * is an important fundamental operation in sorting
 * algorithms.
 *
 * Given an array `arr`, and two positions i and j
 * in the array, swap the two values at positions i and j.
 *
 * Example:
 * arr = [b, a, c]
 * i = 0, j = 1
 * ->
 * arr = [a, b, c]
 */
void swap(Item *arr, size_t i, size_t j) {
  Item tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}

/**
 * Alternative method for swap. Uses pointers to the two
 * array positions instead of indices of the array positions.
 */
void swap2(Item *ai, Item *aj) {
  Item tmp = *ai;
  *ai = *aj;
  *aj = tmp;
}

/**
 * Helper function to print out an array
 *
 * Example:
 * arr=[4, 2, 5], n=3
 * prints "Array: [4, 2, 5]"
 */
void printArray(Item *arr, size_t n) {
  printf("Array: [");

  size_t i = 0;
  for (; i < n - 1; i++) {
    printf("%d, ", arr[i]);
  }

  if (i == n - 1) { // this is the last item in arr
    printf("%d]\n", arr[i]);
  } else { // arr is an empty array
    printf("]\n");
  }
}

int main() {
  size_t n = 3; // Array will have size 3
  Item arr[] = {88, 77, 99};
  printArray(arr, n);

  printf("Swap arr[0] with arr[1]...\n");
  swap(arr, 0, 1);
  printArray(arr, n); // [77, 88, 99]

  printf("Swap arr[1] with arr[2]...\n");
  swap2(&(arr[1]), &(arr[2]));
  printArray(arr, n); // [77, 99, 88]

  printf("Swap arr[0] with arr[2]...\n");
  swap2(arr, arr + 2);
  printArray(arr, n); // [88, 99, 77]

  printf("Compare 4 to 7: %d\n", compare(4, 7)); // -1
  printf("Compare 5 to 2: %d\n", compare(5, 2)); // 1
  printf("Compare 3 to 3: %d\n", compare(3, 3)); // 0
}