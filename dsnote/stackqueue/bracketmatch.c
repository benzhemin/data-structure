#include "stackseq.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

BOOL bracket_match(char *s){
    SqStack stack;
    init_stack(&stack);
    
    int d;
    
    while (*s != '\0') {
        if (*s == '(') {
            push(&stack, *s);
        }else if (*s == ')'){
            if (stack_empty(&stack)) {
                return FALSE;
            }
            pop(&stack, &d);
        }
        s++;
    }
    
    if (stack_empty(&stack)) {
        return TRUE;
    }
    return FALSE;
}

int main(void){
    char a[] = "(a+3)-4*(3-2)";
    
    BOOL match = bracket_match(a);
    
    if (match) {
        printf("match !\n");
    }else{
        printf("doesn't match!\n");
    }
    
    return 0;
}