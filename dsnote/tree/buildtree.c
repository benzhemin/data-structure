#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cstdstring.h"

typedef struct _BiTree{
    char data;
    struct _BiTree *lchild;
    struct _BiTree *rchild;
} BiTree, *BiTreePtr;

void string_divide_char(string *s, char c, string **pl, string **pr){
    char *pa = strchr(s->str, c);
    *pa = '\0';
    *pr = create_with_string(pa+1);
    *pl = create_with_string(s->str);
}

void string_divide(string *s, string *in_right, string **pl, string **pr){
    char *pa = s->str;
    while (*pa!='\0' && strchr(in_right->str, *pa)==NULL) {
        pa++;
    }
    if (*pa == '\0') {
        
    }
}

void build_bitree(BiTreePtr *PT, string *pre_order, string *in_order){
    if (!string_empty(pre_order) && !string_empty(in_order)) {
        BiTreePtr T = malloc(sizeof(BiTree));
        T->data = *pre_order->str;
        T->lchild = T->rchild = NULL;
        *PT = T;
        
        string *in_left, *in_right;
        string_divide_char(in_order, *pre_order->str, &in_left, &in_right);
        
        string *pre_left, *pre_right;
        
        
        build_bitree(&T->lchild, pre_left, in_left);
        build_bitree(&T->rchild, pre_right, in_right);
    }
}

void traverse_bitree(BiTree *T){
    if (T != NULL) {
        printf("%c ", T->data);
        
        traverse_bitree(T->lchild);
        traverse_bitree(T->rchild);
    }
}

int main(void){
    BiTreePtr T = NULL;
    
    char *pre_str = "ABDECF";
    char *in_str = "DBEACF";
    
    string *pre_string = create_with_string(pre_str);
    string *in_string = create_with_string(in_str);
    
    build_bitree(&T, pre_string, in_string);
    
    destory_string(pre_string);
    destory_string(in_string);
    
    return 0;
}