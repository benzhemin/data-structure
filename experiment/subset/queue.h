#ifndef _QUEUE_H
#define _QUEUE_H

#define QUEUE_MAX_SIZE 100

#ifndef bool
#define bool int

#define TRUE 1
#define FALSE 0

#endif

typedef struct {
    void *elem;
    unsigned typesize;
    unsigned front;
    unsigned rear;
}SqQueue;

SqQueue *create_queue_seq(SqQueue **pq, unsigned typesize);

SqQueue *copy_queue_seq(SqQueue *Q);

void init_queue_seq(SqQueue *Q, unsigned typesize);

void desotry_queue_seq(SqQueue *Q);

unsigned queue_seq_length(SqQueue *Q);

bool queue_seq_empty(SqQueue *Q);

bool enqueue_seq(SqQueue *Q, void *pe);

bool dequeue_seq(SqQueue *Q, void *pe);

void print_queue_seq(SqQueue *Q, void (*visit_elem)(void *pe));

#endif