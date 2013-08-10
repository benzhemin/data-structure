#include "linerlink.h"
#include <stdio.h>
#include <stdlib.h>

void split_odd(Node *rootA, Node **prootB){
	//init linkB header
	Node *s = (Node *)malloc(sizeof(Node));
	s->next = NULL;
	*prootB = s;
	
	Node *pa = rootA;
	Node *pb = *prootB;
	Node *p = pa->next;
	int i = 1;
	while(p != NULL){
		if(i%2 == 0){
			pa->next = p->next;
			pa = pa->next;
			pb->next = p;
			p = p->next;
			pb = pb->next;
			pb->next = NULL;
		}else{
			pa = p;
			p = p->next;
		}
		++i;
	}
}

int main(void){
	Node *rootA, *rootB;
	create_linerlink(&rootA, 4);
	split_odd(rootA, &rootB);
	print_linerlink(rootA);	
	print_linerlink(rootB);
	
	return 0;
}