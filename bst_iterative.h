#ifndef __BST_ITERATIVE_H_
#define __BST_ITERATIVE_H_
#include "bst_tree.h"
void insertIter(int value,Node *n);
void deleteIter(int value,Node *n);
Node * findNextIter(Node *n);
Node * findPrevIter(Node *n);
Node * findMinIter(Node *n);
Node * findMaxIter(Node *n);
#endif
