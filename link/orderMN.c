#include "linerseq.h"

int main(void){
	SqList L;
	init_linerseq(&L);
	
	//pre m element;
	int i, m, n, d;
	printf("input m");
	scanf("%d", &m);
	for(i=0; i<m; i++){
		scanf("%d", &d);
		insert_linerseq(&L, i, d);
	}
	
	//n elements
	printf("input n");
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &n);
		insert_linerseq(&L, m+i, d);
	}
	
	
}