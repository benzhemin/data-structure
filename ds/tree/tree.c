#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tree.h"
#include "stack_seq_generic.h"

void create_bitree(BiTree **T){
    char ch;
    scanf("%c", &ch);

    if (ch==' ' || ch=='#'){
        *T = NULL;
    }else{
        BiTree *p = (BiTree *)malloc(sizeof(BiTree));
        p->data = ch;
        *T = p;

        create_bitree(&p->lchild);
        create_bitree(&p->rchild);
    }
}

void visit_node(BiTree *T){
    printf("%c ", T->data);
}

void pre_order_traverse(BiTree *T){
    if (T != NULL){
        visit_node(T);
        pre_order_traverse(T->lchild);
        pre_order_traverse(T->rchild);
    }
}

void in_order_traverse(BiTree *T){
    if (T != NULL){
        in_order_traverse(T->lchild);
        visit_node(T);
        in_order_traverse(T->rchild);
    }
}

void after_order_traverse(BiTree *T){
    if (T != NULL)
    {
        after_order_traverse(T->lchild);
        after_order_traverse(T->rchild);
        visit_node(T);
    }
}
