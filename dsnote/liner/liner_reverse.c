#include <stdio.h>
#include <stdlib.h>
#include "linerseq.h"

/*
	设计一个算法，将顺序表中的所有元素逆置
*/

void swap(ElemType *a, ElemType *b){
    ElemType temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(SqList *L){
    ElemType *pa = L->elem;
    ElemType *pa_last = L->elem+L->length-1;
    
    while (pa < pa_last) {
        swap(pa, pa_last);
        pa++;
        pa_last--;
    }
}

int main(void){
    int a[] = {2, 4, 5, 7, 9, 11};
    
    SqList la;
    init_linerseq(&la);
    cp_array_linerseq(&la, a, ARRAY_LEN(a));
    print_linerseq(&la);
    
    reverse(&la);
    print_linerseq(&la);
    
    
    return 0;
}

