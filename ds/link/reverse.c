#include <stdio.h>
#include <stdlib.h>
#include "link.h"

void reverse(Node **proot){
	//p做向后循环
	Node *p = *proot;
	//header作为新链表头指针
	Node *header = NULL;

	while(p!=NULL){
		Node *pre = p;
		p = p->next;

		pre->next = header;
		header = pre;
	}

	*proot = header;
}

void reverse2(Node **root) {
  Node *pn = *root;
	Node *header = NULL;

  while (pn != NULL) {
    Node *cur = pn;
    pn = pn->next;
    
    *root = cur;
    cur->next = header;
		header = cur;
  }
}

int main(void){
	int a[] = {2, 4, 5, 5, 8, 9};
	Node *root = NULL;

	cp_array_link(&root, a, ARRAY_LEN(a));
	print_link(root);

	reverse2(&root);
	print_link(root);

	return 0;
}