#ifndef _BITREE_H
#define _BITREE_H

typedef struct _BiTree{
	char data;
	struct _BiTree *lchild;
	struct _BiTree *rchild;
} BiTree;

void create_preorder_bitree(BiTree **T);
void preorder_traverse_recursion(BiTree *T);
void inorder_traverse_recursion(BiTree *T);
void postorder_traverse_recursion(BiTree *T);

#endif