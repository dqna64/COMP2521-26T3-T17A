/**
 * Run:
 * $ clang 2_list_count_odds_sol.c linked_list.c && ./a.out
 */

#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

/**
 * Recursive function to cound the number of odd elements in a linked list.
 */
int listCountOdds(struct node *n) {
    if (n == NULL) {
        return 0;
    }

    if (n->value % 2 == 1) {
        // odd
        return 1 + listCountOdds(n->next);
    } else {
        // even
        return listCountOdds(n->next);
    }
}

/**
 * Takes in a container struct to a linked list and returns the number of odd
 * numbers in the contained linked list.
 */
int listCountOddsContainer(struct list *l) { return listCountOdds(l->head); }

int main() {
    struct node *list = listIntro();

    int listNumOdds = listCountOdds(list);
    printf("Number of odd nums in linked list: %d\n", listNumOdds);

    return 0;
}