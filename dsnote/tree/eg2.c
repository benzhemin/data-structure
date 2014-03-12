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

int tree_depth(BiTree *T){
	if(T != NULL){
		int ldepth,rdepth;
		ldepth = tree_depth(T->lchild);
		rdepth = tree_depth(T->rchild);
		
		return ldepth > rdepth ? (ldepth+1) : (rdepth+1);

	}else{
		return 0;
	}
}

int main(void){
	BiTree *T = NULL;
	create_bitree(&T);

	//traverse(T, 0);
	int d = tree_depth(T);

	printf("depth:%d\n", d);

	return 0;
}
