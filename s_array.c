#include "s_array.h"


int * getSortedArray(int n)
{
  int *output,i;
  output = (int*)malloc(sizeof(int)*n);
  for(i=0;i<n;i++)
  {
    output[i]= n-i;
  }
  return output;
}
