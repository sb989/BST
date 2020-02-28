#ifndef __BST_ITERATIVE_H_
#define __BST_ITERATIVE_H_
#include "bst_tree.h"
Node * insertIter(int value,Node *curr);
Node * deleteIter(int value,Node *n);
Node * findNextIter(Node * root,int value);
Node * findPrevIter(Node * root,int value);
Node * findMinIter(Node *n);
Node * findMaxIter(Node *n);
Node * largerAncestorIter(Node *n,int value);
#endif
