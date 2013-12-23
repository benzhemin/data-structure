#include <stdio.h>
#include <stdlib.h>
#include "link.h"

//查找并删除节点
void search_delete(Node **root, ElemType e){
	while(*root!=NULL){
		if((*root)->data == e){
			Node *p = *root;
			*root = p->next;
			free(p);
			break;
		}else{
			root = &(*root)->next;
		}
	}
}

void insert_elem(Node **proot, ElemType e){
	while(*proot!=NULL && (*proot)->data<e){
		proot = &(*proot)->next;
	}

	Node *new_n = (Node *)malloc(sizeof(Node));
	new_n->data = e;

	new_n->next = *proot;
	*proot = new_n;
}

int main(void){
	int a[] = {2, 4, 5, 5, 8, 9};
	Node *root = NULL;

	cp_array_link(&root, a, ARRAY_LEN(a));
	print_link(root);

	/*
	insert_index_link(&root, 1, 7);
	print_link(root);
	*/

	/*
	int d;
	while(scanf("%d", &d)!=-1){
		delete_index_link(&root, d, &d);
		print_link(root);
	}
	*/

	/*
	int d;
	while(scanf("%d", &d)!=-1){
		search_delete(&root, d);
		print_link(root);
	}
	*/

	int d;
	scanf("%d", &d);
	insert_elem(&root, d);
	print_link(root);
	
	return 0;
}