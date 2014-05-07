#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "huffman.h"
#include "linerseq.h"


bool increase_finding(SqList *L, char ch){
    EUnit *peu = (EUnit *)L->elem;
    for (int i=0; i<L->length; i++) {
        if ((peu+i)->ch_data == ch) {
            (peu+i)->freq++;
            return TRUE;
        }
    }
    return FALSE;
}

void process_input(SqList *L){
    char input[512] = {0};
    scanf("%s", input);
    
    for (char *ps=input; *ps!='\0'; ps++) {
        if (!increase_finding(L, *ps)) {
            EUnit unit = {*ps, 0};
            insert_linerseq(L, &unit);
        }
    }
}

void init_hufftree(HuffTreePtr pHT, SqList *L){
    //第0个节点不用 (2n-1)
    unsigned nc = L->length * 2;
    
    pHT->pnode = malloc(sizeof(HTNode) * nc);
    assert(pHT->pnode);
    pHT->length = nc;
    
    memset(pHT->pnode, 0, sizeof(HTNode)*nc);
    
    for (int i=0; i<L->length; i++) {
        (pHT->pnode+i+1)->weight = ((EUnit *)L->elem+i)->freq;
    }
}



int main(void){

    SqList *L = NULL;
    HuffTree HT;
    
    create_linerseq(&L, sizeof(EUnit));
    
    process_input(L);
    
    init_hufftree(&HT, L);
    
    
}







