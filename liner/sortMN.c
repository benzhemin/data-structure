#include "linerseq.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
 * Question desc: 前m个元素递增有序,后n个元素递增有序
 * 设计一个算法,使整个顺序表有序(原地排序,只借助一个元素的辅助空间)
*/

void order_linerseq(SqList *L, int m, int n){
	int *pm = L->elem;
	int *pn = L->elem + m;
	
	while(pm<(L->elem+m) && pn<(L->elem+m+n)){
		if(*pn < *pm){
			int temp = *pn;
			memmove(pm+1, pm, (pn-pm)*sizeof(ElemType));
			*pm = temp;
			++pn;
			//当有元素插入到m范围的数组中时,要扩大m的范围
			++m;
			print_linerseq(L);
			
		}else{
			pm++;
		}
	}
}

int main(void){
	SqList L;
	int m, n, i, d;
	init_linerseq(&L);
	
	int a[] = {2, 4, 5, 8};
	int b[] = {1, 3, 4, 7, 9};
	cp_array_linerseq(&L, a, ARRAY_LEN(a));
	print_linerseq(&L);
	cp_array_linerseq(&L, b, ARRAY_LEN(b));
	print_linerseq(&L);
	
	order_linerseq(&L, ARRAY_LEN(a), ARRAY_LEN(b));
	print_linerseq(&L);
	
	return 0;
}