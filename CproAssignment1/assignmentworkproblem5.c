#include <stdio.h>

int main()

{
   long long int i,vector1[100000],vector2[100000];
   long long int x = 0;

   scanf("%lld",&i);

   for (int j = 0;j<i;j++)
   {
       scanf("%lld",&vector1[j]);
   }

   for (int j = 0;j<i;j++)
   {
       scanf("%lld",&vector2[j]);
   }

   for (int j = 0;j<i;j++)
   {
     x += vector1[j]*vector2[j];
   }

   printf("%lld",x);

return 0;
}