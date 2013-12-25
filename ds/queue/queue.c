#include <stdio.h>
#include <stdlib.h>
#include "queue_link.h"

Status init_queue(QueueLink *Q){
	Q->front = Q->rear = NULL;

	return OK;
}

Status destory_queue(QueueLink *Q){
	Node *p = Q->front;
	while(p != NULL){
		Node *pre = p;
		p = p->next;
		free(pre);
	}
    
    return OK;
}

BOOL empty_queue(QueueLink *Q){
	if(Q->front==Q->rear && Q->front==NULL){
		return TRUE;
	}
	return FALSE;
}

//尾部插入新元素
Status enqueue(QueueLink *Q, ElemType e){
	Node *new_n = (Node *)malloc(sizeof(Node));
	assert(new_n!=NULL);
	new_n->data = e;
	new_n->next = NULL;
    
    if (Q->rear == NULL) {
        Q->front = Q->rear = new_n;
    }else{
        Q->rear->next = new_n;
        Q->rear = new_n;
    }
    
    return OK;
}

//头部删除元素
Status dequeue(QueueLink *Q, ElemType *e){
	if (empty_queue(Q)){
		return ERROR;
	}

	Node *p = Q->front;
	Q->front = p->next;

	if (Q->front == NULL){
		Q->rear = Q->front;
	}
    
    *e = p->data;
	free(p);
    
    return OK;
}

void print_queue(QueueLink *Q){
    Node *p = Q->front;
    while (p!=NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    
    printf("\n");
}






