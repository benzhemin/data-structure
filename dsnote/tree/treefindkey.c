#include <stdio.h>
#include <stdlib.h>

#include "bitree.h"

void bitree_find_key(BiTree *T, char key, BiTree **pq){
	if(T != NULL){
		if (T->data == key){
			*pq = T;
			return;
		}

		bitree_find_key(T->lchild, key, pq);
		bitree_find_key(T->rchild, key, pq);
	}
}

int main(void){
	BiTree *T = NULL;
	BiTree *Q = NULL;
	create_preorder_bitree(&T);
	bitree_find_key(T, '+', &Q);

	if (Q == NULL){
		printf("%s\n", "not found");
	}else{
		printf("%c \n", Q->data);
	}

	return 0;
}