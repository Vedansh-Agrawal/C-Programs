#include <stdio.h>

int main()
{
    int N,M;

    scanf("%d %d",&M,&N);

    long long int arr1[M][N],arr2[M][N],x;


    for (int i = 0 ; i<M;i++)
    {
        for (int j = 0;j<N;j++)
        {
           scanf("%lld",&arr1[i][j]);
        }
    }

    for (int i = 0 ; i<M;i++)
    {
        for (int j = 0;j<N;j++)
        {
           scanf("%lld",&arr2[i][j]);
        }
    }

    for (int i = 0 ; i<M;i++)
    {
        for (int j = 0;j<N;j++)
        {
            x = arr1[i][j] + arr2[i][j];
           printf("%lld ",x);
        }

        printf("\n");
    }

   
    return 0;
}