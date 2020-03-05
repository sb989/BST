#include "sort.h"
#include "bst_recursive.h"
#include "stack.h"
#include <stdio.h>
int * sort(int *unsorted,int size)
{
  Node * root,*curr,*parent;
  int i,count;
  Stack * stack;
  root = NULL;
  int * output;
  output = (int*)malloc(size*sizeof(int));
  printf("size of count is %d\n",size);
  //size = size+1;
  printf("size of count is %d\n",size);
  for(i=0;i<size;i++)
  {
    root = insertRec(unsorted[i],root);
  }
  printBstRec(root);
  curr = root;
  parent = root->parent;
  count = 0;
  stack = NULL;
  while(count < size)
  {
    if(curr)
    {
      stack = push(&stack,curr);
      curr = curr->left;
    }
    else
    {
      if(!empty(stack))
      {
        curr = (Node *)pop(&stack);
        //printf("%d count is %d\n",curr->value,count);
        output[count] = curr->value;
        count = count +1;
        curr = curr->right;
      }
      else
      {
        break;
      }
    }

  }

  return output;
}
