#include "../predef.h"
#include "linerseq.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Status init_linerseq(SqList *sq){	
	sq->elem = (ElemType *)malloc(sizeof(ElemType)*LIST_INIT_SIZE);
	if(sq->elem == NULL){
		perror("memory alloc failure");
	}	
	sq->length = 0;
	sq->listsize = LIST_INIT_SIZE;
	return OK;	
}

void destory_linerseq(SqList *sq){
	free(sq->elem);
}

void check_needs_expand(SqList *sq){
	if(sq->length >= sq->listsize){
		sq->elem = (ElemType *)realloc(sq->elem, (sq->listsize+LIST_INCREMENT)*sizeof(ElemType));
		if(sq->elem == NULL){
			perror("memory alloc failure");
		}
		sq->listsize += LIST_INCREMENT;
	}
}

void cp_array_linerseq(SqList *sq, ElemType *array, int len){
	int i;
	for(i=0; i<len; i++){
		insert_linerseq(sq, array[i]);
	}
}

Status insert_linerseq(SqList *sq, ElemType e){
	return insert_linerseq_index(sq, sq->length+1, e);
}

Status insert_linerseq_index(SqList *sq, int index, ElemType e){
	assert(index>0);
	check_needs_expand(sq);

	ElemType *p, *q;
	q = sq->elem+index-1;
	for(p=sq->elem+sq->length-1; p>=q; p--){
		*(p+1) = *p;
	}
	*q = e;
	++(sq->length);
	return OK;
}

Status delete_linerseq(SqList *sq, int index, ElemType *e){
	if(index<1 || index>sq->length){
		return ERROR;
	}
	ElemType *p, *q;
	p = sq->elem+index-1;
	*e = *p;
	for(q=sq->elem+sq->length-1; p<q; p++){
		*p = *(p+1);
	}
	--sq->length;
	return OK;
}

Status locate_elem_linerseq(SqList *sq, int e, CMP_ELEM cmp_elem){
	ElemType *p = sq->elem;
	ElemType *q = sq->elem+sq->length;

	for(; p<q && cmp_elem(*p, e)!=0; p++);

	if (p>=q){
		return ERROR;
	}

	return p-sq->elem;
}

void print_linerseq(SqList *sq){
	ElemType *p;
	for(p=sq->elem; p<sq->elem+sq->length; p++){
		printf("%d ", *p);
	}
	printf("\n");
}

void sort_insertion(SqList *la, int begin, int len){
	//设置起始偏移位置
	ElemType *elem = la->elem + begin;
	int i, j;
	//0是第一个元素, 从第二个元素开始插入
	for(i=1; i<len; i++){
		for(j=0; j<i; j++){
			if(*(elem+i) < *(elem+j)){
				ElemType d = *(elem+i);
				memmove(elem+j+1,elem+j, (i-j)*sizeof(ElemType));
				*(elem+j) = d;
				break;
			}
		}
	}
}