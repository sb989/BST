#ifndef __STACK_H_
#define __STACK_H_

#include "bst_tree.h"

typedef struct Stack
{
    struct Stack *next;
    void * data;
}Stack;

void * pop(Stack ** top);
void * peek(Stack **top);
Stack * push(Stack **top,void * data);
Stack * newStack(void * data);
int empty(Stack *top);
void freeNode(Stack *stack);

#endif
