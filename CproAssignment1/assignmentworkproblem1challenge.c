#include <stdio.h>

int main()

{
    int n;
  scanf("%d",&n);
 
    for (int a = 1;a<=200;a++)
    {
      for (int b = a;b<=200;b++)
      {
        for (int c = b;c<=200;c++)
        {
          if (a*a + b*b == c*c)
          {
            printf("%d %d %d\n",a,b,c);
            n -= 1;
          }

          if (n == 0)
          {
            break;
          }
        }
        if (n == 0)
        {
          break;
        }
      }
      if (n == 0)
      {
        break;
      }
    }
  
  

 return 0;
 
}