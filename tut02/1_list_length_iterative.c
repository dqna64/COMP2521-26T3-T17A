/**
 * Run:
 * $ clang 1_list_length_iterative.c linked_list.c && ./a.out
 */

#include <stdio.h>

#include "linked_list.h"

int listLength(struct node *n) {
    int length = 0;
    struct node *curr = n;

    while (curr != NULL) {
        length++;
        curr = curr->next;
    }
    return length;
}

int main() {
    struct node *list = listIntro();

    int listLengthRes = listLength(list);
    printf("Length of linked list: %d\n", listLengthRes);

    return 0;
}
