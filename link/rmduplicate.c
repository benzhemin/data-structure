/*
 * 有一个递增非空单链表,设计一个算法删除数据域重复的节点
 * {1,1,2,3,3,3,4,4,7,7,7,9,9,9} 变为{1,2,3,4,7,9}
*/

#include "linerlink.h"
#include <stdio.h>
#include <stdlib.h>

void rmduplicate(Node *header){
	Node *p = header->next;
	Node *q;
	while(p!=NULL){
		ElemType data = p->data;
		q = p->next;
		while(q!=NULL && q->data==data){
			Node *r = q;
			q = q->next;
			free(r);
		}
		p->next = q;
		p = p->next;
	}
}

int main(void){
	int a[] = {1, 1, 2, 3, 3, 3, 4, 4, 7, 7, 7, 9, 9, 9};
	Node *header = (Node *)malloc(sizeof(Node));
	cp_array_link(header, a, ARRAY_LEN(a));
	
	rmduplicate(header);
	
	print_linerlink(header);
	return 0;
}
