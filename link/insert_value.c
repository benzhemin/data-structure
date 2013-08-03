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

void insert_quote_value(Node **root, int value){
	Node **p = root;
	while(*p!=NULL && (*p)->data<value){
		p = &((*p)->next);
	}
	
	Node *s = (Node *)malloc(sizeof(Node));
	s->data = value;
	s->next = *p;
	*p = s;
}

int main(void){
	Node *header;
	create_linerlink(&header, 3);
	print_linerlink(header);
	
	insert_quote_value(&(header->next), 12);
	
	print_linerlink(header);
	
	return 0;
}