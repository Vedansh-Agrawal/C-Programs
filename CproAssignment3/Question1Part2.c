#include <stdio.h>

int main()
{
    int N,M;

    scanf("%d %d",&M,&N);
    int arr[M][N];


    for (int i = 0 ; i<M;i++)
    {
        for (int j = 0;j<N;j++)
        {
           scanf("%d",&arr[i][j]);
        }
    }

    for (int j = 0;j<N;j++)
    {
        for (int i = 0;i<M;i++)
        {
            printf("%d ",arr[i][j]);
        }

        printf("\n");
    }

    return 0;
}