#include <stdlib.h>
#include <stdio.h>
#include "queue_link.h"

int main(void){
    int a[] = {1, 2, 3, 4, 5};
    
    QueueLink queue;
    init_queue(&queue);
    for (int i=0; i<ARRAY_LEN(a); i++) {
        enqueue(&queue, a[i]);
    }
    print_queue(&queue);
    
    int d;
    while (scanf("%d", &d) != -1) {
        if (dequeue(&queue, &d) != OK) {
            printf("empty queue!");
            continue;
        }
        printf("delete %d\n", d);
        print_queue(&queue);
    }
    
    return 0;
}