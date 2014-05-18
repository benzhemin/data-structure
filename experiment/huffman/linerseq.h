#ifndef Huffman_linerseq_h
#define Huffman_linerseq_h

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

SqList *create_linerseq(SqList **pl, unsigned size);

void destory_linerseq(SqList *L);

void init_linerseq(SqList *L, unsigned size);

void insert_linerseq(SqList *L, void *p);

bool linerseq_empty(SqList *L);

void linserseq_remove_first(SqList *L, void *pe);

void sort_linerseq(SqList *L, int (*cmp_value)(void *pa, void *pb));

void print_linerseq(SqList *L, void (*visit_elem)(int index, void *pe));

#endif
