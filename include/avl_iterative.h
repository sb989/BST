#ifndef __AVL_ITERATIVE_H_
#define __AVL_ITERATIVE_H_
#include "bst_tree.h"
#include "stack.h"
#include "bst_iterative.h"

Node * avlInsertIter(Node *root,int value);
Node * avlBalance(Node *curr,Node* child, Node *grandchild);
//int height(Node *root);
int balanceFactor(Node *root);
Node * rotateLeft(Node *r);
Node * rotateRight(Node * r);
Node * avlDeleteIter(Node *root,int value);
Node *deleteBalance(Node * root);
Node * insertBalance(Node *root);
int getAvlCount();
void setAvlCount(int c);



#endif
