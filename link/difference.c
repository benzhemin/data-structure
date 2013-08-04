#include "linerlink.h"
#include <stdio.h>
#include <stdlib.h>

/* Question description
 * LinkA, LinkB 递增有序, 元素个数分别为m,n, 求A和B的差集 A-B, 差集保存在A中
*/

//find differences and remove it from linkA
void difference_link(Node **linkA, Node **linkB){
	Node *pre_pa = *linkA;
	Node *pa = (*linkA)->next;
	Node *pb = (*linkB)->next;
	
	while(pa!=NULL && pb!=NULL){
		if(pa->data < pb->data){
			pre_pa = pa;
			pa = pa->next;
		}else if(pa->data == pb->data){
			pre_pa->next = pa->next;
			free(pa);
			pa = pre_pa->next;
		}else{
			pb = pb->next;
		}
	}
}

int main(void){
	int m, n, i, d;
	Node *linkA;
	Node *linkB;
	
	scanf("%d", &m);
	create_linerlink(&linkA, m);
	print_linerlink(linkA);
	
	scanf("%d", &n);
	create_linerlink(&linkB, n);
	print_linerlink(linkB);
	
	difference_link(&linkA, &linkB);
	print_linerlink(linkA);
	
	destory_linerlink(&linkA);
	destory_linerlink(&linkB);
	
	return 0;
}