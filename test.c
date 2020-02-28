#include "bst_recursive.h"
#include "bst_iterative.h"

int main()
{
  Node *root,*temp;
  int i;
  int arr[] = {20,8,22,12,4,10,14,24,21,25};
  root = NULL;
  for(i=0;i<10;i++)
  {
    root = insertRec(arr[i],root);
  }
  //printBstRec(root);
  for(i=0;i<10;i++)
  {
    temp = findNextRec(root,arr[i]);
    //if(temp)
    //  printf("the value that comes after %d is %d\n",arr[i],temp->value);
  }
  for(i=0;i<10;i++)
  {
    temp = findPrevRec(root,arr[i]);
    if(temp)
      printf("the value that comes before %d is %d\n",arr[i],temp->value);
  }

  root = deleteRec(20,root);
  //printBstRec(root);
  deleteTree(root);
  root = NULL;
  for(i=0;i<10;i++)
  {
    root = insertIter(arr[i],root);
  }
  printf("\n");
  printBstRec(root);
  for(i= 0; i<10;i++)
  {
    temp = findNextIter(root,arr[i]);
    //printf("value is %d\n",arr[i]);
    if(temp)
      printf("the value that after after %d is %d\n",arr[i],temp->value);
  }


}
