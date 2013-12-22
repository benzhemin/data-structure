#include <stdio.h>
#include <stdlib.h>
#include "link.h"

/*
    设计一个算法，将一个头节点为A的单链表（数据域为整数）分解成两个链表A和链表B，
    使得A链表只含有原来链表中data域为奇数的节点，
    B链表只含有原来链表中data域为偶数的节点，且保持原来相对顺序
 */

void split_link(Node **prootA, Node **prootB){
    Node *p = *prootA;
    //偶数链表
    Node *peven = NULL;
    Node **ppe = &peven;
    //奇数链表
    Node *podd = NULL;
    Node **ppo = &podd;
    
    int i = 1;
    while (p != NULL) {
        Node *pcur = p;
        p = p->next;
        
        pcur->next = NULL;
        if (i%2 == 1) {
            *ppo = pcur;
            ppo = &(*ppo)->next;
        }else{
            *ppe = pcur;
            ppe = &(*ppe)->next;
        }
        i++;
    }
    
    *prootB = peven;
}

int main(void){
    Node *rootA = NULL;
    Node *rootB = NULL;
    
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    cp_array_link(&rootA, a, ARRAY_LEN(a));
    print_link(rootA);
    
    split_link(&rootA, &rootB);
    print_link(rootA);
    print_link(rootB);
    
    return 0;
}