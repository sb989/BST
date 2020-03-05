#include "bst_recursive.h"
#include "bst_iterative.h"
#include "sort.h"
#include "rand_array.h"
#include "s_array.h"
#include "avl_iterative.h"
int main()
{
  Node *root,*temp;
  int i,*arr2,*random,*sarray;
  int arr[] = {20,8,22,12,4,10,14,24,21,25,26,15,16,17};
  root = NULL;
  int size;
  Stack * st;
  size = 14;
  root = NULL;
  //insertIter(&root,arr[0]);
  for(i=0;i<size;i++)
  {
    root = insertIter(root,arr[i]);
  }
  printLevelOrder(root);
  printf("\n");
  printf("the height of the tree is %d\n",height(root));
  root = deleteIter(20,root);
  printLevelOrder(root);
  printf("\n");
  root = NULL;
  for(i=0;i<size;i++)
  {
    root = avlInsertIter(root,arr[i]);
    //printf("after insert %d the root is %d\n\n",arr[i],root->value);
  }
  printLevelOrder(root);
  printf("\n");
  root = avlDeleteIter(root,20);
  printLevelOrder(root);
  root = avlDeleteIter(root,21);
  printLevelOrder(root);
  root = avlDeleteIter(root,12);
  printLevelOrder(root);


}
