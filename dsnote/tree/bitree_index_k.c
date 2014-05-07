#include <stdio.h>
#include <stdlib.h>

#include "bitree.h"

void bitree_indxe_k(BiTree *T, int k){
	static int i = 0;

	if(T != NULL){
		i = i + 1;
		if (i == k){
			printf("%c\n", T->data);
		}

		bitree_indxe_k(T->lchild, k);
		bitree_indxe_k(T->rchild, k);
	}
}

int main(void){
	BiTree *T;
	create_preorder_bitree(&T);
	bitree_indxe_k(T, 7);

	return 0;
}