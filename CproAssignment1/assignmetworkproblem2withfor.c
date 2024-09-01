#include <stdio.h>

int main()

{
    int n, i = 0;
    printf("Enter the number of which u want the table\n");
    scanf("%d",&n);

    for (i = 0; i<=10;i++)
    {
      printf("%d x %d = %d\n",n ,i, n*i);
      
    }
return 0;
}