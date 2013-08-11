#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

Status init_stack(SqStack *S){
	ElemType *elem = (ElemType *)malloc(sizeof(ElemType)*STACK_INIT_SIZE);
	assert(elem!=NULL);
	
	S->base = S->top = elem;
	S->stacksize = STACK_INIT_SIZE;
	
	return OK;
}

void clear_stack(SqStack *S){
	S->top = S->base;
}

BOOL empty_stack(SqStack *S){
	return S->base == S->top;
}

Status get_top(SqStack *S, ElemType *e){
	if(empty_stack(S)){
		return ERROR;
	}
	
	*e = *(S->top-1);
	return OK;
}

Status push(SqStack *S, ElemType e){
	if(S->top-S->base >= S->stacksize){
		S->base = (ElemType *)realloc(S->base, (S->stacksize+STACK_INCREMENT)*sizeof(ElemType));
		assert(S->base!=NULL);
		S->top = S->base + S->stacksize;
		S->stacksize += STACK_INCREMENT;
	}
	
	*S->top++ = e;
	return OK;
}

Status pop(SqStack *S, ElemType *e){
	if(empty_stack(S)){
		return ERROR;
	}
	
	*e = *--S->top;
	return OK;
}

Status destory_stack(SqStack *S){
	free(S->base);
	
	return OK;
}
