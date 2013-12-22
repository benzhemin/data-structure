#include <stdio.h>
#include <stdlib.h>
#include "link.h"

void reverse(Node **proot){
    Node *header = NULL;
    Node *p = *proot;
    
    while (p != NULL) {
        Node *pre = p;
        p = p->next;
        
        pre->next = header;
        header = pre;
    }
    
    *proot = header;
}

int main(void){
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node *root = NULL;
    cp_array_link(&root, a, ARRAY_LEN(a));
    print_link(root);
    
    reverse(&root);
    print_link(root);
    
    return 0;
}