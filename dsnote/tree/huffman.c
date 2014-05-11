#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "huffman.h"
#include "linerseq.h"

bool increase_finding(SqList *L, char ch){
    bool found = FALSE;
    EUnit *pe = (EUnit *)L->elem;
    EUnit *pe_end = (EUnit *)L->elem+L->length;
    for (; pe<pe_end; pe++) {
        if (pe->ch_data == ch) {
            pe->freq++;
            found = TRUE;
            break;
        }
    }
    return found;
}

void process_input(SqList *L){
    char input[512] = {0};
    fgets(input, 512, stdin);
    
    for (char *p=input; *p!='\n'&&*p!='\0'; p++) {
        if (!increase_finding(L, *p)) {
            EUnit unit = {*p, 1};
            insert_linerseq(L, &unit);
        }
    }
}

void print_Liner(SqList *L, void (*print_elem)(int index, void *p)){
    unsigned step = L->typesize;
    char *pe = (char *)L->elem;
    char *pe_end = (char *)L->elem + L->length*step;
    
    for (int i=1; pe<pe_end; pe=pe+step, i++) {
        print_elem(i, pe);
    }
    printf("\n");
}

void init_hufftree(HuffTreePtr pHT, SqList *L){
    //-------for test-------
    /*
    L->length = 0;
    EUnit testdata[] = {
        {'a', 5}, {'b', 29}, {'c', 7}, {'d', 8}, {'e', 14}, {'f', 23}, {'g', 3}, {'h', 11}
    };
    for (int i=0; i<sizeof(testdata)/sizeof(testdata[0]); i++) {
        insert_linerseq(L, testdata+i);
    }
     */
    //-------for test-------
    
    //第0个节点不用 (2n-1)
    unsigned nc = L->length * 2;
    
    pHT->pnode = malloc(sizeof(HTNode) * nc);
    assert(pHT->pnode);
    pHT->huffsize = nc;
    pHT->length = 0;
    
    memset(pHT->pnode, 0, sizeof(HTNode)*nc);
    
    for (int i=0; i<L->length; i++) {
        (pHT->pnode+i+1)->elem.weight = ((EUnit *)L->elem+i)->freq;
        (pHT->pnode+i+1)->elem.ch_data = ((EUnit *)L->elem+i)->ch_data;
    }
    pHT->length = L->length;
}

int cmp_value(void *pa, void *pb){
    HTNodePtr pa_n = *(HTNodePtr *) pa;
    HTNodePtr pb_n = *(HTNodePtr *) pb;

    if (pa_n->elem.weight < pb_n->elem.weight) {
        return -1;
    }else if(pa_n->elem.weight == pb_n->elem.weight){
        return 0;
    }else{
        return 1;
    }
}

void print_elem(int index, void *pe){
    HTNodePtr p = *(HTNodePtr *)pe;
    printf("%u %c %u %u %u\n", p->elem.weight, p->elem.ch_data, p->parent, p->lchild, p->rchild);
}

bool select_twohuff(HuffTreePtr pHT, HTNodePtr *p1, HTNodePtr *p2){
    HTNodePtr pn = pHT->pnode+1;
    
    SqList *L = create_linerseq(NULL, sizeof(HTNodePtr));
    
    for (int i=0; i<pHT->length; i++, pn++) {
        if (pn->parent == 0) {
            insert_linerseq(L, &pn);
        }
    }
    
    sort_linerseq(L, cmp_value);
    
    print_Liner(L, print_elem);
    
    if (L->length < 2) {
        return FALSE;
    }
    *p1 = *(HTNodePtr *) L->elem;
    *p2 = *((HTNodePtr *) L->elem + 1);
    
    destory_linerseq(L);
    
    return TRUE;
}

void print_hufftree(HuffTreePtr pHT){
    for (int i=0; i<pHT->length; i++) {
        HTNodePtr pn = pHT->pnode + i + 1;
        
        printf("index:%d weight:%d %c parent:%d lchild:%d rchild:%d\n", (i+1), pn->elem.weight, pn->elem.ch_data, pn->parent, pn->lchild, pn->rchild);
    }
    printf("\n");
}

void traverse_huff(HuffTreePtr pHT, HTNodePtr pnode, char *coding, SqList *L){
    char buff[20] = {0};
    
    coding == NULL ? 0:strcpy(buff, coding);
    
    if (pnode->lchild==0 && pnode->rchild==0) {
        HTCoding htc = { pnode->elem.ch_data, NULL };
        htc.coding = malloc(sizeof(strlen(buff)+1));
        strcpy(htc.coding, buff);
        insert_linerseq(L, &htc);
    }else{
        char *pb = buff;
        while (*pb != '\0') {
            pb++;
        }
        
        if (pnode->lchild != 0) {
            *pb = '0';
            traverse_huff(pHT, pHT->pnode+pnode->lchild, buff, L);
        }
        
        if (pnode->rchild != 0) {
            *pb = '1';
            traverse_huff(pHT, pHT->pnode+pnode->rchild, buff, L);
        }
    }
}

void visit_coding(int index, void *p){
    HTCoding *pc = p;
    printf("%c %s\n", pc->ch_data, pc->coding);
}

void hufftree_coding(HuffTreePtr pHT, SqList *L){
    
    HTNodePtr pnfirst, pnsec;
    while (select_twohuff(pHT, &pnfirst, &pnsec)) {
        HTNodePtr pp = pHT->pnode + pHT->length + 1;
        
        pnfirst->parent = pHT->length + 1;
        pnsec->parent = pHT->length + 1;
        
        pp->elem.weight = pnfirst->elem.weight + pnsec->elem.weight;
        pp->parent = 0;
        pp->lchild = (unsigned)(pnfirst-pHT->pnode);
        pp->rchild = (unsigned)(pnsec-pHT->pnode);
        
        pHT->length++;
    }
    
    HTNodePtr root = pHT->pnode + pHT->huffsize - 1;
    traverse_huff(pHT, root, NULL, L);
    
    print_Liner(L, visit_coding);
}

void hufftree_decoding(HuffTreePtr pHT){
    char buff[512] = { 0 };
    char output[20] = { 0 };
    fgets(buff, 512, stdin);
    
    char *pb = buff;
    char *po = output;
    bool from_root = TRUE;
    HTNodePtr pnode = NULL;
    
    do {
        if (from_root) {
            from_root = FALSE;
            pnode = pHT->pnode + pHT->huffsize-1;
        }else{
            if (pnode->lchild==0 && pnode->rchild==0) {
                *po++ = pnode->elem.ch_data;
                from_root = TRUE;
                continue;
            }
            
            if (*pb == '0') {
                pnode = pHT->pnode + pnode->lchild;
            }
            
            if (*pb == '1') {
                pnode = pHT->pnode + pnode->rchild;
            }
            pb++;
        }
    } while (*pb!='\n' && *pb!='\0');
    printf("decoding:%s\n", output);
}

int main(void){

    SqList *L = create_linerseq(NULL, sizeof(EUnit));
    SqList *CL = create_linerseq(NULL, sizeof(HTCoding));
    HuffTree HT;
    
    process_input(L);
    
    init_hufftree(&HT, L);
    
    hufftree_coding(&HT, CL);
    
    hufftree_decoding(&HT);
    
    return 0;
}







