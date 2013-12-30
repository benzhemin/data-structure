#ifndef _STACKSEQ_H
#define _STACKSEQ_H

#include "../predef.h"

typedef int ElemType;

typedef struct _Node{
	ElemType data;
	struct _Node *next;
}Node;

Status init_stack(Node **proot);

BOOL stack_empty(Node *root);

Status get_top(Node *root, ElemType *e);

Status push(Node **proot, ElemType e);

Status pop(Node **proot, ElemType *e);

void print_stack(Node *root);

#endif