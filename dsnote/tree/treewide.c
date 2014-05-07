#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bitree.h"

typedef struct{
	char ch;
	int level;
}TElem;

#define RECORD_INITSIZE 5
#define RECORD_INCREMENT 10

typedef struct{
	int *elem;
	unsigned length;
}LevelRrd;

void init_lr(LevelRrd *LR){
	LR->elem = malloc(sizeof(int) * RECORD_INITSIZE);
	memset(LR->elem, 0, RECORD_INITSIZE*sizeof(int));
	LR->length = RECORD_INITSIZE;
}

void level_record(LevelRrd *LR, int level){
	if(level >= LR->length){
		LR->elem = realloc(LR->elem, (LR->length+RECORD_INCREMENT)*sizeof(int));
		memset(LR->elem+LR->length, 0, RECORD_INCREMENT*sizeof(int));
	}

	*(LR->elem + level) += 1;
}

int tree_wide(LevelRrd *LR){
	int wide = -1;
	int *pstart = LR->elem;
	int *pend = LR->elem+LR->length;

	while(pstart < pend){
		if(*pstart > wide){
			wide = *pstart;
		}
		pstart++;
	}

	return wide;
}

void traverse_build(BiTree *T, int level, LevelRrd *LR){
	if(T != NULL){
		level_record(LR, level);

		//((TElem *)T->pdata)->level = level;
		traverse_build(T->lchild, (level+1), LR);
		traverse_build(T->rchild, (level+1), LR);
	}
}

int main(void){
	int wide;
	BiTree *T;
	LevelRrd LR;
	init_lr(&LR);

	create_preorder_bitree(&T);
	traverse_build(T, 1, &LR);
	wide = tree_wide(&LR);

	printf("tree wide :%d\n", wide);

	return 0;
}