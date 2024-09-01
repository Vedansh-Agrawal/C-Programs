#include <stdio.h>

int main()
{
    int N;

    scanf("%d",&N);
    int arr[N][N];


    for (int i = 0 ; i<N;i++)
    {
        for (int j = 0;j<N;j++)
        {
           scanf("%d",&arr[i][j]);
        }
    }

    for (int j = 0;j<N;j++)
    {
        for (int i = 0;i<N;i++)
        {
            printf("%d ",arr[i][j]);
        }

        printf("\n");
    }

    return 0;
}