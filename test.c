#include "bst_recursive.h"
#include "bst_iterative.h"
#include "sort.h"
#include "rand_array.h"
#include "s_array.h"
int main()
{
  Node *root,*temp;
  int i,*arr2,*random,*sarray;
  int arr[] = {20,8,22,12,4,10,14,24,21,25};
  root = NULL;
  int size;
  size = 10;
  for(i=0;i<size;i++)
  {
    root = insertRec(arr[i],root);
  }
  printBstRec(root);
  for(i=0;i<size;i++)
  {
    temp = findNextRec(root,arr[i]);
    //if(temp)
    //  printf("the value that comes after %d is %d\n",arr[i],temp->value);
  }
  for(i=0;i<size;i++)
  {
    temp = findPrevRec(root,arr[i]);
    //if(temp)
      //printf("the value that comes before %d is %d\n",arr[i],temp->value);
  }

  root = deleteRec(20,root);
  //printBstRec(root);
  //deleteTree(root);
  root = NULL;
  for(i=0;i<size;i++)
  {
    root = insertIter(arr[i],root);
  }
  //printf("\n");
  //printBstRec(root);
  for(i= 0; i<size;i++)
  {
    temp = findNextIter(root,arr[i]);
    //printf("value is %d\n",arr[i]);
    //if(temp)
      //printf("the value that after after %d is %d\n",arr[i],temp->value);
  }
  arr2 = sort(arr,size);
  for(i = 0;i<size;i++)
  {
    printf("sort test value is %d\n",arr2[i]);
  }
  random = getRandomArray(20);
  for(i=0;i<20;i++)
  {
    printf("random[%d] is %d\n",i,random[i]);
  }

  sarray = getSortedArray(20);
  for(i=0;i<20;i++)
  {
    printf("%d\n",sarray[i]);
  }
}
