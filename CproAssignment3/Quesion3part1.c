#include <stdio.h>

int main()
{
    int N;

    scanf("%d",&N);

    int y;

    double Matrix[N][N + 1],Ans[N],x;

    for (int i = 0;i<N;i++)
    {
        for (int j = 0;j<N;j++)
        {
            scanf("%lf",&Matrix[i][j]);
        }
    }

    for (int i = 0;i<N;i++)
    {
        scanf("%lf",&Matrix[i][N]);
    }

   


    for (int i = 0;i<N - 1;i++)
    {
        for (int a = i+1;a<N;a++)
        {
            x = Matrix[a][i]/Matrix[i][i];
            for (int b = i;b<N+1;b++)
            {
                Matrix[a][b] -= x*Matrix[i][b];
            }

            
        }
    }

    

    
      for (int i = N-1;i>=0;i--)
    {
        if (i + 1 != N)
        {
           for (int a = i+1;a<N;a++)
           {
               Matrix[i][N] -= Matrix[i][a]*Ans[a];
           }

           Ans[i] = Matrix[i][N]/Matrix[i][i];
        }

        else
        {
            Ans[N-1] = Matrix[N-1][N]/Matrix[N-1][N-1];
        }
    }

    for (int i = 0;i<N;i++)
    {
        y = Ans[i];
        printf("%lf\n",Ans[i]);
    }

    return 0;
}