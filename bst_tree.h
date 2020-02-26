#ifndef __BST_TREE_H_
#define __BST_TREE_H_
#include <stdio.h>
#include <stdlib.h>
typedef struct Node_s
{
  int value;
  struct Node_s * left;
  struct Node_s * right;
  struct Node_s * parent;
}Node;

Node * newNode();
void deleteNode(Node *n);
void childToNull(Node *n);
int isLeftChild(Node *n);
int isRightChild(Node *n);




#endif
