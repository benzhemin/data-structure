#include "linerseq.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * 顺序表L,将L中所有小于表头元素的整数放在前半部分,大于的整数放在后半部分,数组下标从1开始存储
*/

//解法参考快速排序
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

/*
 * 
*/
void order_MN(SqList *L){
	ElemType *first, *last;
	ElemType pivot = *L->elem;
	
	first = L->elem+1;
	last = L->elem + L->length-1;
	
	while(first < last){
		while(*first < pivot){
			++first;
		}
		
		while(*last > pivot){
			--last;
		}
	}
}

int main(void){
	SqList L;
	int a[] = {5,9,6,3,8,5,2,7};
	init_linerseq(&L);
	memcpy(L.elem, a, sizeof(a));
	L.length = ARRAY_LEN(a);
	
	order_MN(&L);
	
	print_linerseq(&L);
	
	return 0;
}