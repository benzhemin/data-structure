#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "huffman.h"
#include "linerseq.h"
#include "charfreq.h"
#include "cstdstring.h"

void init_huffman(HuffTreePtr *htl, SqList *L){
    HuffTreePtr htree = malloc(sizeof(HuffTree));
    assert(htree != NULL);
    *htl = htree;
    
    htree->pnodes = malloc(sizeof(HTNode) * (L->length * 2));
    htree->huffsize = L->length * 2;
    memset(htree->pnodes, 0, sizeof(HTNode) * htree->huffsize);
    
    for (int i=1; i<=L->length; i++) {
        HTNodePtr pn = htree->pnodes + i;
        HTElem *pe = (HTElem *)L->elem + (i-1);
        
        pn->elem = malloc(sizeof(HTElem));
        memcpy(pn->elem, pe, sizeof(HTElem));
    }
    
    htree->length = L->length + 1;
}

void destory_huffman(HuffTreePtr pHT){
    HTNodePtr pn = pHT->pnodes;
    while (pn < pHT->pnodes+pHT->huffsize) {
        free(pn->elem);
        pn++;
    }
    free(pHT->pnodes);
    free(pHT);
}

void print_huffman(HuffTreePtr pHT){
    HTNodePtr pn = pHT->pnodes + 1;
    while (pn < pHT->pnodes+pHT->length) {
        printf("%ld %s %c %d %d %d %d\n", (pn-pHT->pnodes), pn->hc_str,pn->elem->ch_data, pn->elem->weight, pn->parent, pn->lchild, pn->rchild);
        pn++;
    }
    printf("\n");
}

int cmp_weight(void *p1, void *p2){
    HTNodePtr pa = *(HTNodePtr *)p1;
    HTNodePtr pb = *(HTNodePtr *)p2;
    
    if (pa->elem->weight < pb->elem->weight) {
        return -1;
    }else if (pa->elem->weight == pb->elem->weight) {
        return 0;
    }else{
        return 1;
    }
}

bool select_two_minmum(HuffTreePtr pHT, HTNodePtr *pa, HTNodePtr *pb){
    bool have_two = FALSE;
    
    SqList *L = create_linerseq(NULL, sizeof(HTNodePtr));
    
    HTNodePtr pn = pHT->pnodes + 1;
    while (pn < pHT->pnodes + pHT->length) {
        if (pn->parent == 0) {
            insert_linerseq(L, &pn);
        }
        pn++;
    }
    
    sort_linerseq(L, cmp_weight);
    
    if (L->length >= 2) {
        have_two = TRUE;
        *pa = *((HTNodePtr *)L->elem);
        *pb = *((HTNodePtr *)L->elem + 1);
    }
    
    destory_linerseq(L);
    
    return have_two;
}

void traverse_hufftree(HuffTreePtr pHT, HTNodePtr pn){
    if (pn->lchild!=0 || pn->rchild!=0) {
        if (pn->lchild != 0) {
            HTNodePtr plchild = pHT->pnodes + pn->lchild;
            string *s = create_with_string(pn->hc_str);
            
            string_append(s, HUFFMAN_LEFT_BRANCH);
            string_copy(s, &plchild->hc_str);
            destory_string(s);
            
            traverse_hufftree(pHT, plchild);
        }
        
        if (pn->rchild != 0) {
            HTNodePtr prchild = pHT->pnodes + pn->rchild;
            string *s = create_with_string(pn->hc_str);
            
            string_append(s, HUFFMAN_RIGHT_BRANCH);
            string_copy(s, &prchild->hc_str);
            destory_string(s);
            
            traverse_hufftree(pHT, prchild);
        }
    }
}

void build_hufftree(HuffTreePtr pHT){
    HTNodePtr pa, pb;
    HTNodePtr proot;
    
    while (select_two_minmum(pHT, &pa, &pb)) {
        HTNodePtr pp = pHT->pnodes + pHT->length;
        pp->elem = malloc(sizeof(HTElem));
        pp->elem->weight = pa->elem->weight + pb->elem->weight;
        pp->parent = 0;
        
        pa->parent = pHT->length;
        pb->parent = pHT->length;
        
        pp->lchild = (unsigned) (pa-pHT->pnodes);
        pp->rchild = (unsigned) (pb-pHT->pnodes);
        
        pHT->length += 1;
    }
    
    proot = pHT->pnodes+pHT->length-1;
    
    traverse_hufftree(pHT, proot);
}

void decoding_hufftree(HuffTreePtr pHT){
    char buf[512] = { 0 };
    char *pb = buf;
    fgets(buf, sizeof(buf), stdin);

    HTNodePtr proot = pHT->pnodes + pHT->length-1;
    HTNodePtr pn = proot;
    while (*pb!='\n' && *pb!='\0'){
        if (pn->lchild==0 && pn->rchild==0) {
            printf("%c", pn->elem->ch_data);
            fflush(stdout);
            pn = proot;
        }
        
        if (*pb == '0') {
            pn = pHT->pnodes + pn->lchild;
        }
        if (*pb == '1') {
            pn = pHT->pnodes + pn->rchild;
        }
        pb++;
    }
}

int main(void){
    SqList *L = create_linerseq(NULL, sizeof(HTElem));
    HuffTreePtr pHT;
    
    apperance_freq(L);
    
    init_huffman(&pHT, L);
    
    build_hufftree(pHT);
    
    print_huffman(pHT);
    
    decoding_hufftree(pHT);
    
    destory_huffman(pHT);
    destory_linerseq(L);
    
    return 0;
}















