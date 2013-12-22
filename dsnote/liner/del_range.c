#include "linerseq.h"
#include <stdio.h>
#include <stdlib.h>

/*
    给定一个算法，从一给丁的顺序表L中删除下标i到j(i<=j,包括i,j)之间的所有元素
    假设i，j都是合法的
*/

void del_range(SqList *L, int index_i, int index_j){
    ElemType *pi = L->elem + index_i -1;
    ElemType *pj = L->elem + index_j;
    ElemType *p_last = L->elem+L->length;
    
    while (pj < p_last) {
        *pi++ = *pj++;
    }
    
    L->length = L->length - (index_j-index_i+1);
}

int main(void){
    int a[] = {2, 4, 5, 5, 6, 8, 7, 9, 11};
    
    SqList la;
    init_linerseq(&la);
    cp_array_linerseq(&la, a, ARRAY_LEN(a));
    print_linerseq(&la);
    
    int i,j;
    scanf("%d%d", &i, &j);
    
    del_range(&la, i, j);
    
    print_linerseq(&la);
    
    return 0;
}