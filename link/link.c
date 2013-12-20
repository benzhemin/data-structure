#include <stdio.h>
#include <stdlib.h>
#include "link.h"

//create linerlink
void create_link(Node **root, int n){
	int d;
	while(n > 0){
		scanf("%d", &d);

		Node *new_node = (Node *)malloc(sizeof(Node));
		new_node->data = d;
		new_node->next = NULL;

		*root = new_node;
		root = &(*root)->next;

		n--;
	}
}

//cp array to link
void cp_array_link(Node **root, ElemType *array, int len){
	int i;

	for(i=0; i<len; i++){
		Node *new_node = (Node *)malloc(sizeof(Node));
		new_node->data = array[i];
		new_node->next = NULL;

		*root = new_node;
		root = &(*root)->next;
	}
}

//在单链表中第i个位置之前插入元素e
Status insert_index_link(Node **root, int index, ElemType e){
	int i = 1;
	while(*root!=NULL && i<index){
		root = &(*root)->next;
		i++;
	}

	//在最后节点插入或index<1
	if(*root==NULL || i>index){
		return ERROR;
	}

	Node *new_node = (Node *)malloc(sizeof(Node));
	new_node->data = e;

	new_node->next = *root;
	*root = new_node;

	return OK;
}

//删除第i个元素并返回删除的值
Status delete_index_link(Node **root, int index, ElemType *e){
	int i = 1;
	while(*root!=NULL && i<index){
		root = &(*root)->next;
		i++;
	}

	if(*root==NULL || i>index){
		return ERROR;
	}

	Node *p = *root;
	*e = p->data;
	*root = p->next;
	free(p);

	return OK;
}

//get elem at index
Status elem_at_index(Node *L, int index,  ElemType *e){
	int i = 1;
	while(L!=NULL && i<index){
		L=L->next;
		i++;
	}

	if(L==NULL){
		return ERROR;
	}

	*e = L->data;
	return OK;
}

//print all
void print_link(Node *L){
	while(L!=NULL){
		printf("%d ", L->data);
		L = L->next;
	}
	printf("\n");
}

//destroy link
void destroy_link(Node *L){
	Node *p;
	while(L!=NULL){
		p = L;
		L = L->next;
		free(p);
	}
}