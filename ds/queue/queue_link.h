#ifndef _QUEUE_LINK_H
#define _QUEUE_LINK_H

#include "../predef.h"

typedef int ElemType;

typedef struct _Node{
	ElemType data;
	struct _Node *next;
} Node;

typedef struct {
	Node *front;
	Node *rear;
} QueueLink;

Status init_queue(QueueLink *Q);

Status destory_queue(QueueLink *Q);

BOOL empty_queue(QueueLink *Q);

Status enqueue(QueueLink *Q, ElemType e);

Status dequeue(QueueLink *Q, ElemType *e);

void print_queue(QueueLink *Q);

#endif
