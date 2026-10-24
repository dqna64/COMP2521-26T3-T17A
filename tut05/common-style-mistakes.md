# Common Style Mistakes

This page highlights some of the most common style issues in student assignment submissions for COMP2521. Please don't make the same mistakes in your assignments!

Make sure to read the full
[course style guide](https://cgi.cse.unsw.edu.au/~cs2521/26T3/style-guide) too.

---

## 1. Function order

Put each helper function directly below the function that calls it. If several functions call it, put it below the first one.

❌

```c
static int countNodes(struct node *head);
static int countNegative(struct node *head);
static void printStats(struct node *head);

int main(void) {
    ...
    printStats(head);
}

static int countNodes(struct node *head) {
    ...
}

static int countNegative(struct node *head) {
    ...
}

static void printStats(struct node *head) {
    printf("nodes: %d\n", countNodes(head));
    printf("negative: %d\n", countNegative(head));
}
```

✅

```c
static void printStats(struct node *head);
static int countNodes(struct node *head);
static int countNegative(struct node *head);

int main(void) {
    ...
    printStats(head);
}

static void printStats(struct node *head) {
    printf("nodes: %d\n", countNodes(head));
    printf("negative: %d\n", countNegative(head));
}

static int countNodes(struct node *head) {
    ...
}

static int countNegative(struct node *head) {
    ...
}
```

✅ Helper function with two callers should go below the first caller:

```c
struct node *appendToList(struct node *head, int value) {
    struct node *new = newNode(value);
    ...
}

static struct node *newNode(int value) {
    ...
}

struct node *prependToList(struct node *head, int value) {
    struct node *new = newNode(value);
    ...
}
```

Style guide: [Function Order](https://cgi.cse.unsw.edu.au/~cs2521/26T3/style-guide#function-order),
[Function Prototypes](https://cgi.cse.unsw.edu.au/~cs2521/26T3/style-guide#function-prototypes-function-signatures)

---

## 2. Line length

Keep lines under 80 characters.

❌

```c
        if (curr->next != NULL && curr->next->value < curr->value && curr->value != 0) {
            // stop at the first pair that is out of order, because the rest of the list doesn't matter
            printf("Found an out-of-order pair: %d comes before %d\n", curr->value, curr->next->value);
```

✅

```c
        if (curr->next != NULL && curr->next->value < curr->value &&
            curr->value != 0) {
            // stop at the first pair that is out of order, because the rest
            // of the list doesn't matter
            printf("Found an out-of-order pair: %d comes before %d\n",
                   curr->value, curr->next->value);
```

Style guide: [Line Width](https://cgi.cse.unsw.edu.au/~cs2521/26T3/style-guide#line-width),
[Auto-Formatting](https://cgi.cse.unsw.edu.au/~cs2521/26T3/style-guide#auto-formatting)

---

## 3. Static helper functions

Functions not declared in the `.h` header file must be declared `static`.

❌

```c
int countNodes(struct node *head);
...
int countNodes(struct node *head) {
```

✅

```c
static int countNodes(struct node *head);
...
static int countNodes(struct node *head) {
```

Functions declared in the `.h` must not be `static` - it won't compile.

Style guide: [Static Functions](https://cgi.cse.unsw.edu.au/~cs2521/26T3/style-guide#static-functions)

---

## 4. Function comments

Every function you write needs a descriptive comment above it.

Information you might want to put in this comment:
- what is the purpose of the function, why does it exist
- what does the function do
- conditions the function expects of its input
- guarantees the function makes about its output

Functions defined in the assignment spec or starter code are exempt.

❌

```c
// countNegative function
static int countNegative(struct node *head) {
```

✅

```c
// Returns the number of nodes in the list with a negative value.
// Returns 0 if the list is empty.
static int countNegative(struct node *head) {
```

```c
// Removes every node with a negative value from the list and frees them.
// Returns the new head of the list.
static struct node *removeNegative(struct node *head) {
```

Style guide: [Function Comments](https://cgi.cse.unsw.edu.au/~cs2521/26T3/style-guide#function-comments)

---

## 5. Repeated code

Move repeated code into a helper function.

❌

```c
struct node *appendToList(struct node *head, int value) {
    struct node *new = malloc(sizeof(struct node));
    if (new == NULL) {
        fprintf(stderr, "out of memory\n");
        exit(EXIT_FAILURE);
    }
    new->value = value;
    new->next = NULL;
    ...
}

struct node *prependToList(struct node *head, int value) {
    struct node *new = malloc(sizeof(struct node));
    if (new == NULL) {
        fprintf(stderr, "out of memory\n");
        exit(EXIT_FAILURE);
    }
    new->value = value;
    new->next = NULL;
    ...
}
```

✅

```c
struct node *appendToList(struct node *head, int value) {
    struct node *new = newNode(value);
    ...
}

// Creates a node containing value. Exits if out of memory.
static struct node *newNode(int value) {
    struct node *new = malloc(sizeof(struct node));
    if (new == NULL) {
        fprintf(stderr, "out of memory\n");
        exit(EXIT_FAILURE);
    }
    new->value = value;
    new->next = NULL;
    return new;
}

struct node *prependToList(struct node *head, int value) {
    struct node *new = newNode(value);
    ...
}
```

Style guide: [Don't Repeat Yourself](https://cgi.cse.unsw.edu.au/~cs2521/26T3/style-guide#don-t-repeat-yourself-dry-)

---

## 6. Constants / Magic numbers

Name constants with `#define`. For example, for "bigger than any `int`", use `INT_MAX` from `<limits.h>` if your spec allows it.

❌

```c
int nums[10];
...
int min = 999999;
```

❌ Not truly the largest possible integer

```c
#define INFINITY 999999
```

✅

```c
#include <limits.h>

#define MAX_SCORES 10
...
int nums[MAX_SCORES];
...
int min = INT_MAX;
```

Style guide: [Constants](https://cgi.cse.unsw.edu.au/~cs2521/26T3/style-guide#constants)
