#include <stdio.h>

#include "huffman.h"
#include "linerseq.h"
#include "charfreq.h"

bool char_found(SqList *L, char ch){
    bool found = FALSE;
    
    for (int i=0; i<L->length; i++) {
        HTElem *pe = (HTElem *)L->elem + i;
        if (pe->ch_data == ch) {
            pe->weight++;
            found = TRUE;
        }
    }
    
    return found;
}

void apperance_freq(SqList *L){
    char input[512] = { 0 };
    char *p = input;
    fgets(input, sizeof(input), stdin);
    
    while (*p!='\n' && *p!='\0') {
        if (char_found(L, *p) == FALSE) {
            HTElem elem = { *p, 1 };
            insert_linerseq(L, &elem);
        }
        p++;
    }
}

void visit_statistic(int index, void *p){
    HTElem *pe = p;
    printf("%c %d\n", pe->ch_data, pe->weight);
}
