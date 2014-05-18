#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "queue.h"

SqQueue *create_queue_seq(SqQueue **pq, unsigned typesize){
    SqQueue *Q = malloc(sizeof(SqQueue));
    init_queue_seq(Q, typesize);
    if (pq != NULL) {
        *pq = Q;
    }
    return Q;
}

SqQueue *copy_queue_seq(SqQueue *Q){
    SqQueue *new_Q = malloc(sizeof(SqQueue));
    new_Q->front = Q->front;
    new_Q->rear = Q->rear;
    new_Q->typesize = Q->typesize;
    
    new_Q->elem = malloc(Q->typesize * QUEUE_MAX_SIZE);
    memcpy(new_Q->elem, Q->elem, Q->typesize * QUEUE_MAX_SIZE);
    
    return new_Q;
}

void init_queue_seq(SqQueue *Q, unsigned typesize){
    Q->elem = malloc(typesize * QUEUE_MAX_SIZE);
    Q->typesize = typesize;
    Q->front = Q->rear = 0;
}

void desotry_queue_seq(SqQueue *Q){
    free(Q->elem);
    free(Q);
}

bool enqueue_seq(SqQueue *Q, void *pe){
    unsigned front = Q->front;
    unsigned rear = Q->rear;
    unsigned step = Q->typesize;
    char *prear = (char *)Q->elem + rear * step;
    
    if ((rear+1)%QUEUE_MAX_SIZE == front) {
        perror("Queue Overflow!");
        return FALSE;
    }
    
    memcpy(prear, pe, step);
    Q->rear = (rear+1) % QUEUE_MAX_SIZE;
    
    return TRUE;
}

bool dequeue_seq(SqQueue *Q, void *pe){
    unsigned front = Q->front;
    unsigned step = Q->typesize;
    char *pfront = (char *)Q->elem + step * front;
    
    if (queue_seq_empty(Q)) {
        return FALSE;
    }
    
    memcpy(pe, pfront, step);
    Q->front = (Q->front + 1) % QUEUE_MAX_SIZE;
    
    return TRUE;
}

unsigned queue_seq_length(SqQueue *Q){
    unsigned rear = Q->rear;
    unsigned front = Q->front;
    
    return (rear+QUEUE_MAX_SIZE-front) % QUEUE_MAX_SIZE;
}

bool queue_seq_empty(SqQueue *Q){
    return queue_seq_length(Q) == 0;
}

void print_queue_seq(SqQueue *Q, void (*visit_elem)(void *pe)){
    unsigned front = Q->front;
    unsigned rear = Q->rear;
    unsigned step = Q->typesize;
    
    while (front < rear) {
        char *pcur = (char *)Q->elem + step * front;
        visit_elem(pcur);
        front++;
    }
    printf("\n");
}


