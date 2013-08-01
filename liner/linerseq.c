#include "../predef.h"
#include "linerseq.h"
#include <stdio.h>
#include <stdlib.h>


Status init_linerseq(SqList *sq){	
	sq->elem = (ElemType *)malloc(sizeof(ElemType)*LIST_INIT_SIZE);
	if(sq->elem == NULL){
		perror("memory alloc failure");
	}	
	sq->length = 0;
	sq->listsize = LIST_INIT_SIZE;
	return OK;	
}

Status insert_linerseq(SqList *sq, int index, ElemType e){
	if(sq->length >= sq->listsize){
		sq->elem = (ElemType *)realloc(sq->elem, (sq->listsize+LIST_INCREMENT)*sizeof(ElemType));
		if(sq->elem == NULL){
			perror("memory alloc failure");
		}
		sq->listsize += LIST_INCREMENT;
	}
	ElemType *p, *q;
	q = &(sq->elem[index-1]);
	for(p=&(sq->elem[sq->length-1]); p>=q; p--){
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
	p = &(sq->elem[index-1]);
	*e = *p;
	for(q=&(sq->elem[sq->length-1]); p<q; p++){
		*p = *(p+1);
	}
	--sq->length;
	return OK;
}

Status locate_elem_linerseq(SqList *sq, int e, CMP_ELEM cmp_elem){
	int i=1;
	ElemType *p = sq->elem;
	while(i<=sq->length && cmp_elem(*p++, e)!=0);
	
	if(i>sq->length){
		return 0;
	}
	return i;
}

Status mearge_linerseq(SqList *la, SqList *lb, SqList *lc){
	ElemType *pa = la->elem;
	ElemType *pb = lb->elem;
	ElemType *pc = lc->elem;
	lc->listsize = lc->length = la->length + lb->length;
	
	while(pa<la->elem+la->length && pb<lb->elem+lb->length){
		if(*pa <= *pb)
			*pc++=*pa++;
		else
			*pc++=*pb++; 
	}
	while(pa<la->elem+la->length){
		*pc++ = *pa++;
	}
	while(pb<lb->elem+lb->length){
		*pc++ = *pb++;
	}
}

int main(void){
	
}