#include <stdio.h>
#include <stdlib.h>
#include "link.h"

void reverse(Node **root){
	Node *p;
	Node *header = NULL;

	for(p=*root; p!=NULL; )
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