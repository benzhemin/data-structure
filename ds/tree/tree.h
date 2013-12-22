#ifndef _TREE_H
#define _TREE_H

#include "../predef.h"

typedef int ElemType;

typedef struct _TNode{
	ElemType data;
	struct _TNode *lchild;
	struct _TNode *rchild;
} TNode;

#endif