#include "stack.h"

void * pop(Stack ** top)
{
  Stack *n;
  Node * ret;
  if(empty(*top))
  {
    //printf("stack empty\n");
    return NULL;
  }
  else
  {
    ret = (*top)->data;
    n = (*top)->next;
    free(*top);
    *top = n;
    return ret;
  }
}

void freeStack(Stack **top)
{
  Stack *temp,*next;
  if(!*top)
  {
    return;
  }
  temp = *top;
  while(temp)
  {
    next = temp->next;
    free(temp);
    temp = next;
  }
}
void * peek(Stack **top)
{
  if(empty(*top))
  {
    //printf("stack empty\n");
    return NULL;
  }
  else
  {
    return (*top)->data;
  }
}

Stack * push(Stack **top,void * data)
{
  Stack * temp = newStack(data);

  if(!*top)
  {
    //printf("stack empty returning new node\n");
    return temp;
  }
  temp->next = *top;
  return temp;
}

Stack * newStack(void * data)
{
  Stack * temp;
  temp = (Stack*) malloc(sizeof(Stack));
  temp->data = data;
  temp->next = NULL;
  return temp;
}

void freeNode(Stack *stack)
{
  free(stack->data);
  free(stack);
}

int empty(Stack *top)
{
  return (!top);
}
