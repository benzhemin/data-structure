#include "queue_link.h"
#include <stdio.h>
#include <stdlib.h>

Status init_queue(QueueLink *Q){
	Node *s = (Node *)malloc(sizeof(Node));
	assert(s!=NULL);
	s->next = NULL;
	
	Q->front = Q->rear = s;
	return OK;
}

Status destory_queue(QueueLink *Q){
	Node *p = Q->front;
	while(p!=NULL){
		Node *r = p;
		p = p->next;
		free(r);
	}
}

BOOL empty_queue(QueueLink *Q){
	return Q->front == Q->rear;
}

Status enqueue(QueueLink *Q, ElemType e){
	Node *s = (Node *)malloc(sizeof(Node));
	assert(s!=NULL);
	s->data = e;
	s->next = NULL;
	
	Q->rear->next = s;
	Q->rear = s;
	return OK;
}

Status dequeue(QueueLink *Q, ElemType *e){
	if(empty_queue(Q)){
		return ERROR;
	}
	
	Node *p = Q->front->next;
	*e = p->data;
	Q->front->next = p->next;
	//如果只有一个元素,释放p后Q->rear成为野指针
	//注意链式队列实际上维护两个指针,注意尾指针
	if(Q->rear == p){
		Q->rear = Q->front;
	}
	
	free(p);
	
	return OK;
}