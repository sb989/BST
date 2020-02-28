#include "rand_array.h"

int * getRandomArray(int n)
{
  int * output,count,r,i;
  output = malloc(n*sizeof(int));
  count = 0;
  while(count <n)
  {
    r = rand();
    //printf("%d\n",r );
    if(count == 0)
    {
      output[0] = r;
      count = 1;
      continue;
    }

    for(i=0;i<count;i++)
    {
      //printf("r is %d output[%d] is %d\n",r,i,output[i]);
      //printf("%d && %d\n",(r!=output[i]),(i==count-1));
      if(r != output[i] && i ==count-1)
      {
        output[i+1] = r;
        count = count +1;
        printf("count is %d\n",count);
        break;
      }
      else if(r== output[i])
      {
        break;
      }
    }
  }
  return output;
}
