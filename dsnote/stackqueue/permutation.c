#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
    Question: 求N个数的全排列
 */

#define ARRAY_LEN(x) sizeof(x)/sizeof(x[0])

static int count = 0;

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void print_all(int *base, int len){
	for(int *p=base; p<base+len; p++){
		printf("%d ", *p);
	}
	printf("\n");
}

void permutation(int *base, int start, int end){
	if (start >= end){
        count++;
		print_all(base, end);
	}else{
        //避免下一层递归破坏当前数据的顺序
		int *buf = (int *)malloc(sizeof(int)*(end-start));
		memcpy(buf, base+start, sizeof(int)*(end-start));

		for (int i = start; i < end; ++i){
			swap(buf, buf+(i-start));
			memcpy(base+start, buf, sizeof(int)*(end-start));
			permutation(base, (start+1), end);
		}
        
        free(buf);
	}
}

int main(void){
	int a[] = {1, 2, 3, 4};
	permutation(a, 1, ARRAY_LEN(a));
    printf("total:%d\n", count);
	return 0;
}




