#include "stack_seq_generic.h"

Status init_stack(SqStack *s, unsigned typesize){
    s->typesize = typesize;
    s->base = malloc(sizeof(s->typesize)*STACK_INIT_SIZE);
    assert(s->base!=NULL);
    
    s->top = s->base;
    s->stacksize = STACK_INIT_SIZE;
    
    return OK;
}

Status destory_stack(SqStack *s){
    free(s->base);
    return OK;
}

BOOL stack_empty(SqStack *s){
    return s->top == s->base;
}

Status get_top(SqStack *s, void *elem){
    if (stack_empty(s)) {
        return ERROR;
    }
    
    char *top_elem = (char *)s->top - s->typesize;
    memcpy(elem, top_elem, s->typesize);
    return OK;
}

Status push(SqStack *s, void *pelem){
    if (((char *)s->top-(char *)s->base)/s->typesize >= s->stacksize) {
        s->base = realloc(s->base, s->typesize*(s->stacksize+STACKINCREMENT));
        assert(s->base);
        s->top = s->base + s->stacksize*s->typesize;
        s->stacksize += STACKINCREMENT;
    }
    
    memcpy(s->top, pelem, s->typesize);
    s->top = (char *)s->top + s->typesize;
    return OK;
}

Status pop(SqStack *s, void *elem){
    if (stack_empty(s)) {
        return ERROR;
    }
    
    s->top = (char *)s->top - s->typesize;
    if (elem != NULL) {
        memcpy(elem, s->top, s->typesize);
    }
    return OK;
}

void print_stack(SqStack *s, print_method pm){
    char *base = s->base;
    char *top = s->top;
    
    while (base < top) {
        pm(base);
        base = base + s->typesize;
    }
    printf("\n");
}