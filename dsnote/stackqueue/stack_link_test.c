//
//  stack_link_test.c
//  DS
//
//  Created by peer on 12/28/13.
//  Copyright (c) 2013 peer. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "stack_link.h"

int main(void){
    Node *stack = NULL;
    init_stack(&stack);
    
    int a[] = {1, 2, 3, 4, 5, 6};
    
    for (int i=0; i<ARRAY_LEN(a); i++) {
        push(&stack, a[i]);
        print_stack(stack);
    }
    
    int d;
    while (scanf("%d", &d) != -1) {
        if (!stack_empty(stack)) {
            pop(&stack, &d);
            print_stack(stack);
        }else{
            printf("empty stack!!");
            break;
        }
    }
    
    return 0;
}
