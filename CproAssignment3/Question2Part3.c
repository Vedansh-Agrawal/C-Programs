#include <stdio.h>

int main()
{
    int N,a,x = 0,y,n;

    scanf("%d",&N);
    

    int arr[N + 1];

    for (int i = 0;i<N+1;i++)
    {
        scanf("%d",&arr[i]);
    }

    scanf("%d",&n);

    for (int i = N;i>0;i--)
    {
       y = arr[i];
       for (int j = i;j>0;j--)
       {
           y = y*n;
       }
       x += y;
    }

    x += arr[0];

    printf("%d",x);

    return 0;
}