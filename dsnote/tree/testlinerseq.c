#include <stdio.h>
#include <stdlib.h>

#include "linerseq.h"

#define ARRAY_LEN(a) sizeof(a)/sizeof(a[0])

int cmp_value(void *pa, void *pb){
	int *pa_int = pa;
	int *pb_int = pb;

	if(*pa_int > *pb_int){
		return 1;
	}else if(*pa_int == *pb_int){
		return 0;
	}else{
		return -1;
	}
}

void print_list(SqList *L){
	int *pe = (int *)L->elem;
	for(int i=0; i<L->length; i++){
		printf("%d ", *(pe+i));
	}
	printf("\n");
}

int main(void){
	int a[] = {9, 2, 8, 4, 5, 1, 7};

	SqList *L = create_linerseq(NULL, sizeof(int));
	
	for(int i=0; i<ARRAY_LEN(a); i++){
		insert_linerseq(L, a+i);
	}
	
	print_list(L);
	sort_linerseq(L, cmp_value);
	print_list(L);

	return 0;
}
