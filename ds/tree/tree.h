#ifndef _TREE_H
#define _TREE_H

#include "predef.h"

typedef int ElemType;

typedef struct _Tree{
	int data;
	struct _Tree *lchild;
	struct _Tree *rchild;
} Tree;

void create_tree(Tree **PT);

void pre_order_traverse(Tree *T);

void in_order_traverse(Tree *T);

void inorder_traverse(Tree *T);

#endif