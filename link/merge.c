#include <stdio.h>
#include <stdlib.h>
#include "link.h"

void merge_list(Node *la, Node *lb, Node **lc){
	while(la!=NULL && lb!=NULL){
		if(la->data < lb->data){
			*lc = la;
			lc = &la->next;
			la = la->next;
		}else{
			*lc = lb;
			lc = &lb->next;
			lb = lb->next;
		}
	}

	if(la!=NULL){
		*lc = la;
	}

	if(lb!=NULL){
		*lc = lb;
	}
}

int main(void){
	int a1[] = {2, 4, 5, 7, 9, 11};
	int a2[] = {1, 2, 4, 5, 6, 9, 10};

	Node *la, *lb, *lc;

	cp_array_link(&la, a1, ARRAY_LEN(a1));
	cp_array_link(&lb, a2, ARRAY_LEN(a2));

	print_link(la);
	print_link(lb);

	merge_list(la, lb, &lc);

	print_link(lc);

	destroy_link(lc);

	return 0;
}