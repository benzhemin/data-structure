#include "linerlink.h"
#include <stdio.h>
#include <stdlib.h>

Status get_link_elem(Node *header, int index, ElemType *e){
	Node *p = header->next;
	int j = 1;
	while(p!=NULL && j<index){
		p = p->next;
		j++;
	}
	if(p!=NULL){
		*e = p->data;
		return OK;
	}
	return ERROR;
}

Status insert_linerlink(Node *header, int index, ElemType e){
	int i=1;
	Node *p = header;
	while(p!=NULL && i<index){
		header = header->next;
		i++;
	}
	
	if(p==NULL || i>index){
		return ERROR;
	}
	
	Node *s = (Node *)malloc(sizeof(Node));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;	
}

Status delete_linerlink(Node *header, int index, ElemType *e){
	int j=1;
	Node *p = header;
	
	while(p!=NULL && j<index){
		p=p->next; 
		j++;
	}
	
	if(p==NULL || j>index){
		return ERROR;
	}
	
	Node *q = p->next;
	*e = q->data;
	p->next = q->next;
	free(q);
	
	return OK;
}

void create_linerlink(Node **header, int n){
	Node *s = (Node *)malloc(sizeof(Node));
	s->next = NULL;
	*header = s;
	Node *tail = *header;
	
	int i, d;
	for(i=0; i<n; i++){
		scanf("%d", &d);
		Node *p = (Node *)malloc(sizeof(Node));
		p->next = NULL;
		p->data = d;
		
		tail->next = p;
		tail = p;
	}
}

void create_reverse_linerlink(Node **header, int n){
	Node *s = (Node *)malloc(sizeof(Node));
	s->next = NULL;
	*header = s;
	
	int i;
	for(i=0; i<n; i++){
		Node *p = (Node *)malloc(sizeof(Node));
		scanf("%d", &p->data);
		p->next = s->next;
		s->next = p;
	}
}

void merge_linerlink(Node *La, Node *Lb, Node **Lc){
	Node *pa = La->next;
	Node *pb = Lb->next;
	Node *pc;
	*Lc = pc = La;
	while(pa!=NULL && pb!=NULL){
		if(pa->data < pb->data){
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}else{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	
	pc->next = pa!=NULL ? pa:pb;
	
	free(Lb);
}

void print_linerlink(Node *L){
	Node *p = L->next;
	
	while(p!=NULL){
		printf("%d ", p->data);
		p = p->next;
	}
	
	printf("\n");
}

/*
void destory_linerlink(Node *header){
	while(header != NULL){
		Node *p = header;
		header = header->next;
		free(p);
	}
}
*/

//invoke destory_linerlink(&header);
void destory_linerlink(Node **root){
	Node *fp, *p;
	p = *root;
	while(p!=NULL){
		fp = p;
		p = p->next;
		free(fp);
	}
	*root = NULL;
}