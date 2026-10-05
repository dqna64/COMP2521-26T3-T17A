#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Run command:
 *    $ clang bst_count_odds.c bst.c && ./a.out
 *
 */

int bstCountOdds(struct node *t) {
  if (t == NULL) {
    return 0;
  }

  int nLeft = bstCountOdds(t->left);
  int nRight = bstCountOdds(t->right);

  if (t->value % 2 == 1) {
    return nLeft + nRight + 1;
  } else {
    return nLeft + nRight;
  }
}

int bstCountOddsSimplified(struct node *t) {
  if (t == NULL) {
    return 0;
  }

  if (t->value % 2 != 0) { // odd
    return 1 + bstCountOdds(t->left) + bstCountOdds(t->right);
  } else { // even
    return bstCountOdds(t->left) + bstCountOdds(t->right);
  }
}

int main(void) {
  TreeNode tree = NULL;
  tree = bstInsert(tree, 8);
  tree = bstInsert(tree, 3);
  tree = bstInsert(tree, 9);
  tree = bstInsert(tree, 1);
  tree = bstInsert(tree, 4);
  bstShow(tree);

  int numOddNodes = bstCountOdds(tree);
  printf("Number of odd nodes in BST: %d\n", numOddNodes); // should be 3
}