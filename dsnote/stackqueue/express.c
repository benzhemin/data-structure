#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>
#include "stack_seq_generic.h"

char *operaters = "+-*/()#";

char priorities[7][7] = {
        {'>', '>', '<', '<', '<', '>', '>'},
        {'>', '>', '<', '<', '<', '>', '>'},
        {'>', '>', '>', '>', '<', '>', '>'},
        {'>', '>', '>', '>', '<', '>', '>'},
        {'<', '<', '<', '<', '<', '=', '$'},
        {'>', '>', '>', '>', '$', '>', '>'},
        {'<', '<', '<', '<', '<', '$', '='},
};

void input_express(char *a){
	int ch;
	while((ch=getchar()) != '#'){
		*a++ = (char) ch;
	}
	*a = ch;
}

char get_priority(char a, char b){
	char *pa = strchr(operaters, a);
	char *pb = strchr(operaters, b);

	assert(pa != NULL);
	assert(pb != NULL);

	return priorities[pa-operaters][pb-operaters];
}

void scan_express_num(char **pexpress, SqStack *pnumStack){
	char temp[20];
	int offset = 0;
	char *express = *pexpress;
	memset(temp, 0, sizeof(temp));

	while(isdigit(*express)){
		*(temp+offset) = *express;
		offset++;
		express++;
	}

	if (offset != 0){
		int num = 0;
		*(temp+offset) = '\0';
		offset = 0;
		num = atoi(temp);
		push(pnumStack, &num);
	}
	
	*pexpress = express;
}

char cmp_priority(char a, char b){
	char *pa = strchr(operaters, a);
    char *pb = strchr(operaters, b);
    
    assert(pa!=NULL);
    assert(pb!=NULL);
    
    return priorities[pa-operaters][pb-operaters];
}

int do_compute(char oper, int a, int b){
	int res;
	switch (oper){
		case '+':
			res = a + b;
			break;
		case '-':
			res = a - b;
			break;
		case '*':
			res = a * b;
			break;
		case '/':
			res = a / b;
			break;
		default:
			perror("operator encounter error!");
			break;
	}
	return res;
}

void evaluate(char **pexpress, char priority, SqStack *pnumStack, SqStack *psymbloStack){
	char *express = *pexpress;

	if(priority == '<'){
		push(psymbloStack, express);
		express++;
	}else if(priority == '='){
		pop(psymbloStack, NULL);
		express++;
	}else if(priority == '>'){
		int a, b;
		char oper;
		int res = 0;
		pop(pnumStack, &b);
		pop(pnumStack, &a);
		
		pop(psymbloStack, &oper);

		res = do_compute(oper, a, b);

		push(pnumStack, &res);
	}else{
		perror("encounter error!");
	}

	*pexpress = express;
}

void evaluate_express(char *express, SqStack *pnumStack, SqStack *psymbolStack){
	char def_start = '#';
	push(psymbolStack, &def_start);

	while (!stack_empty(psymbolStack) && *express!='\0'){
		char priority;
		char oper;

		scan_express_num(&express, pnumStack);

		get_top(psymbolStack, &oper);
		priority = cmp_priority(oper, *express);

		evaluate(&express, priority, pnumStack, psymbolStack);
	}
}

int main(void){
	char input[100];
	int res;

	SqStack operNumStack;
	SqStack operSymbStack;
	
	memset(input, 0, sizeof(input));
	input_express(input);

	
	init_stack(&operNumStack, sizeof(int));
	init_stack(&operSymbStack, sizeof(char));

	evaluate_express(input, &operNumStack, &operSymbStack);

	pop(&operNumStack, &res);
	printf("res:%d\n", res);

	system("pause");

	return 0;
}

