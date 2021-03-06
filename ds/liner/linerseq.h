#ifndef _LINER_SEQ_H
#define _LINER_SEQ_H

#include "../predef.h"

#define LIST_INIT_SIZE 100
#define LIST_INCREMENT 10

typedef int ElemType;

typedef Status (*CMP_ELEM)(ElemType e1, ElemType e2);

typedef struct _SqList{
	ElemType *elem;
	int length;
	int listsize;
} SqList;

//initialize liner
Status init_linerseq(SqList *sq);

//destory liner
void destory_linerseq(SqList *sq);

//check if needs expand
void check_needs_expand(SqList *sq);

//insert at tail
Status insert_linerseq(SqList *sq, ElemType e);

//insert element to linerSeq
//index starts from 1
Status insert_linerseq_index(SqList *sq, int index, ElemType e);

//copy array contents to linerseq
void cp_array_linerseq(SqList *sq, ElemType *array, int len);

//delete element in linerSeq
Status delete_linerseq(SqList *sq, int index, ElemType *e);

//cmp element int linerSeq
Status locate_elem_linerseq(SqList *sq, int e, CMP_ELEM cmp_elem);

//insertion sort, sort from begin, total len elements
void sort_insertion(SqList *la, int begin, int len);

//print all elements
void print_linerseq(SqList *sq);

#endif
