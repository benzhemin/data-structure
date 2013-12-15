#include <stdio.h>
#include <stdlib.h>

void left_shift(int *a, size_t len, size_t p){
	int tp, i,j;
	for(i=0; i<p; i++){
		tp = a[0];
		for(j=0; j<len-1; j++){
			a[j] = a[j+1];
		}
		a[j] = tp;
	}
}

void print_all(int *a, size_t len){
	int i;
	for(i=0; i<len; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main(void){
	int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	left_shift(a, sizeof(a)/sizeof(a[0]), 5);
	
	print_all(a, sizeof(a)/sizeof(a[0]));
	
	return 0;
}