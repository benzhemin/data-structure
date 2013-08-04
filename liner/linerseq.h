#ifndef _LINER_SEQ_H
#define _LINER_SEQ_H

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

//insert element to linerSeq
Status insert_linerseq(SqList *sq, int index, ElemType e);

//delete element in linerSeq
Status delete_linerseq(SqList *sq, int index, ElemType *e);

//cmp element int linerSeq
Status locate_elem_linerseq(SqList *sq, int e, CMP_ELEM cmp_elem);

//merge two linerseq
Status mearge_linerseq(SqList *la, SqList *lb, SqList *lc);

//insertion sort, sort from begin, total len elements
void sort_insertion(SqList *la, int begin, int len);

#endif
