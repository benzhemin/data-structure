#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

typedef struct {
    SqQueue *pickedQueue;
    SqQueue *unpickedQueue;
}EUnit;

typedef struct _BiTree{
    EUnit *pdata;
    struct _BiTree *lchild;
    struct _BiTree *rchild;
} BiTree, *BiTreePtr;

void init_tree(BiTree **pt){
    BiTree *T = malloc(sizeof(BiTree));
    T->pdata = malloc(sizeof(EUnit));
    T->lchild = NULL;
    T->rchild = NULL;
    
    *pt = T;
}

BiTreePtr create_tree(BiTreePtr *pt){
    BiTreePtr new_T = NULL;
    init_tree(&new_T);
    
    if (pt != NULL) {
        *pt = new_T;
    }
    return new_T;
}

void process_input(BiTreePtr T){
    char buf[512] = {0};
    char *pb = buf;
    int ch;
    
    while ((ch=getchar())!=EOF && ch!='\n') {
        *pb++ = ch;
    }
    
    T->pdata->pickedQueue = create_queue_seq(NULL, sizeof(char));
    T->pdata->unpickedQueue = create_queue_seq(NULL, sizeof(char));
    
    for (pb=buf; *pb!='\0'; pb++) {
        enqueue_seq(T->pdata->unpickedQueue, pb);
    }
}

static void visit_queue_elem(void *p){
    printf("%c ", *(char *)p);
}

void build_tree(BiTreePtr pT){
    SqQueue *Q = create_queue_seq(NULL, sizeof(BiTreePtr));
    enqueue_seq(Q, &pT);
    
    while (!queue_seq_empty(Q)) {
        BiTreePtr T = NULL;
        dequeue_seq(Q, &T);
        
        if (!queue_seq_empty(T->pdata->unpickedQueue)) {
            BiTreePtr lchildT = create_tree(NULL);
            BiTreePtr rchildT = create_tree(NULL);
            
            char chPick;
            lchildT->pdata->unpickedQueue = copy_queue_seq(T->pdata->unpickedQueue);
            lchildT->pdata->pickedQueue = copy_queue_seq(T->pdata->pickedQueue);
            dequeue_seq(lchildT->pdata->unpickedQueue, &chPick);
            enqueue_seq(lchildT->pdata->pickedQueue, &chPick);
            
            rchildT->pdata->unpickedQueue = copy_queue_seq(lchildT->pdata->unpickedQueue);
            rchildT->pdata->pickedQueue = copy_queue_seq(T->pdata->pickedQueue);
            
            T->lchild = lchildT;
            T->rchild = rchildT;
            
            enqueue_seq(Q, &T->lchild);
            enqueue_seq(Q, &T->rchild);
            
        }
    }
    
    desotry_queue_seq(Q);
}

static void traverse_tree(BiTreePtr T){
    if (T!=NULL) {
        if (T->lchild==NULL && T->rchild==NULL) {
            print_queue_seq(T->pdata->pickedQueue, visit_queue_elem);
        }
        
        traverse_tree(T->lchild);
        traverse_tree(T->rchild);
    }
}

int main_test(void){
    BiTree *T = NULL;
    
    init_tree(&T);
    
    process_input(T);
    
    build_tree(T);
    
    traverse_tree(T);
    
    return 0;
}