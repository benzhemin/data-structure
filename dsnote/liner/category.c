#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linerseq.h"
/*
    有顺序表L， 将L中所有小于表头元素的整数放到前半部分，大于的整数放到后半部分
*/

void category(SqList *L){
    assert(L->length > 0);
    
    //pb向后遍历
    ElemType *pa, *pb, *p_last;
    ElemType key = *L->elem;
    pa = L->elem + 1;
    p_last = L->elem+L->length;
      
    //pa指向第一个大于elem[0]的指针
    while (pa<p_last && *pa < key) {
        pa++;
    }
    
    pb = pa+1;
    while (pb<p_last) {
        if (*pb <= key){
            ElemType v = *pb;
            
            ElemType *p = pb-1;
            while (p>=pa) {
                *(p+1) = *p;
                p--;
            }
            *pa = v;
            if (*pa < key) {
                pa++;
            }
        }
        pb++;
    }
}

int main(void){
    int a[] = {6, 9, 11, 4, 5, 8, 6, 9, 5, 6, 8, 7};
    
    SqList la;
    init_linerseq(&la);
    cp_array_linerseq(&la, a, ARRAY_LEN(a));
    print_linerseq(&la);
    
    category(&la);
    
    print_linerseq(&la);
    
    return 0;
}