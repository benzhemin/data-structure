#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void find_sequence_num(BiTree *T, int k){
	static int count = 0;

	if(T != NULL){
		count++;

		if(k == count){
			printf("num %d found %c\n", k, (char)T->data);
		}

		find_sequence_num(T->lchild, k);
		find_sequence_num(T->rchild, k);
	}
}
