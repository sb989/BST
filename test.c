#include "bst_recursive.h"


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
  printBstRec(root);
  for(i=0;i<10;i++)
  {
    temp = findNextRec(root,arr[i]);
    if(temp)
      printf("the value that comes after %d is %d\n",arr[i],temp->value);
  }
  root = deleteRec(20,root);
  printBstRec(root);
}
