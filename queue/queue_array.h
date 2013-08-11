#ifndef _QUEUE_ARRAY_H
#define _QUEUE_ARRAY_H

#include "../predef.h"

typedef int ElemType;

//定义循环队列最大长度
#define MAX_QUEUE_SIZE 100

typedef struct {
	ElemType *base;
	int front;
	int rear;
} SqQueue;

Status init_queue(SqQueue *Q);

Status destory_queue(SqQueue *Q);

Status empty_queue(SqQueue *Q);

int queue_len(SqQueue *Q);

Status enqueue(SqQueue *Q, ElemType e);
Status dequeue(SqQueue *Q, ElemType *e);

#endif