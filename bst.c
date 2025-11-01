#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/*The idea is to use only two structs, the Node struct will be used for internal logic while the tree structure
will be the one exposed to the user, for the moment we don't take note of the level of each node, maybe in the future.
For the moment the fiel parent is not useful, but we keep it for future ideas.*/
typedef struct Node{
	struct Node *parent;
	struct Node *left;
	struct Node *right;	
	int value;
} Node;

typedef struct{
	Node *root;
} Tree;



/*Generate an empty tree and returns the pointer to the Tree structure*/ 
Tree* bst_emp() {
    Tree* tree = malloc(sizeof(Tree));
    if (!tree) {
        perror("malloc failed");
        exit(1);
    }
    tree->root = NULL;
    return tree;
}


/*This function add a node to a tree, the input is a pointer to the Tree struct and the element to add */
void bst_add_node(Tree* tree, int key){


	Node* n = (Node*)malloc(sizeof(Node));
	n -> value = key;
	n -> left = NULL;
	n -> right = NULL;
	n -> parent = NULL;

	/*This handle the case of empty tree*/
	if (tree -> root == NULL){
		tree -> root = n;
		return;
		}

	
	Node* current = tree -> root;

	while(1){
	
		if (key > current -> value){ 
			
			if(!current -> right){
				
				n -> parent = current; 
				current -> right = n;
				break;
			}
			
			current = current -> right;
		
			
		}
	
		else if (key < current ->value){
			
			if(!current -> left){
				
				n -> parent = current; 
				current -> left = n;
				break;
			}
			
			current = current -> left;
			
		}
		
		/*For the moment we restrict to the case in which no element can be inserted multiple
		time in the tree*/
		else{
			free(n);
			break;
		}
    }

	

}


void bst_add_list(Tree* tree, int values[], int length) {
    for (int i = 0; i < length; i++) {
        bst_add_node(tree, values[i]);
    }
}

/*Subrutine used by other api print functions*/
void bst_print_nodes(Node* node) {
    if (node == NULL) return;
    bst_print_nodes(node->left);
    printf("%d ", node->value);
    bst_print_nodes(node->right);
}

/*print tre element in the tre in ascendent order*/
void bst_inorder(Tree* tree) {
    if (tree == NULL || tree->root == NULL) {
        printf("(empty tree)\n");
        return;
    }
    bst_print_nodes(tree->root);
    printf("\n");
}

/*look for an element in the tree, return true if the element is in the tree, false otherwise*/
bool bst_search(Tree* tree, int key){
	
	Node* current = tree -> root;
	
	while(current != NULL){
		
		if(key < current -> value){
			current = current -> left;
		}
		else if(key > current -> value){
			current = current -> right;
		}
		else{
			return true;
		}

	}

	return false;
}




























