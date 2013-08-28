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

ElemType get_top(SqStack *S){
	assert(!empty_stack(S));
	
	return *(S->top-1);
}

ElemType pop(SqStack *S){
	assert(!empty_stack(S));
	
	return *(--S->top);
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

Status destory_stack(SqStack *S){
	free(S->base);
	
	return OK;
}
