#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "linerseq.h"

SqList *create_linerseq(SqList **pL, unsigned size){
    SqList *L = malloc(sizeof(SqList));
    assert(L!=NULL);
    init_linerseq(L, size);
    
    if (pL != NULL) {
        *pL = L;
    }
    return L;
}

void init_linerseq(SqList *L, unsigned size){
    L->typesize = size;
    L->elem = malloc(size * LIST_INIT_SIZE);
    assert(L->elem != NULL);
    memset(L->elem, 0, size * LIST_INIT_SIZE);
    
    L->listsize = LIST_INIT_SIZE;
    L->length = 0;
}

void destory_linerseq(SqList *L){
    L->length = 0;
    free(L->elem);
    free(L);
}

void check_needs_expand(SqList *L){
    if (L->length >= L->listsize) {
        L->elem = realloc(L->elem, L->typesize*(L->listsize+LIST_INCREMENT));
        assert(L->elem != NULL);
        L->listsize += LIST_INCREMENT;
    }
}

void insert_linerseq(SqList *L, void *pe){
    unsigned step = L->typesize;
    char *pelem = (char *)L->elem + step*L->length;
    
    check_needs_expand(L);
    
    memcpy(pelem, pe, step);
    L->length += 1;
}

//insertion sort
void sort_linerseq(SqList *L, int (*cmp)(void *p1, void *p2)){
    unsigned step = L->typesize;
    char *pe = (char *)L->elem;
    
    for (int i=1; i<L->length; i++) {
        char *pa = pe + i*step;
        for (int j=0; j<i; j++) {
            char *pb = pe + j*step;
            
            if (cmp(pa, pb) < 0) {
                char *pe = malloc(sizeof(step));
                
                memcpy(pe, pa, step);
                memmove(pb+step, pb, (i-j)*step);
                memcpy(pb, pe, step);
                
                free(pe);
            }
        }
    }
}

// 1<=index<=L->length+1
bool insert_linerseq_index(SqList *L, int index, void *pe){
    if (index<1 || index>L->length+1) {
        return FALSE;
    }
    check_needs_expand(L);
    
    unsigned size = L->typesize;
    char *pend = (char *)L->elem + size*L->length;
    char *pstart = (char *)L->elem + size*(index-1);
    
    memmove(pstart+size, pstart, pend-pstart);
    memcpy(pstart, pe, size);
    
    L->length += 1;
    
    return TRUE;
}





