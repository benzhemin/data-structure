#ifndef _LINER_LINK_H
#define _LINER_LINK_H

#include "../predef.h"

typedef int ElemType;

typedef struct _Node{
	ElemType data;
	struct _Node *next;
} Node;

//get the element at index
Status get_link_elem(Node *header, int index, ElemType *e);

//insert element to linerlink
Status insert_linerlink(Node *header, int index, ElemType e);

//delete element at index
Status delete_linerlink(Node *header, int index, ElemType *e);

//create linerlink
void create_linerlink(Node **header, int n);

//merge la lb to lc
void merge_linerlink(Node *La, Node *Lb, Node **Lc);

//print all
void print_linerlink(Node *L);

#endif