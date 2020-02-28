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
  return parent->left == n;
}
int isRightChild(Node *n)
{
  Node *parent = n->parent;
  return parent->right ==n;
}
