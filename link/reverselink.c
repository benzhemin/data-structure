#include "linerlink.h"
#include <stdio.h>
#include <stdlib.h>

void reverse_link(Node *root){
	Node *p, *q;
	p = root->next;
	root->next = NULL;
	
	while(p != NULL){
		q = p->next;
		p->next = root->next;
		root->next = p;
		p = q;
	}
}

int main(void){
	Node *root;
	create_linerlink(&root, 5);
	
	print_linerlink(root);
	reverse_link(root);
	print_linerlink(root);
	
	destory_linerlink(&root);
	
	return 0;
}