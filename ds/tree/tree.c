#include "tree.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void pre_order_traverse(TNode *node){
	if(node != NULL){
		printf("%c\n", node->data);
		pre_order_traverse(node->lchild);
		pre_order_traverse(node->rchild);
	}
}

void pre_order_traverse_level(TNode *node, int level){
	if(node != NULL){
		printf("%c, %d\n", node->data, level);
		pre_order_traverse_level(node->lchild, (level+1));
		pre_order_traverse_level(node->rchild, (level+1)
			);
	}
}

void visit(TNode *n){
	printf("%c\n", n->data);
}

//LDR
void in_order_traverse(TNode *root){
	SqStack stack;
	init_stack(&stack);
	push(&stack, root);
	TNode *p;
	while(!stack_empty(&stack)){
		get_top(&stack, (void **)&p);
		while(p->lchild != NULL){
			push(&stack, p->lchild);
			p = p->lchild;
		}
		
		while(!stack_empty(&stack)){
			pop(&stack, (void **)&p);
			visit(p);
			if(p->rchild != NULL){
				push(&stack, p->rchild);
				break;
			}
		}
	}
}

void create_tree(TNode **T){
	int ch = getchar();
	if(ch == '\n'){
		return;
	}else if(ch == '#'){
		*T = NULL;
	}else{
		TNode *n = (TNode *)malloc(sizeof(TNode));
		n->data = ch;
		*T = n;
		create_tree(&n->lchild);
		create_tree(&n->rchild);
	}
}

int main(void){
	TNode *T;
	create_tree(&T);
	
	//pre_order_traverse(T);
	pre_order_traverse_level(T, 1);
	//in_order_traverse(T);
	
	return 0;
}