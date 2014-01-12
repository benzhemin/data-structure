/*
	迷宫求解
*/

#include <stdio.h>
#include "stack_seq_generic.h"

typedef enum{
	di_right = 0,
	di_down,
	di_left,
	di_up,
    di_end,
} Direction;

typedef struct{
	int x;
	int y;
} Coordi;

typedef struct{
	Coordi coordi;
	Direction di;
} Point;

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

Coordi start = {1, 1};
Coordi end = {8, 7};


BOOL reach_end(SqStack *s){
    Point p;
    if (!stack_empty(s)) {
        get_top(s, &p);
        if (p.coordi.x==end.x && p.coordi.y==end.y) {
            return TRUE;
        }
    }
    return FALSE;
}

BOOL point_equal(Point *a, Point *b){
	if (a->coordi.x==b->coordi.x && a->coordi.y==b->coordi.y) {
		return TRUE;
	}
	return FALSE;
}

BOOL stack_has_point(SqStack *stack, Point *p){
	Point *base = (Point *)stack->base;
	Point *top = (Point *)stack->top;

	while(base < top){
		if (point_equal(base, p)){
			return TRUE;
		}

		base++;
	}
	return FALSE;
}

BOOL can_step_next(SqStack *stack, Point *pnext){
	Point cur;

	get_top(stack, &cur);

	while(cur.di != di_end){
		Point next = {0};
		next.coordi = cur.coordi;

		switch(cur.di){
			case di_right:
				next.coordi.x++;
				break;
			case di_down:
				next.coordi.y++;
				break;
			case di_left:
				next.coordi.x--;
				break;
			case di_up:
				next.coordi.y--;
				break;
            default:
                perror("direction error");
                break;
		}

		if (maze[next.coordi.y][next.coordi.x]!=0 && !stack_has_point(stack, &next)){
			//修改栈顶方向
			Point *top = (Point *)stack->top - 1;
            top->di = cur.di;

			*pnext = next;
			return TRUE;
		}

		cur.di++;
	}

	return FALSE;
}

void print_path(SqStack *s){
	Point *base = (Point *)s->base;
	Point *top = (Point *)s->top;
    
	int row = sizeof(maze)/sizeof(maze[0]);
    int col = sizeof(maze[0])/sizeof(maze[0][0]);
    
    char *area = (char *)malloc(sizeof(row*col*(sizeof(char))));
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            *(area+(i*col)+j) = '0' + maze[i][j];
        }
    }
    
    while (base < top) {
        Coordi coodi = base->coordi;
        *(area+coodi.y*col+coodi.x) = '*';
        base++;
    }
    
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            printf("%c, ", *(area+i*col+j));
        }
        printf("\n");
    }
    printf("\n");
    
    free(area);
}

void find_way_out(SqStack *stack){
    Point p = {start, di_right};
    push(stack, &p);
    
    while (!stack_empty(stack) && !reach_end(stack)) {
        Point next = {0};

        if (can_step_next(stack, &next)){
        	push(stack, &next);
            
            print_path(stack);
        }
        else{
        	pop(stack, NULL);
            
        	if (!stack_empty(stack))
        	{
                //修改栈顶方向
                Point *top = (Point *)stack->top - 1;
                top->di++;
        	}
            
            print_path(stack);
        }
    }
}

int main(void){
    SqStack s;
    init_stack(&s, sizeof(Point));
    
	find_way_out(&s);

	print_path(&s);

	return 0;
}



