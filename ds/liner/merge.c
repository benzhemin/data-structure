typedef int ElemType;

#include <stdio.h>
#include <stdlib.h>

#include "linerseq.h"

void merge_list(SqList *la, SqList *lb, SqList *lc){
	ElemType *pa, *pb, *pc;
	ElemType *pa_last, *pb_last;

	lc->length = lc->listsize = la->length + lb->length;
	lc->elem = (ElemType *)malloc(sizeof(ElemType)*lc->listsize);
	assert(lc->elem!=NULL);

	pa = la->elem;
	pb = lb->elem;
	pc = lc->elem;
	pa_last = la->elem+la->length;
	pb_last = lb->elem+lb->length;

	while(pa<pa_last && pb<pb_last){
		if(*pa < *pb){
			*pc++ = *pa++;
		}else{
			*pc++ = *pb++;
		}
	}

	while(pa<pa_last){	*pc++ = *pa++;}
	
	while(pb<pb_last){	*pc++ = *pb++;}
}

int main(void){
	SqList la, lb, lc;

	init_linerseq(&la);
	init_linerseq(&lb);

	int a1[] = {2, 4, 5, 7, 9, 11};
	int a2[] = {1, 2, 4, 5, 6, 9, 10};

	cp_array_linerseq(&la, a1, sizeof(a1)/sizeof(a1[0]));
	cp_array_linerseq(&lb, a2, sizeof(a2)/sizeof(a2[0]));

	print_linerseq(&la);
	print_linerseq(&lb);

	merge_list(&la, &lb, &lc);

	print_linerseq(&lc);

	destory_linerseq(&la);
	destory_linerseq(&lb);
	destory_linerseq(&lc);

	return 0;
}