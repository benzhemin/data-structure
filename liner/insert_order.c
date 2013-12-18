#include <stdio.h>
#include "linerseq.h"

//有序表中插入元素
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

//第i个位置之前插入元素
//1<=i<=length+1
void insert_index(SqList *sq, int index, ElemType e){
	check_needs_expand(sq);

	//插入位置
	ElemType *q = sq->elem+index-1;
	ElemType *p;
	for(p=sq->elem+sq->length; p>q; --p){
		*p = *(p-1);
	}
	*q = e;
	sq->length++;
}

//删除顺序表下标为p（1<=p<=length)的元素，成功返回1，否则返回0，并将被删除的值赋给e
Status delete_index(SqList *sq, int index, ElemType *e){
	if (index<1 || index>sq->length){
		return 0;
	}

	ElemType *p = sq->elem +index;
	*e = *(p - 1);
	for(; p<sq->elem+sq->length; p++){
		*(p-1) = *p;
	}
	sq->length--;

	return 1;
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

	printf("delete index:\n");
	scanf("%d", &d);

	delete_index(&sq, d, &d);
	print_linerseq(&sq);

	printf("deleted:%d\n", d);

	return 0;
}