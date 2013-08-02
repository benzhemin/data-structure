#include "linerlink.h"
#include <stdio.h>
#include <stdlib.h>

void insert_value(Node *p, int value){
	Node *pre = p;
	Node *cur = p->next;
	while(cur!=NULL && cur->data<value){
		pre = cur;
		cur = cur->next;
	}
	
	Node *s = (Node *)malloc(sizeof(Node));
	s->data = value;
	s->next = cur;
	pre->next = s;
}

int main(void){
	Node *header;
	create_linerlink(&header, 3);
	print_linerlink(header);
	
	insert_value(header, 12);
	
	print_linerlink(header);
	
	return 0;
}