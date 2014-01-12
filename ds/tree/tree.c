#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tree.h"
#include "stack_seq_generic.h"

void create_tree(Tree **PT){
	char ch;
	scanf("%c", &ch);
	if (ch==' ' || ch=='#'){
		*PT = NULL;
	}else{
		Tree *p = (Tree *)malloc(sizeof(Tree));
		assert(p!=NULL);
		p->data = ch;
		
        *PT = p;
		create_tree(&p->lchild);
		create_tree(&p->rchild);
	}
}

void pre_order_traverse(Tree *T){
	if (T!=NULL){
		printf("%c", T->data);
		pre_order_traverse(T->lchild);
		pre_order_traverse(T->rchild);
	}
}

void in_order_traverse(Tree *T){
    SqStack s;
    init_stack(&s, sizeof(Tree *));
    push(&s, &T);
    while (!stack_empty(&s)) {
        Tree *p;
        while(get_top(&s, &p) && p!=NULL){
            push(&s, &p->lchild);
        }
        pop(&s, NULL);
        
        if (!stack_empty(&s)) {
            pop(&s, &p);
            printf("%c", p->data);
            push(&s, &p->rchild);
        }
    }
}

void inorder_traverse(Tree *T){
    SqStack s;
    init_stack(&s, sizeof(Tree *));
    Tree *p = T;
    while (p || !stack_empty(&s)) {
        if (p!=NULL) {
            push(&s, &p);
            p = p->lchild;
        }else{
            pop(&s, &p);
            printf("%c", p->data);
            p = p->rchild;
        }
    }
}