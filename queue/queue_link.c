#include "queue_link.h"

Status init_queue(QueueLink *Q){
	Node *s = (Node *)malloc(sizeof(Node));
	assert(s!=NULL);
	s->next = NULL;
	
	Q->front = Q->rear = s;
	return OK;
}

Status destory_queue(QueueLink *Q){
	Node *p = Q->front;
	while(p!=NULL){
		Node *r = p;
		p = p->next;
		free(r);
	}
}

int main(void){
	
}