#include <stdio.h>

int main()

{
    int i, j, k, l = 0;
   
    scanf("%d %d",&i,&j);

  
    for (k = 2 ;k <= i ; k++)
    {
      if (i % k != 0 || j % k != 0)
      {
          l = l + 1;
      }
    }
    
      if (l == i - 1)
      {
          printf("YES");
      }

      else{
          printf("NO");
      }
    


  return 0;
}