#include <stdio.h>


int main()
{
    printf("Hello!what is your favourite number?\n");
    int n, i, j, k;
    scanf("%d",&n);
for(k = 1;k<=10;k++)
{
    for(i=1;i<=n; i++)
    {
        for(j=1;j<=10;j++)
        {
            printf("%d x %d = %d\n",i,j,j*i);
        }
    }
}   

    
}