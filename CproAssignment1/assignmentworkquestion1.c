#include <stdio.h>
int main()

{
    int a, b, c;

scanf("%d\n%d\n%d",&a,&b,&c);
   if ((a*a)+(b*b) == (c*c))
   {
       printf("YES");
   }

   else if ((b*b)+(c*c) == (a*a))
   {
        printf("YES");
   }

   else if ((c*c)+(a*a) == (b*b))
   {
        printf("YES");
   }
else{

    printf("NO");
}

return 0;

}