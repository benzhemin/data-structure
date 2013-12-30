#include <stdlib.h>
#include <stdio.h>
#include "stack_link.h"

Status init_stack(Node **proot){
	*proot = NULL;
	return OK;
}

BOOL stack_empty(Node *root){
	return root == NULL;
}

Status get_top(Node *root, ElemType *e){
	if (stack_empty(root)){
		return ERROR;
	}

	*e = root->data;
	return OK;
}

Status push(Node **proot, ElemType e){
	Node *new_n = (Node *)malloc(sizeof(Node));
	assert(new_n != NULL);
	new_n->data = e;

	new_n->next = *proot;
	*proot = new_n;

	return OK;
}

Status pop(Node **proot, ElemType *e){
	if (stack_empty(*proot)){
		return ERROR;
	}

	Node *p = *proot;
	*e = p->data;

	*proot = p->next;
	free(p);

	return OK;
}

void print_stack(Node *root){
    while (root!=NULL) {
        printf("%d ", root->data);
        root = root->next;
    }
    printf("\n");
}


