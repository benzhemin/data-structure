#include <stdio.h>
#include <stdlib.h>
#include "bitree.h"

void create_preorder_bitree(BiTree **T, ){
	char ch;
	scanf("%c", &ch);

	if(ch == ' '){
		*T = NULL;
	}else{
		BiTree *n_bitree = (BiTree *)malloc(sizeof(BiTree));
		n_bitree->data = ch;

		*T = n_bitree;
		create_preorder_bitree(&n_bitree->lchild);
		create_preorder_bitree(&n_bitree->rchild);
	}
}

void preorder_traverse_recursion(BiTree *T){
	if (T != NULL){
		printf("%c ", T->data);
		preorder_traverse_recursion(T->lchild);
		preorder_traverse_recursion(T->rchild);
	}
}

void inorder_traverse_recursion(BiTree *T){
	if(T != NULL){
		inorder_traverse_recursion(T->lchild);
		printf("%c ", T->data);
		inorder_traverse_recursion(T->rchild);
	}
}

void postorder_traverse_recursion(BiTree *T){
	if(T != NULL){
		postorder_traverse_recursion(T->lchild);
		postorder_traverse_recursion(T->rchild);
		printf("%c ", T->data);
	}
}

int main_test(void){
	BiTree *T;
	create_preorder_bitree(&T);

	preorder_traverse_recursion(T);
	printf("\n");
	inorder_traverse_recursion(T);
	printf("\n");
	postorder_traverse_recursion(T);

	return 0;
}