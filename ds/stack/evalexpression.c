//
//  express.c
//  DS
//
//  Created by peer on 1/9/14.
//  Copyright (c) 2014 peer. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include "stack_seq_generic.h"

#define INPUT_MAX_SIZE 1000

char *validstr = "+-*/()#";

char priorities[7][7] = {
	{'>', '>', '<', '<', '<', '>', '>'},
	{'>', '>', '<', '<', '<', '>', '>'},
	{'>', '>', '>', '>', '<', '>', '>'},
	{'>', '>', '>', '>', '<', '>', '>'},
	{'<', '<', '<', '<', '<', '=', '$'},
	{'>', '>', '>', '>', '$', '>', '>'},
	{'<', '<', '<', '<', '<', '$', '='},
};

void input_express(char *input){
    int ch;
    while ((ch=getchar()) != '#') {
        *input++ = (char) ch;
    }
    *input++ = ch;
}

char get_priority(char a, char b){
    char *pa = strchr(validstr, a);
	char *pb = strchr(validstr, b);
    
	assert(pa!=NULL);
	assert(pb!=NULL);
    
	return priorities[pa-validstr][pb-validstr];
}

int do_compute(char symbol, int a, int b){
	int res = 0;
	switch(symbol){
		case '+':
			res = a+b;
			break;
		case '-':
			res = a-b;
			break;
		case '*':
			res = a * b;
			break;
		case '/':
			res = a / b;
			break;
		default:
			printf("do_compute encount error!");
			break;
	}
	return res;
}

//将数字压栈
void push_operand(SqStack *pnumStack, char **pexpress){
    char temp[20];
    int offset = 0;
    char *exp = *pexpress;
    
    while (isdigit(*exp)) {
        *(temp + offset) = *exp;
        offset++;
        exp++;
    }
    
    if (offset != 0) {
        *(temp + offset) = '\0';
        offset = 0;
        int num = atoi(temp);
        push(pnumStack, &num);
    }
    *pexpress = exp;
}

void evaluate_express(char *express, SqStack *pnumStack, SqStack *poperStack){
    char def_start = '#';
    push(poperStack, &def_start);
    
    
    while (!stack_empty(poperStack) && *express != '\0') {
        
        push_operand(pnumStack, &express);
        
        int ch;
        get_top(poperStack, &ch);
        char priority = get_priority(ch, *express);
        
        if (priority == '<') {
            push(poperStack, express);
            express++;
        }else if (priority == '='){
            pop(poperStack, NULL);
            express++;
        }else if (priority == '>'){
            int opnum1, opnum2;
            pop(pnumStack, &opnum1);
            pop(pnumStack, &opnum2);
            
            pop(poperStack, &ch);
            
            int res = do_compute(ch, opnum2, opnum1);
            
            push(pnumStack, &res);
        }
    }
}

int main(void){
    char input[INPUT_MAX_SIZE];
    memset(input, 0, sizeof(input));
    input_express(input);
    
    SqStack numStack;
    init_stack(&numStack, sizeof(int));
    
    SqStack operStack;
    init_stack(&operStack, sizeof(char));
    
    evaluate_express(input, &numStack, &operStack);
    
    int res ;
    pop(&numStack, &res);
    
    printf("res:%d\n", res);
    
    return 0;
}















