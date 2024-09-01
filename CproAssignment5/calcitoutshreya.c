#include <stdio.h>
#include<stdlib.h>

#define MOD 1000000007


long long int gcdExtended(long long int a, long long int b, long long int *x, long long int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    long long int x1, y1; // To store results of recursive call
    long long int gcd = gcdExtended(b % a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

long long int modInverse(long long int a)
{
    long long int x, y;
    gcdExtended(a, MOD, &x, &y);

    // m is added to handle negative x
    long long int res = (x % MOD + MOD) % MOD;
    return res;
}


int main()
{
   // input stuff
   long long int N, M;
   scanf("%lld %lld", &N, &M);
   long long int A[N][M];
   for (long long int e = 0; e < N; e++)
   {
      for (long long int j = 0; j < M; j++)
      {
      
         scanf("%lld", &A[e][j]);
      }
   }

   for (long long int i = 1; i < N; i++)
   {
      for (long long int j = 0; j < M; j++)
      {
         A[i][j] = (A[i - 1][j] * A[i][j]) % MOD;
      }
   }

   for (long long int i = 0; i < N; i++)
   {
      for (long long int j = 1; j < M; j++)
      {
         A[i][j] = (A[i][j - 1] * A[i][j]) % MOD;
      }
   }

   

   long long int q;
   scanf("%lld", &q);
   long long int result[q];
   long long int x1[q], x2[q], y1[q], y2[q];

   for (long long int t = 0; t < q; t++)
   {
      long long int X = 1;
      long long int Y = 1;
      scanf("%lld %lld %lld %lld", &x1[t], &y1[t], &x2[t], &y2[t]);
   
         if (x1[t] != 0)
         {
            X = (X * A[x1[t]-1][y2[t]]) % MOD;
            
         }
         else
         {
            X = 1;
           
         }
     
         if (y1[t] != 0)
         {
            Y = (Y* A[x2[t]][y1[t]-1]) % MOD;
           
         }
         else
         {
            Y = 1;
           
         }
    
      long long int k;
     
   
      
      result[t]=A[x2[t]][y2[t]];

      if (x1[t] != 0 && y1[t] != 0)
      {
        // k = modInverse(w);
         result[t] = (result[t] * A[x1[t] - 1][y1[t] - 1] ) % MOD;
         //result[t] = (result[t] * k) % MOD;
      }
     // if (x1[t] == 0 && y1[t] != 0)

      if (y1[t] != 0)
      {
         k = modInverse(Y);
         result[t] = (result[t]*k) % MOD;
         
      }
     
      if (x1[t] != 0 )
      {
         k = modInverse(X);
        
         result[t] = (result[t]*k) % MOD;
      }
      
      printf("%lld\n", (result[t]));
      //result[t]=0;
   }

 
   return 0;
}