#ifndef _LINER_LINK_H
#define _LINER_LINK_H

#include "../predef.h"

typedef int ElemType;

typedef struct _Node{
	ElemType data;
	struct _Node *next;
} Node;

//create linerlink
void create_link(Node **header, int n);

//copy array to link
void cp_array_link(Node **header, ElemType *array, int len);

//print all
void print_link(Node *L);

//destroy link
void destroy_link(Node *L);

#endif