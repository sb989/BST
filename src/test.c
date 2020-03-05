#include "bst_recursive.h"
#include "bst_iterative.h"
#include "sort.h"
#include "rand_array.h"
#include "s_array.h"
#include "avl_iterative.h"
int main()
{
  Node *bstRec,*bstIter1,*bstIter2,*avl1,*avl2;
  int i,*arr2,*arr1;
  int arr[] = {20,8,22,12,4,10,14,24,21,25,26,15,16,17};
  int size;
  Stack * st;
  size = 10000;
  bstRec= NULL;
  bstIter1 = NULL;
  bstIter2 = NULL;
  avl1 = NULL;
  avl2 = NULL;
  printf("starting creation of random array with %d elements\n",size);
  arr1 = getRandomArray(size);
  printf("finished creating random array of %d elements\n\n",size);
  printf("starting bst rec creation using random array.\n");
  for(i=0;i<size;i++)
  {
    bstRec = insertRec(bstRec,arr1[i]);
  }
  printf("finished creating bst rec.\n\n");
  //printLevelOrder(bst);
  printf("starting bst iter creation using random array.\n");
  for(i=0;i<size;i++)
  {
    bstIter1 = insertIter(bstIter1,arr1[i]);
  }
  printf("finished creating bst iter.\n\n");
  printf("starting avl creation using random array.\n");
  for(i=0;i<size;i++)
  {
    avl1 = avlInsertIter(avl1,arr1[i]);
  }
  printf("finished creating avl from random array\n\n");
  //printLevelOrder(avl);
  printf("BST iterative count using random array is %d \n",getBstCount());
  printf("AVL iterative count using random array is %d \n\n",getAvlCount());
  setBstCount(0);
  setAvlCount(0);

  printf("starting creation of sorted array with %d elements\n",size);
  arr2 = getSortedArray(size);
  printf("finished creating sorted array of %d elements\n\n",size);

  printf("starting bst iter creation using sorted array.\n");
  for(i=0;i<size;i++)
  {
    bstIter2 = insertIter(bstIter2,arr2[i]);
  }
  printf("finished creating bst iter.\n\n");
  printf("starting avl creation using sorted array.\n");
  for(i=0;i<size;i++)
  {
    avl2 = avlInsertIter(avl2,arr2[i]);
  }
  printf("finished creating avl from sorted array\n\n");

  printf("BST iterative count using sorted array is %d \n",getBstCount());
  printf("AVL iterative count using sorted array is %d \n",getAvlCount());


  printf("done\n");
}
