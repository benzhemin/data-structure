#include <stdio.h>
#include <stdlib.h>
#include "link.h"

//create linerlink
void create_link(Node **header, int n){
	int d;
	while(n > 0){
		scanf("%d", &d);

		Node *new_node = (Node *)malloc(sizeof(Node));
		new_node->data = d;
		new_node->next = NULL;

		*header = new_node;
		header = &(*header)->next;

		n--;
	}
}

//cp array to link
void cp_array_link(Node **header, ElemType *array, int len){
	int i;

	for(i=0; i<len; i++){
		Node *new_node = (Node *)malloc(sizeof(Node));
		new_node->data = array[i];
		new_node->next = NULL;

		*header = new_node;
		header = &(*header)->next;
	}
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

//print all
void print_link(Node *L){
	while(L!=NULL){
		printf("%d ", L->data);
		L = L->next;
	}
	printf("\n");
}