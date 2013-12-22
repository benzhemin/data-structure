#include <stdio.h>
#include <stdlib.h>
#include "link.h"

/*
    逆序打印单链表的数据
 */

void reverse_print(Node **proot){
    if (*proot != NULL) {
        reverse_print(&(*proot)->next);
        printf("%d ", (*proot)->data);
    }else{
        return;
    }
}

int main(void){
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node *root = NULL;
    cp_array_link(&root, a, ARRAY_LEN(a));
    print_link(root);
    
    reverse_print(&root);
    printf("\n");
    
    return 0;
}