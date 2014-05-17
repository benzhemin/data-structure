#ifndef Huffman_huffman_h
#define Huffman_huffman_h

#define HUFFMAN_LEFT_BRANCH "0"
#define HUFFMAN_RIGHT_BRANCH "1"

typedef struct{
    char ch_data;
    unsigned weight;
} HTElem;

typedef struct {
    HTElem *elem;
    char *hc_str;
    unsigned parent;
    unsigned lchild, rchild;
}HTNode, *HTNodePtr;

typedef struct {
    HTNodePtr pnodes;
    unsigned length;
    unsigned huffsize;
} HuffTree, *HuffTreePtr;

#endif
