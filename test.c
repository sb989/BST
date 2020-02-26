#include "bst_recursive.h"


int main()
{
  Node *root,*temp;
  int i;
  int arr[] = {11,15,7,1,2,29,40,35};
  root = NULL;
  for(i=0;i<8;i++)
  {
    root = insertRec(arr[i],root);
  }
  printBstRec(root);
  for(i=0;i<8;i++)
  {
    temp = findNextRec(root,arr[i]);
    if(temp)
      printf("the value that comes after %d is %d\n",arr[i],temp->value);
  }
}
