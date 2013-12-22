#include <stdio.h>
#include <stdlib.h>
#include "link.h"

/*
    有一个递增非空单链表，设计一个算法删除值域重复的节点，
    比如{1, 1, 2, 3, 3, 3, 4, 4, 7, 7, 7, 9, 9, 9}经过删除后变成
    {1, 2, 3, 4, 7, 9}
*/

void rm_duplicate(Node **proot){
    Node *p;
    while(*proot != NULL){

        p=(*proot)->next;
        while (p!=NULL && p->data==(*proot)->data){
            Node *temp = p;
            (*proot)->next = p->next;
            p = p->next;
            free(temp);
        }

        proot = &(*proot)->next;
    }
}

int main(void){
    int a[] = {1, 1, 2, 3, 3, 3, 4, 4, 7, 7, 7, 9, 9, 9};
    
    Node *root;
    cp_array_link(&root, a, ARRAY_LEN(a));
    print_link(root);
    
    rm_duplicate(&root);
    print_link(root);

    destroy_link(root);
    
    return 0;
}