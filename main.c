#include<stdio.h>
#include "bst.h"

int main(){

    /*TEST STRUTTURA DATI ALBERO BINARIO*/


	/*Generate an empy tree and add a list of node to the tree*/
	Tree* tree= bst_emp();
	bst_add_node(tree,3);
	bst_add_node(tree,34);
	bst_add_node(tree,23);
	bst_add_node(tree,121);
	bst_add_node(tree,45);
	bst_add_node(tree,13);
	bst_inorder(tree);


	/*Add a whole array to the tree*/
	int a[] = {45,46,67,35,89,0,35,4678};
	int len = sizeof(a)/sizeof(a[0]);
	bst_add_list(tree, a, len);
	bst_inorder(tree);
	
	/*Implementation of searching*/
	if(bst_search(tree,45)){
		printf("trovato\n");
	}
	else{
		printf("non trovato\n");
	}
	
	return 0;
}