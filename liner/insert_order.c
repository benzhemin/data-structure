#include <stdio.h>
#include "linerseq.h"

void insert_order(SqList *sq, ElemType e){
	check_needs_expand(sq);

	//search from the end
	/*
	ElemType *p = sq->elem + sq->length;
	while(e<*(p-1) && p>sq->elem){
		*p = *(p-1);
		p--;
	}
	*p = e;
	sq->length++;
	*/

	//search from the beginning
	ElemType *p = sq->elem;
	ElemType *q = sq->elem+sq->length;
	while(e>*p && p<q){
		p++;
	}

	for(;q>p; q--){
		*q = *(q-1);
	}

	*p = e;
	sq->length++;

	print_linerseq(sq);

}

int main(void){
	int a[] = {1, 2, 4, 6, 7, 8, 8, 10};

	SqList sq;
	init_linerseq(&sq);
	cp_array_linerseq(&sq, a, sizeof(a)/sizeof(a[0]));
	print_linerseq(&sq);

	int d;
	scanf("%d", &d);
	insert_order(&sq, d);

	return 0;
}