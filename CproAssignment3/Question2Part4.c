#include <stdio.h>

int main()
{
    int N,a,x = 0,y,n;

    scanf("%d",&N);
    scanf("%d",&n);

    int arr[N + 1];

    for (int i = N;i>=0;i--)
    {
        scanf("%d",&arr[i]);
    }

    for (int i = N;i>0;i--)
    {
       x = n*arr[i] + arr[i - 1];
       n = x;

    }

   

    printf("%d",x);

    return 0;
}