#include <stdio.h>
#include <stdlib.h>
#include "bitree.h"

int how_deep(BiTree *T){

	if (T == NULL){
		return 0;
	}else{
		int ldeep = 0;
		int rdeep = 0;

		ldeep = how_deep(T->lchild)+1;
		rdeep = how_deep(T->rchild)+1;

		return ldeep>rdeep ? ldeep : rdeep;
	}
}

int main(void){
	BiTree *T;
	int deep;
	
	create_preorder_bitree(&T);
	deep = how_deep(T);
	printf("%d\n", deep);

	return 0;
}