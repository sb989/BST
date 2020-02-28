#include "stack.h"

Node * pop(sNode ** top)
{
  sNode *n;
  Node * ret;
  if(empty(*top))
  {
    printf("stack empty");
    return NULL;
  }
  else
  {
    ret = (*top)->tree;
    n = (*top)->next;
    free(*top);
    *top = n;
    return ret;
  }
}

sNode * push(sNode **top,Node *tree)
{
  sNode * temp = newStack(tree);

  if(empty(*top))
  {
    printf("empty\n");
    return temp;
  }
  temp->next = *top;
  return temp;
}

sNode * newStack(Node * tree)
{
  sNode * temp;
  temp = (sNode*) malloc(sizeof(sNode));
  temp->tree = tree;
  temp->next = NULL;
  return temp;
}

void freeNode(sNode *stack)
{
  free(stack);
}

int empty(sNode *top)
{
  return (!top);
}
