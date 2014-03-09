#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int depth = 0;

void traverse(BiTree *T, int d){
	if(T != NULL){
		if(d > depth){
			depth = d;
		}
		traverse(T->lchild, (d+1));
		traverse(T->rchild, (d+1));
	}
}

int main(void){
	BiTree *T = NULL;
	create_bitree(&T);

	traverse(T, 1);

	printf("depth:%d", depth);

	return 0;
}
