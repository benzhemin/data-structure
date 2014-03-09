#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int operate(char operand, int a, int b){
	switch(operand){
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			return a / b;
		default:
			return -1;
	}
}

int compute(BiTree *T){
	if (T != NULL){
		
		if (T->lchild!=NULL && T->rchild!=NULL){
			int lvalue = compute(T->lchild);
			int rvalue = compute(T->rchild);

			int res = operate(T->data, lvalue, rvalue);
			return res;

		}else{
			return (int)(T->data-'0');
		}

	}else{
		return -1;
	}
}

int main(void){
    BiTree *T = NULL;
    create_bitree(&T);
    pre_order_traverse(T);
    printf("\n");
    int res = compute(T);
    printf("res:%d\n", res);
}