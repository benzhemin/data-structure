#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "stack_seq_generic.h"

#define QUEEN 4

typedef struct{
    int x;
    int y;
} Point;

BOOL in_border(int x){
    if (x>=0 && x<QUEEN) {
        return TRUE;
    }
    return FALSE;
}

BOOL can_place(SqStack *s, Point *p){
    Point *top = (Point *)s->top;
    Point *base = (Point *)s->base;
    
    if (!in_border(p->x) || !in_border(p->y)) {
        return FALSE;
    }
    
    while (base < top) {
        int x_dif = abs(p->x - base->x);
        int y_dif = abs(p->y - base->y);
        
        if (base->y==p->y || x_dif==y_dif) {
            return FALSE;
        }
        base++;
    }
    return TRUE;
}

static int count = 0;

void print_queens(SqStack *s){
    Point *top = s->top;
    Point *base = s->base;
    
    char area[QUEEN][QUEEN] = {0};
    memset(area, '*', sizeof(char)*QUEEN*QUEEN);
    
    if (top - base >= QUEEN) {
        while (base < top) {
            area[base->x][base->y] = '#';
            base++;
        }
        
        int i,j;
        for (i=0; i<QUEEN; i++) {
            for (j=0; j<QUEEN; j++) {
                printf("%c ", area[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        
        count++;
    }
    
}

void queens_recursion(SqStack *s, Point p){
    if (can_place(s, &p)) {
        push(s, &p);
        print_queens(s);
        Point next = {p.x+1, 0};
        queens_recursion(s, next);
    }else{
        if (stack_empty(s)) {
            return;
        }
        
        if (!in_border(p.y) || !in_border(p.x)){
        	pop(s, &p);
        	Point next = {p.x, p.y+1};
        	queens_recursion(s, next);
        }else{
        	Point next = {p.x, p.y+1};
        	queens_recursion(s, next);
        }
        
    }
}

int main(void){
    SqStack stack;
    init_stack(&stack, sizeof(Point));
    
    //queens(&stack);
    Point p = {0, 0};
    queens_recursion(&stack, p);

    printf("total:%d\n", count);
    
    return 0;
}