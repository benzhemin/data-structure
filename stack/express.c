#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "stack.h"

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

//make sure input end with char #
void input_express(char *a){
	int c;
	while((c=getchar())!='#'){
		*a++ = c;
	}
	*a = c;
}

char get_priority(char a, char b){
	char *pa = strchr(validstr, a);
	char *pb = strchr(validstr, b);
	-
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

void evaluate_express(char *a, SqStack *s_symbol, SqStack *s_number){
	push(s_symbol, '#');
	
	int offset = 0;
	char temp[20];
	char c;
	char *pc;
	while(!empty_stack(s_symbol)){
		c = *a;
		if(isdigit(c)){
			++a;
			++offset;
		}else if(strchr(validstr, c)!=NULL){
			if(offset != 0){
				strncpy(temp, a-offset, offset);
				temp[offset] = '\0';
				push(s_number, atoi(temp));
				offset = 0;
			}
			
			char c_priority = get_priority(get_top(s_symbol), c);
			
			if(c_priority == '>'){
				int a = pop(s_number);
				int b = pop(s_number);
				char symbol = pop(s_symbol);
				//push result
				push(s_number, do_compute(symbol, b, a));
			}
			//Ɵ1 < Ɵ2
			else if(c_priority == '<'){
				a++;
				push(s_symbol, c);
			}
			//Ɵ1 == Ɵ2
			else if(c_priority == '='){
				a++;
				pop(s_symbol);
			}else{
				printf("undefined priority!");
			}
				
		}else{
			printf("encounter unrecognized character\n");
		}
	}
}

int main(void){
	char a[INPUT_MAX_SIZE];
	memset(a, 0, sizeof(a));
	
	input_express(a);
	
	SqStack stack_symbol;
	init_stack(&stack_symbol);
	
	SqStack stack_number;
	init_stack(&stack_number);
	
	evaluate_express(a, &stack_symbol, &stack_number);
	
	int res = pop(&stack_number);
	printf("res is %d\n", res);
	
	return 0;
}
