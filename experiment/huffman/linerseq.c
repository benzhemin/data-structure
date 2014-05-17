#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "linerseq.h"

SqList *create_linerseq(SqList **pl, unsigned size){
    SqList *L = malloc(sizeof(SqList));
    if (pl != NULL) {
        *pl = L;
    }
    
    init_linerseq(L, size);
    
    return L;
}

void init_linerseq(SqList *L, unsigned size){
    L->typesize = size;
    L->elem = malloc(size * LIST_INIT_SIZE);
    assert(L->elem != NULL);
    
    L->listsize = LIST_INIT_SIZE;
    L->length = 0;
}

void destory_linerseq(SqList *L){
    free(L->elem);
    free(L);
}

static void check_needs_expand(SqList *L){
    unsigned size = L->typesize;
    
    if (L->length >= L->listsize) {
        L->elem = realloc(L->elem, (L->listsize+LIST_INCREMENT)*size);
        assert(L->elem != NULL);
        
        L->listsize += LIST_INCREMENT;
    }
}

void insert_linerseq(SqList *L, void *pe){
    unsigned size = L->typesize;
    char *pelem = (char *)L->elem + L->length*size;

    check_needs_expand(L);
    
    memcpy(pelem, pe, size);
    L->length += 1;
}

void sort_linerseq(SqList *L, int (*cmp_value)(void *p1, void *p2)){
    unsigned size = L->typesize;
    
    for (int i=1; i<L->length; i++) {
        char *pa = (char *)L->elem+i*size;

        for (int j=0; j<i; j++) {
            char *pb = (char *)L->elem + j*size;
            
            if (cmp_value(pa, pb) < 0) {
                char *pt = malloc(size);
                
                memcpy(pt, pa, size);
                memmove(pb+size, pb, (i-j)*size);
                memcpy(pb, pt, size);
                
                free(pt);
            }
        }
    }
}

void print_linerseq(SqList *L, void (*visit)(int index, void *pe)){
    unsigned step = L->typesize;
    char *pe = (char *)L->elem;
    
    for (int i=1; i<=L->length; i++) {
        visit(i, pe+(i-1)*step);
    }
    
    printf("\n");
}

static void visit_elem(int index, void *p){
    int *pe = p;
    printf("%d ", *pe);
}

static int cmp_value(void *p1, void *p2){
    int *pa = p1;
    int *pb = p2;
    
    if (*pa < *pb) {
        return -1;
    }else if (*pa == *pb){
        return 0;
    }else{
        return 1;
    }
}


int test_linser_main(void){
    int a[] = {6, 8, 3, 5, 1, 10, 2};
    
    SqList *L = create_linerseq(NULL, sizeof(int));
    
    for (int i=0; i<ARRAY_LEN(a); i++) {
        insert_linerseq(L, a+i);
    }
    
    print_linerseq(L, visit_elem);
    
    sort_linerseq(L, cmp_value);
    
    print_linerseq(L, visit_elem);
    
    return 0;
}


























