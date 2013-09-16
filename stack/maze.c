/*
	迷宫求解
*/

#include <stdio.h>
#include "stack.h"

int maze[9][10] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 1, 0, 1, 1, 1, 0, 1, 0},
	{0, 1, 1, 0, 1, 1, 1, 0, 1, 0},
	{0, 1, 1, 1, 1, 0, 0, 1, 1, 0},
	{0, 1, 0, 0, 0, 1, 1, 1, 1, 0},
	{0, 1, 1, 1, 0, 1, 1, 1, 1, 0},
	{0, 1, 0, 1, 1, 1, 0, 1, 1, 0},
	{0, 0, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

static SqStack stack;

BOOL reach_end(Point p){
	int total = sizeof(maze)/sizeof(maze[0][0]);
	int rows = sizeof(maze)/sizeof(maze[0]);
	int cols = total / rows;
	
	if(p.row==rows-2 && p.col==cols-2){
		return TRUE;
	}
	return FALSE;
}

BOOL has_visited(Point p){
	ElemType *top = stack.top;
	while(top != stack.base){
		Point curp = *(--top);
		if(curp.row == p.row && curp.col == p.col){
			return TRUE;
		}
	}
	return FALSE;
}

BOOL find_next_point(Point p, Point *nextPoint){
	Point nextp = p;
	switch(p.di){
		case Right:
			++nextp.col;
			break;
		case Down:
			++nextp.row;
			break;
		case Left:
			--nextp.col;
			break;
		case Up:
			--nextp.row;
			break;
		case Di_UnDef:
			return FALSE;
	}
	if(maze[nextp.row][nextp.col] == 1 && !has_visited(nextp)){
		nextPoint->row = nextp.row;
		nextPoint->col = nextp.col;
		nextPoint->di = Right;
		
		return TRUE;
	}else{
		p.di++;
		return find_next_point(p, nextPoint);
	}
}

void print_path(){
	ElemType *base = stack.base;
	printf("path======================================\n");
	while(base != stack.top){
		Point p = *base;
		printf("%d, %d\n", p.row, p.col);
		++base;
	}
}

void find_way_out(){
	Point start = {1, 1, Right};

	init_stack(&stack);
	push(&stack, start);
	
	Point nextp;
	while(!empty_stack(&stack) && !reach_end(get_top(&stack))){
		Point p = get_top(&stack);
		if(find_next_point(p, &nextp)){
			push(&stack, nextp);
			printf("%d, %d\n", nextp.row, nextp.col);
		}else{
			pop(&stack);
			//栈的top节点要变换方向,因为上一个方向是一条死路
			if(!empty_stack(&stack)){
				(*(stack.top-1)).di++;
			}
		}
	}
	
	print_path();
	
	destory_stack(&stack);
}

int main(void){
	
	find_way_out();
	
	return 0;
}