#ifndef _TREE_H
#define _TREE_H

#include "predef.h"

typedef int ElemType;

typedef struct _BiTree{
	int data;
	struct _BiTree *lchild;
	struct _BiTree *rchild;
} BiTree;

void visit_node(BiTree *T);

void create_bitree(BiTree **T);

void pre_order_traverse(BiTree *T);

void in_order_traverse(BiTree *T);

void after_order_traverse(BiTree *T);

#endif