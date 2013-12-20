#include <stdio.h>
#include <stdlib.h>
#include "link.h"

void reverse(Node **proot){
	Node *p = *proot;
	Node *header = NULL;

	while(p!=NULL){
		Node *pre = p;
		p = p->next;

		pre->next = header;
		header = pre;
	}

	*proot = header;
}

int main(void){
	int a[] = {2, 4, 5, 5, 8, 9};
	Node *root = NULL;

	cp_array_link(&root, a, ARRAY_LEN(a));
	print_link(root);

	reverse(&root);
	print_link(root);

	return 0;
}