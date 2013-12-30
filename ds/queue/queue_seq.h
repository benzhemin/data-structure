#ifndef _QUEUE_SEQ_H
#define _QUEUE_SEQ_H

#include "../predef.h"

typedef int ElemType;

#define MAXSIZE 100

typedef struct{
	ElemType *base;
	int front;
	int rear;
}SqQueue;

Status init_queue(SqQueue *Q);

Status destory_queue(SqQueue *Q);

int queue_length(SqQueue *Q);

BOOL empty_queue(SqQueue *Q);

Status enqueue(SqQueue *Q, ElemType e);

Status dequeue(SqQueue *Q, ElemType *e);

void print_queue(SqQueue *Q);

#endif