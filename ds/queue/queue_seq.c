#include <stdio.h>
#include <stdlib.h>
#include "queue_seq.h"

Status init_queue(SqQueue *Q){
	Q->base = (ElemType *)malloc(sizeof(ElemType)*MAXSIZE);
	assert(Q->base!=NULL);

	Q->front = Q->rear = 0;
	return OK;
}

Status destory_queue(SqQueue *Q){
	free(Q->base);
	Q->front = Q->rear = 0;

	return OK;
}

int queue_length(SqQueue *Q){
	return (Q->rear-Q->front+MAXSIZE)%MAXSIZE;
}

BOOL empty_queue(SqQueue *Q){
	return Q->front == Q->rear;
}

Status enqueue(SqQueue *Q, ElemType e){
	//队列满
	if ((Q->rear+1)%MAXSIZE == Q->front){
		return ERROR;
	}

	*(Q->base+Q->rear) = e;
	Q->rear = (Q->rear+1) % MAXSIZE;

	return OK;
}

Status dequeue(SqQueue *Q, ElemType *e){
	if (empty_queue(Q)){
		return ERROR;
	}
	*e = *(Q->base + Q->front);
	Q->front = (Q->front+1) % MAXSIZE;

	return OK;
}

void print_queue(SqQueue *Q){
	int front = Q->front;
	int rear = Q->rear;
	while(front != rear){
		printf("%d ", *(Q->base+front));
		front = (front+1) % MAXSIZE;
	}
	printf("\n");
}



