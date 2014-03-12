#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "tree.h"

#define MAX_QUEUE_SIZE 100
#define TRUE 1
#define FALSE 0

typedef int bool;

typedef struct {
	void *elem;
	int front;
	int rear;
}Queue;

bool queue_init(Queue *Q, unsigned int type_size){
	Q->elem = malloc(MAX_QUEUE_SIZE * type_size);
	assert(Q->elem != NULL);

	Q->front = Q->rear = 0;
	return TRUE;
}

bool queue_empty(Queue *Q){
	return Q->rear == Q->front;
}

unsigned int queue_size(Queue *Q){
	return (Q->rear + MAX_QUEUE_SIZE - Q->front) % MAX_QUEUE_SIZE;
}

bool en_queue(Queue *Q, void *p, unsigned int type_size){
	if((Q->rear+1)%MAX_QUEUE_SIZE == Q->front){
		return FALSE;
	}

	memcpy((Q->elem+Q->rear), &p, type_size);
	Q->rear = (Q->rear + 1) % MAX_QUEUE_SIZE;

	return TRUE;
}

bool de_queue(Queue *Q, void **p, unsigned int type_size){
	if(queue_empty(Q)){
		return FALSE;
	}
	
	memcpy(p, Q->elem+Q->front, type_size);
	Q->front = (Q->front + 1) % MAX_QUEUE_SIZE;

	return TRUE;
}

int main(void){
	BiTree *T = NULL;
	create_bitree(&T);

	Queue Q;
	queue_init(&Q, sizeof(BiTree *));

	en_queue(&Q, T, sizeof(BiTree *));

	while(!queue_empty(&Q)){
		BiTree *bt = NULL;
		if(de_queue(&Q, &bt, sizeof(BiTree *))){
			printf("%c ", bt->data);

			if(bt->lchild){
				en_queue(&Q, bt->lchild, sizeof(BiTree *));
			}

			if(bt->rchild){
				en_queue(&Q, bt->rchild, sizeof(BiTree *));
			}
		}
	}

	return 0;
}



