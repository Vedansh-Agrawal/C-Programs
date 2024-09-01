#include <stdio.h>


int main()
{
    int n, i = 0;
    printf("Enter the number of which u want the table\n");
    scanf("%d",&n);

    while (i != 11)
    {
      printf("%d x %d = %d\n",n ,i, n*i);
      i = i + 1;
    }
return 0;
}