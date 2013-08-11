#include <stdio.h>
#include <stdlib.h>

void move()

void hanoi(int n, x, y, z){
	if(n == 1){
		move(x, z);
	}else{
		hanoi(n-1, x, z, y);
		move(x, z);
		hanoi(n-1, y, x, z);
	}
}