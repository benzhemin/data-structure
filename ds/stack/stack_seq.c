#include <stdio.h>
#include <stdlib.h>
#include "stack_seq.h"

Status init_stack(SqStack *s){
	s->base = (ElemType *)malloc(sizeof(ElemType) * STACK_INIT_SIZE);
	assert(s->base!=NULL);
	s->top = s->base;
	s->stacksize = STACK_INIT_SIZE;

	return OK;
}

void destory_stack(SqStack *s){
	free(s->base);
	s->base = s->top = NULL;
	s->stacksize = 0;
}

BOOL stack_empty(SqStack *s){
	return s->top == s->base;
}

Status get_top(SqStack *s, ElemType *e){
	if (stack_empty(s)){
		return ERROR;
	}
	*e = *(s->top-1);
	return OK;
}

Status push(SqStack *s, ElemType e){
	if (s->top-s->base >= s->stacksize){
		s->base = (ElemType *)realloc(s->base, sizeof(ElemType)*(s->stacksize+STACK_INCREMENT));
		assert(s->base!=NULL);
		s->top = s->base+s->stacksize;
		s->stacksize += STACK_INCREMENT;
	}

	*s->top++ = e;

	return OK;
}

Status pop(SqStack *s, ElemType *e){
	if (stack_empty(s)){
		return ERROR;
	}
	*e = *--s->top;
	return OK;
}
