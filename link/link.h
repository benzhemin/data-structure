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

//在单链表中第i个位置之前插入元素e
Status insert_index_link(Node **root, int index, ElemType e);

//删除第i个元素
Status delete_index_link(Node **root, int index, ElemType *e);

//get elem at index
Status elem_at_index(Node *L, int index,  ElemType *e);

//print all
void print_link(Node *L);

//destroy link
void destroy_link(Node *L);

#endif