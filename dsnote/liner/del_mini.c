#include <stdio.h>
#include <stdlib.h>
#include "link.h"

/*
	设计一个算法，删除单链表L(有头节点)中的一个最小值节点
*/

void del_min(Node **proot){
	Node **pmin = NULL;
	while(*proot!=NULL){
		if (pmin == NULL){
			pmin = proot;
			proot = &(*proot)->next;
			continue;
		}

		if ((*proot)->data < (*pmin)->data){
			pmin = proot;
		}
		proot = &(*proot)->next;
	}

	Node *temp = *pmin;
	*pmin = (*pmin)->next;
	free(temp);
}

int main(void){
	int a[] = {4, 6, 8, 3, 4, 2, 9, 4, 6, 8};

	Node *root;
	cp_array_link(&root, a, ARRAY_LEN(a));
    print_link(root);
    
    del_min(&root);
    print_link(root);
    
    return 0;
}