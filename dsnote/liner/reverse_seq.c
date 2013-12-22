#include <stdio.h>
#include <stdlib.h>
#include "linerseq.h"

/*
    将顺序表中的所有元素逆置
 */

void swap(ElemType *a, ElemType *b){
    ElemType temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(SqList *L){
    ElemType *pa, *pa_last;
    pa = L->elem;
    pa_last = L->elem + L->length -1;
    
    while (pa < pa_last) {
        swap(pa++, pa_last--);
    }
}

int main(void){
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    SqList sq;
    init_linerseq(&sq);
    cp_array_linerseq(&sq, a, ARRAY_LEN(a));
    print_linerseq(&sq);
    
    reverse(&sq);
    print_linerseq(&sq);
    
    return 0;
}