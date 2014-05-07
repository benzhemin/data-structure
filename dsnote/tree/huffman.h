#ifndef _HUFFMAN_H
#define _HUFFMAN_H

typedef struct {
    unsigned weight;
    unsigned parent;
    unsigned lchild, rchild;
}HTNode, *HTNodePtr;

typedef struct {
    HTNodePtr pnode;
    unsigned length;
} HuffTree, *HuffTreePtr;

#define ELEM_INIT_SIZE 100
#define ELEM_INCREMENT 20

typedef struct {
    char ch_data;
    unsigned freq;
} EUnit;

#endif