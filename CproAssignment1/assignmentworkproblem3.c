#include <stdio.h>
#include <math.h>

int main()

{
    double k = 0;
  int i, j;
 
  scanf("%d",&i);

  for (j = 1 ; j <= i ; j++)
  {
   k = k + sqrt(j);
  }
  printf("%f",k);
  return 0;

}