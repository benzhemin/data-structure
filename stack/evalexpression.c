/*
	Evaluate Expression
*/
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define EXPRESSION_MAX_LEN 100

typedef enum{
	add = 0,	// +	
	sub,		// -
	mul,		// *
	div,		// /
	lbrac,		// (
	rbrac,		// )
	pondkey,  	// #
	signlen		// 符号长度
} signsymbol;

typedef enum{
	greater = 1,	// >
	equal,			// =
	less,			// <
	undef,			// undefine
} cmpres;

int priority[signlen][signlen] = {
	{greater,greater,less,less,less,greater,greater},
	{greater,greater,less,less,less,greater,greater},
	{greater,greater,greater,greater,less,greater,greater},
	{greater,greater,greater,greater,less,greater,greater},
	{less,less,less,less,less,equal,undef},
	{greater,greater,greater,greater,undef,greater,greater},
	{less,less,less,less,less,undef,equal}
};

void input_express(char *a){
	int index = 0;
	int ch;
	
	while((ch=getchar())!=EOF && ch!='\n'){
		*(a+index) = (char)ch;
		++index;
	}
}

//operand 操作数
//operator 操作符
void value_express(char *a, SqStack *operand, SqStack *operator){
	int index = 0;
	push(operator, '#');
	
	
}

int main(void){
	char a[EXPRESSION_MAX_LEN];
	
	input_express(a, &len);
	
	//操作数 
	SqStack operand_stack; 
	init_stack(&operand_stack);
	//操作符
	SqStack operator_stack;
	init_stack(&operator_stack);
	
	value_express(a, &operand_stack, &operator_stack);
	
	
	return 0;
}

