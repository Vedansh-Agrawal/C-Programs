#include <stdio.h>



int main()
{
    int N;

    scanf("%d",&N);

    

    double Matrix[N][N],identity[N][N],x;

    for (int i = 0;i<N;i++)
    {
        for (int j = 0;j<N;j++)
        {
            scanf("%lf",&Matrix[i][j]);
        }
    }

     for (int i = 0;i<N;i++)
    {
        for (int j = 0;j<N;j++)
        {
            if(i == j)
            {
                identity[i][j] = 1;
            }

            else
            {
                identity[i][j] = 0;
            }
        }
    }

 for (int i = 0;i<N - 1;i++)
    {
        for (int a = i+1;a<N;a++)
        {
            if (Matrix[i][i] != 0)
            {
                identity[a][i] = Matrix[a][i]/Matrix[i][i];
            }

            else
            {
               printf("No LU decomposition");
               return 0;
            }
            
            for (int b = i;b<N;b++)
            {
                Matrix[a][b] -= identity[a][i]*Matrix[i][b];
            }

        }
    }

    for (int i = 0;i<N;i++)
    {
        for (int j = 0;j<N;j++)
        {
            
            printf("%lf ",identity[i][j]);
        }
        printf("\n");
    }

    for (int i = 0;i<N;i++)
    {
        for (int j = 0;j<N;j++)
        {
            printf("%lf ",Matrix[i][j]);
        }
        printf("\n");
    }


    
    return 0;
}