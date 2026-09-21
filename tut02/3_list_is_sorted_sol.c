/**
 * Run:
 * $ clang 3_list_is_sorted_sol.c linked_list.c && ./a.out
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

bool listIsSortedContainer(struct list *l);
bool listIsSorted(struct node *l);

int main() {
    struct node *list = listIntro();

    int res = listIsSorted(list);
    printf("Linked list sorted order:  %s\n", res ? "true" : "false");

    return 0;
}

/**
 * Recursive function to determine whether the linked list is in sorted
 * ascending order.
 */
bool listIsSorted(struct node *n) {
    if (n == NULL || n->next == NULL) {
        return true;
    }
    if (n->value <= n->next->value) {
        return listIsSorted(n->next);
    } else {
        return false;
    }
}

/**
 * Takes in a container struct to a linked list and returns whether the
 * contained linked list is in sorted ascending order.
 */
bool listIsSortedContainer(struct list *l) { return listIsSorted(l->head); }