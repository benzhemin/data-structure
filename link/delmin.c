#include "linerlink.h"
#include <stdio.h>
#include <stdlib.h>

void delmin(Node *header){
	Node *p = header->next;
	Node *pre = header;
	Node *minipre ;
	ElemType min = p->data;
	
	while(p != NULL){
		if(p->data < min){
			minipre = pre;
		}
		pre = p;
		p = p->next;
	}
	
	Node *r = minipre->next;
	minipre->next = r->next;
	free(r);
}

int main(void){
	int a[] = {7, 4, 5, 9, 3, 8};
	Node *header = (Node *)malloc(sizeof(Node));
	cp_array_link(header, a, ARRAY_LEN(a));
	
	delmin(header);
	
	print_linerlink(header);
	
	return 0;
}