#include <stdio.h>


long long int determinant(int N,long long int A[][N])
{
    long long int x = 0,B[N - 1][N - 1],y = 0;

    if (N == 2)
    {
        x += (A[0][0]*A[1][1]) + (A[0][1]*A[1][0]);
        return x % 1000000007;
    }

    for (int j = 0;j<N;j++)
    {
        for (int i = 1;i<N;i++)
        {
            for (int a = 0;a < N;a++)
            {
                if (a != j)
                {
                    B[i - 1][y] = A[i][a];
                    y++;
                }
            }
            y = 0;
        }

        if (A[0][j] != 0)
        {
            x += A[0][j]*determinant(N-1,B);
        }

       
    }

    return x % 1000000007;
}

int main()
{

    int q,N,b,count = 0,arr[50];
    char x = 'a';

    scanf("%d",&q);

    if (q == 0)
    {
        scanf("%d",&N);
    }

    if (q == 1)
    {
        scanf("%d",&N);
        scanf("%d",&b);

        for (int i = 0;i<50;i++)
        {
            arr[i] = b;
        }
    }

    

    long long int matrix[N][N],Ans,m;

    for(int i = 0;i<N;i++)
    {
        for (int j = 0;j<N;j++)
        {
            scanf("%lld",&matrix[i][j]);
            if (matrix[i][j] > 10 || matrix[i][j] < -10)
            {
                count += 1;
            }
        }
    }

    if (N == 1)
    {
        printf("%lld",matrix[0][0]);
        return 0;
    }

    if (determinant(N,matrix) < 0)
    {
        m = (-determinant(N,matrix)) / 1000000007;
        Ans = determinant(N,matrix) + ((m+1)*1000000007);
    }

    else
    {
        Ans = determinant(N,matrix);
    }
     

    if (q == 0)
    {
        printf("%lld",Ans);
    }

    else
    {
       for (int i = 49;i>=0;i--)
       {
           arr[i] = Ans % b;
           Ans = Ans / b;

           if (Ans == 0)
           {
               break;
           }
       }

       for (int i = 0;i<50;i++)
       {
           if (arr[i] != b && arr[i] < 10)
           {
              printf("%d",arr[i]);
           }

           if (arr[i] != b && arr[i] >= 10)
           {
               arr[i] -= 10;
               printf("%c",x + arr[i]); 
           }
       }
    }

   
    return 0;
    
}

