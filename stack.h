#ifndef __STACK_H_
#define __STACK_H_

#include "bst_tree.h"

typedef struct sNode
{
    struct sNode *next;
    Node * tree;
}sNode;

Node * pop(sNode ** top);
sNode * push(sNode **top,Node *tree);
sNode * newStack(Node * tree);
int empty(sNode *top);
void freeNode(sNode *stack);

#endif
