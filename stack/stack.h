#ifndef _STACK_H
#define _STACK_H

#include "../predef.h"

#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10

//typedef int ElemType;
typedef enum _Di{
	Right = 0,
	Down,
	Left,
	Up,
	Di_UnDef,
} Di;

typedef struct _Point{
	int row;
	int col;
	Di di;
} Point;

typedef Point ElemType;

typedef struct{
	ElemType *top;
	ElemType *base;
	int stacksize;
} SqStack;

Status init_stack(SqStack *S);

Status empty_stack(SqStack *S);

void clear_stack(SqStack *S);

ElemType get_top(SqStack *S);

ElemType pop(SqStack *S);

Status push(SqStack *S, ElemType e);

Status destory_stack(SqStack *S);

#endif