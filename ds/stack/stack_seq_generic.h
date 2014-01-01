#ifndef _STACK_SEQ_GENERIC_H
#define _STACK_SEQ_GENERIC_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "predef.h"

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef void (*print_method)(void *p);

typedef struct {
	void *base;
	void *top;
	unsigned typesize;
	int stacksize;
}SqStack;

Status init_stack(SqStack *s, unsigned typesize);

Status destory_stack(SqStack *s);

BOOL stack_empty(SqStack *s);

Status get_top(SqStack *s, void *elem);

Status push(SqStack *s, void *elem);

Status pop(SqStack *s, void *elem);

void print_stack(SqStack *s, print_method pm);

#endif