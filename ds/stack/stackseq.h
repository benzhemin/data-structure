#ifndef _STACKSEQ_H
#define _STACKSEQ_H

#include "../predef.h"

#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10

typedef int ElemType;

typedef struct{
	ElemType *base;
	ElemType *top;
	int stacksize;
}SqStack;

Status init_stack(SqStack *s);

BOOL stack_empty(SqStack *s);

Status get_top(SqStack *s, ElemType *e);

Status push(SqStack *s, ElemType e);

Status pop(SqStack *s, ElemType *e);


#endif