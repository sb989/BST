#include "bst_tree.h"

Node *newNode()
{
  Node * temp = (Node*)malloc(sizeof(Node));
  temp->left = NULL;
  temp->right = NULL;
  temp->parent = NULL;
  return temp;
}



void deleteNode(Node *n)
{
  free(n);
}

void deleteTree(Node *root)
{
  Node *curr,*parent;
  curr = root;
  while(curr)
  {
    if(!curr->right && !curr->left)
    {
      if(parent)
      {
        if(isLeftChild(curr))
          parent->left = NULL;
        else if(isRightChild(curr))
          parent->right = NULL;
      }
      deleteNode(curr);
      curr = parent;
      if(curr->parent)
        parent = curr->parent;
    }
    if(curr->left)
    {
      parent = curr;
      curr = curr->left;
      continue;
    }
    if(curr->right)
    {
      parent = curr;
      curr = curr->left;
      continue;
    }

  }
}

int isLeftChild(Node *n)
{
  Node * parent = n->parent;
  if(!parent)
    return 0;
  if(parent->left)
    return parent->left == n;
  else
    return 0;
}
int isRightChild(Node *n)
{
  Node *parent = n->parent;
  if(!parent)
    return 0;
  if(parent->right)
    return parent->right ==n;
  else
    return 0;
}

int height(Node * root)
{
  Node * curr,*temp;
  Stack * stack,*lstack,*rstack;
  int max,ret,*v;
  curr = root;
  ret = 0;
  max = -2;
  lstack = NULL;
  rstack = NULL;
  stack =NULL;
  while(1)
  {
    if(curr)
    {
      //printf("avl_iterative line 82 m1\n");
      if(curr->right)
        stack = push(&stack,curr->right);
      stack = push(&stack,curr);
      curr = curr->left;
      continue;
    }
    else
    {
      //printf("avl_iterative.c line 91 m2\n");
      if(empty(stack))
      {
        ret = max+1;
        break;
      }
      temp = (Node *)pop(&stack);
      if(temp->right == peek(&stack) && !empty(stack))
      {
        curr = (Node *)pop(&stack);
        stack = push(&stack,temp);
      }
      else
      {
        if(!temp->left)
        {
          v =(int*)malloc(sizeof(int));
          *v = -1;
          lstack = push(&lstack,v);
        }
        if(!temp->right)
        {
          v =(int*)malloc(sizeof(int));
          *v = -1;
          rstack = push(&rstack,v);
        }
        max = maxVal(*(int*)pop(&lstack),*(int*)pop(&rstack));
        if(!temp->parent)
        {
          ret = max+1;
        }
        else if(isLeftChild(temp))
        {
          v =(int*)malloc(sizeof(int));
          *v = max+1;
          lstack = push(&lstack,v);
        }
        else if(isRightChild(temp))
        {
          v =(int*)malloc(sizeof(int));
          *v = max+1;
          rstack = push(&rstack,v);
        }
      }
    }
    if(empty(stack))
    {
      ret = max+1;
      break;
    }
  }
  freeStack(&lstack);
  freeStack(&rstack);
  return ret;
}

int maxVal(int a, int b)
{
  if(a>b)
    return a;
  if(b>a)
    return b;
}
