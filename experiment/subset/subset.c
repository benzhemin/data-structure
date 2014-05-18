#include <stdio.h>
#include <stdlib.h>

#include "cstdstring.h"
#include "queue.h"

typedef struct {
    SqQueue *pickedQueue;
    SqQueue *unpickedQueue;
} EUnit;

typedef struct _BiTree{
    EUnit *pdata;
    struct _BiTree *lchild;
    struct _BiTree *rchild;
} BiTree, *BiTreePtr;

static void visit_queue_elem(void *p){
    printf("%c ", *(char *)p);
}

BiTreePtr create_bitree(){
    BiTreePtr new_tree = malloc(sizeof(BiTree));
    new_tree->pdata = malloc(sizeof(EUnit));
    new_tree->lchild = NULL;
    new_tree->rchild = NULL;
    
    return new_tree;
}

void init_set(SqQueue *Q){
    char input[512] = { 0 };
    char *p = input;
    fgets(input, sizeof(input), stdin);
    
    while (*p!='\n' && &p!='\0') {
        enqueue_seq(Q, p);
        p++;
    }
}

void build_treeset(BiTreePtr *PT, SqQueue *unpickedQueue, SqQueue *pickedQueue){
    if (PT != NULL) {
        SqQueue *new_upQ = copy_queue_seq(unpickedQueue);
        SqQueue *new_lchildQ = copy_queue_seq(pickedQueue);
        SqQueue *new_rchildQ = copy_queue_seq(pickedQueue);
            
        print_queue_seq(unpickedQueue, visit_queue_elem);
        print_queue_seq(pickedQueue, visit_queue_elem);
            
        char ch;
        
        BiTreePtr T = create_bitree();
        T->pdata->pickedQueue = copy_queue_seq(pickedQueue);
        *PT = T;
        
        dequeue_seq(new_upQ, &ch);
        enqueue_seq(new_lchildQ, &ch);
        
        if (!queue_seq_empty(new_upQ)) {
            build_treeset(&T->lchild, new_upQ, new_lchildQ);
            build_treeset(&T->rchild, new_upQ, new_rchildQ);
        }
        
        desotry_queue_seq(new_lchildQ);
        desotry_queue_seq(new_rchildQ);
        desotry_queue_seq(new_upQ);
        
    }
}

static void traverse_tree(BiTreePtr T){
    if (T != NULL) {
        if (T->lchild==NULL && T->rchild==NULL) {
            print_queue_seq(T->pdata->pickedQueue, visit_queue_elem);
        }
        traverse_tree(T->lchild);
        traverse_tree(T->rchild);
    }
}

int main(void){
    SqQueue *upQ = create_queue_seq(NULL, sizeof(char));
    SqQueue *pQ = create_queue_seq(NULL, sizeof(char));
    BiTreePtr T = NULL;
    
    init_set(upQ);
    
    build_treeset(&T, upQ, pQ);
    
    //traverse_tree(T);
    
    desotry_queue_seq(upQ);
    desotry_queue_seq(pQ);
    return 0;
}