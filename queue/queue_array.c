#include "queue_array.h"
#include <stdio.h>
#include <stdlib.h>

Status init_queue(SqQueue *Q){
	Q->base = (ElemType *)malloc(sizeof(ElemType)*MAX_QUEUE_SIZE);
	assert(Q->base!=NULL);
	Q->front = Q->rear = 0;
	return OK;
}

Status destory_queue(SqQueue *Q){
	free(Q->base);
	Q->front = Q->rear = 0;
}

Status empty_queue(SqQueue *Q){
	return Q->front == Q->rear;
}

int queue_len(SqQueue *Q){
	return (Q->front-Q->rear+MAX_QUEUE_SIZE)%MAX_QUEUE_SIZE;
}

Status enqueue(SqQueue *Q, ElemType e){
	//queue full
	if((Q->rear+1)%MAX_QUEUE_SIZE == Q->front){
		return ERROR;
	}
	*(Q->base+Q->rear) = e;
	Q->rear = (Q->rear+1) % MAX_QUEUE_SIZE;
	return OK;
}

Status dequeue(SqQueue *Q, ElemType *e){
	if(empty_queue(Q)){
		return ERROR;
	}
	*e = *(Q->base + Q->front);
	Q->front = (Q->front+1) % MAX_QUEUE_SIZE;
	return OK;
}

int main(void){
	
}