#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

void visit_elem(void *p){
	printf("%c ", *(char *)p);
}

int main(void){
	SqQueue *Q = create_queue_seq(NULL, sizeof(char));

	char a[] = "1234";
	char *pa = a;

	while(*pa != '\0'){
		enqueue_seq(Q, pa);
		pa++;
	}
	
	print_queue_seq(Q, visit_elem);

	while(!queue_seq_empty(Q)){
		char ch;
		dequeue_seq(Q, &ch);

		print_queue_seq(Q, visit_elem);
	}

	return 0;
}
