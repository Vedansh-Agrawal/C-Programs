#include <stdio.h>

int main()
{
    int N,M,P;

    scanf("%d %d %d",&M,&N,&P);
    long long int arr1[M][N],x = 0;
    long long int arr2[N][P];


    for (int i = 0 ; i<M;i++)
    {
        for (int j = 0;j<N;j++)
        {
           scanf("%lld",&arr1[i][j]);
        }
    }

    for (int i = 0 ; i<N;i++)
    {
        for (int j = 0;j<P;j++)
        {
           scanf("%lld",&arr2[i][j]);
        }
    }

      printf("\n");
    
     for (int i = 0 ; i<M;i++)
    {
        for (int j = 0;j<P;j++)
        {
          for (int k = 0 ;k<N;k++)
          {
            x += arr1[i][k]*arr2[k][j];
          }

          printf("%lld ",x);
          x = 0;
        }

        printf("\n");
    }

    

    return 0;
}