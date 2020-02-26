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

void childToNull(Node *n)
{
  Node * parent;
  parent = n->parent;
  if(!parent)
  {
    //printf("child has no parent");
    return;
  }
  if(isLeftChild(n))
    parent->left == NULL;//set the parent nodes pointer to it to null
  else if(isRightChild(n))
    parent->right == NULL;//set the parent nodes pointer to it to null
  else
    printf("Error: child is not child of parent");
}
