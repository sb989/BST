#ifndef __BST_RECURSIVE_H_
#define __BST_RECURSIVE_H_
#include "bst_tree.h"
Node * insertRec(int value,Node *n);
Node * deleteRec(int value,Node *n);
Node * findNextRec(Node *root,int value);
Node * findPrevRec(Node *root,int value);
Node * findMinRec(Node *n);
Node * findMaxRec(Node *n);
Node * binarySearchRec(Node *root,int value);
Node * largerAncestorRec(Node *n,int value);
void printBstRec(Node *n);
Node * childToNullRec(Node * root,Node *n);
void printLevelOrder(Node *root);
void printLevel(Node *root,int level);
#endif
