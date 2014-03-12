#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void tree_search_key(BiTree *T, int key, BiTree **p){
	if(T != NULL){
		if(T->data == key){
			*p = T;
		}else{
			tree_search_key(T->lchild, key, p);
			tree_search_key(T->rchild, key, p);
		}
	}
}

int main(void){
	BiTree *T = NULL;
	create_bitree(&T);

	BiTree *p = NULL;
	tree_search_key(T, 'T', &p);
	
    if (p == NULL) {
        printf("not found\n");
    }else{
        printf("%c\n", p->data);
    }
    
	return 0;
}
