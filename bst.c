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
