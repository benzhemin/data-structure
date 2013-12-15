#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void init_stack(SqStack *s){
	s->base = (void **) malloc(sizeof(void *) * STACK_INIT_SIZE);
	if(!s->base){
		exit(OVERFLOW);
	}
	
	s->top = s->base;
	s->stack_size = STACK_INIT_SIZE;
}

BOOL stack_empty(SqStack *s){
	if(s->base == s->top){
		return TRUE;
	}
	return FALSE;
}

void push(SqStack *s, void *elem){
	if(s->top-s->base >= s->stack_size){
		s->base = (void **) realloc(s->base, (s->stack_size+STACK_INCREMENT) * sizeof(void *));
		if(!s->base){
			exit(OVERFLOW);
		}
		s->top = s->base + s->stack_size;
		s->stack_size += STACK_INCREMENT;
	}
	*s->top++ = elem;
}

BOOL pop(SqStack *s, void **elem){
	if(stack_empty(s)){
		return ERROR;
	}
	*elem = *(--s->top);
	return TRUE;
}

BOOL get_top(SqStack *s, void **elem){
	if(stack_empty(s)){
		return ERROR;
	}
	*elem = *(s->top-1);
	return TRUE;
}

void destory_stack(SqStack *s){
	free(s->base);
	s->base = s->top = NULL;
}