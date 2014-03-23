#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "tree.h"

#define MAX_QUEUE_SIZE 100

#define TRUE 1
#define FALSE 0

typedef int bool;

typedef struct{
	void *elem;
	unsigned typesize;
	unsigned front;
	unsigned rear;
}Queue;

bool init_queue(Queue *Q, unsigned typesize){
	Q->elem = malloc(typesize * MAX_QUEUE_SIZE);
	assert(Q->elem != NULL);

	Q->typesize = typesize;
	Q->front = Q->rear = 0;

	return TRUE;
}

bool enqueue(Queue *Q, void *p){
	if((Q->rear+1)%MAX_QUEUE_SIZE == Q->front){
		return FALSE;
	}

	char *pr = (char *)Q->elem + Q->typesize*Q->rear;
	memcpy(pr, p, Q->typesize);
    
	Q->rear = (Q->rear+1)%MAX_QUEUE_SIZE;

	return TRUE;
}

bool dequeue(Queue *Q, void *p){
	if(Q->front == Q->rear){
		return FALSE;
	}

	char *ps = (char *)Q->elem + Q->front*Q->typesize;
	memcpy(p, ps, Q->typesize);
	Q->front = (Q->front + 1)%MAX_QUEUE_SIZE;
	return TRUE;
}

unsigned queue_size(Queue *Q){
	return (Q->rear+MAX_QUEUE_SIZE-Q->front) % MAX_QUEUE_SIZE;
}

bool queue_empty(Queue *Q){
	return Q->front == Q->rear;
}

int main(void){
	BiTree *root = NULL;
	Queue Q;

	create_bitree(&root);

	init_queue(&Q, sizeof(BiTree *));
	enqueue(&Q, &root);
	root->level = 0;

	while(!queue_empty(&Q)){
		BiTree *pt = NULL;
		if(dequeue(&Q, &pt)){
			if(pt->lchild != NULL){
				enqueue(&Q, &pt->lchild);
				pt->lchild->level = pt->level+1;
			}

			if(pt->rchild != NULL){
				enqueue(&Q, &pt->rchild);
				pt->rchild->level = pt->level+1;
			}
		}
	}

	unsigned *count_arr = (unsigned *)malloc(sizeof(unsigned) * Q.rear);
	assert(count_arr!=NULL);
	memset(count_arr, 0, sizeof(unsigned) * Q.rear);

    unsigned i;
	for(i=0; i<Q.rear; i++){
		BiTree **pt = (BiTree **)((char *)Q.elem + Q.typesize*i);
        printf("%c %d\n", (*pt)->data, (*pt)->level);
		count_arr[(*pt)->level]++;
	}

	unsigned max = 0;
	for(i=0; i<Q.rear; i++){
		if(count_arr[i] > max){
			max = count_arr[i];
		}
	}

	printf("max count:%d\n", max);

	return 0;
}