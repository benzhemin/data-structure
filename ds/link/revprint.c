#include "linerlink.h"
#include <stdio.h>
#include <stdlib.h>

void revprint(Node *p){
	if(p == NULL){
		return;
	}else{
		revprint(p->next);
	}
	printf("%d,", p->data);
}

int main(void){
	int a[] = {7, 4, 5, 9, 3, 8};
	Node *header = (Node *)malloc(sizeof(Node));
	cp_array_link(header, a, ARRAY_LEN(a));
	
	print_linerlink(header);
	
	revprint(header->next);
	
	return 0;
}