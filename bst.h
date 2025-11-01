#ifndef BST_H
#define BST_H

#include <stdbool.h>

/* ============================
 *  STRUCT DEFINITIONS
 * ============================ */

typedef struct Node {
    struct Node *parent;
    struct Node *left;
    struct Node *right;
    int value;
} Node;

typedef struct {
    Node *root;
} Tree;

/* ============================
 *  PUBLIC API DECLARATIONS
 * ============================ */

// --- Creation ---
Tree* bst_emp(void);

// --- Insertion ---
void bst_add_node(Tree* tree, int key);
void bst_add_list(Tree* tree, int values[], int length);

// --- Search ---
bool bst_search(Tree* tree, int key);

// --- Printing ---
void bst_inorder(Tree* tree);

#endif 
