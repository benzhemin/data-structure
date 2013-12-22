#include <stdio.h>
#include <stdlib.h>
#include "linerseq.h"

void print_array(int *array, int len){
	for (int i = 0; i < len; ++i){
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main(void){
	int m=5, n=4;
	int a[] = {0, 1, 4, 5, 6, 7, 2, 3, 5, 8};

	print_array(a, ARRAY_LEN(a));

	int *pn;
	for(pn=a+m+1; pn<a+m+n+1; pn++){
		int *p = pn;
		while(p>a+1 && *p < *(p-1)){
			a[0] = *(p-1);没	
			*(p-1) = *p;
			*p = a[0];
			p--;
		}
	}

	print_array(a, ARRAY_LEN(a));
}