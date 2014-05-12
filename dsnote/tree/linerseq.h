#ifndef _LINERSEQ_H
#define _LINERSEQ_H

#ifndef bool
#define bool int
#define TRUE 1
#define FALSE 0
#endif

#define ARRAY_LEN(x) sizeof(x)/sizeof(x[0])

#define LIST_INIT_SIZE 100
#define LIST_INCREMENT 10

typedef struct {
    void *elem;
    unsigned typesize;
    unsigned length;
    unsigned listsize;
} SqList;

SqList *create_linerseq(SqList **pL, unsigned size);

void init_linerseq(SqList *L, unsigned size);

void destory_linerseq(SqList *L);

void insert_linerseq(SqList *L, void *pe);

bool insert_linerseq_index(SqList *L, int index, void *pe);

void sort_linerseq(SqList *L, int (*cmp)(void *p1, void *p2));

#endif