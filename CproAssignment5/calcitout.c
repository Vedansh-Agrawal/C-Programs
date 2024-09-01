#include <stdio.h>
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

long long int inv(long long int a)
{
    long long int x, y;
    gcdExtended(a, MOD, &x, &y);

    // m is added to handle negative x
    long long int res = (x % MOD + MOD) % MOD;
    return res;
}

int main()
{
    int N, M;

    scanf("%d %d", &N, &M);

    long long int Matrix[N][M];

    

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            scanf("%lld", &Matrix[i][j]);
            
            if (i - 1 != (-1) && j - 1 != (-1))
            {
                Matrix[i][j] = (Matrix[i][j] * Matrix[i - 1][j]) % MOD;
                Matrix[i][j] = (Matrix[i][j] * Matrix[i][j - 1]) % MOD;
                Matrix[i][j] = (Matrix[i][j] * inv(Matrix[i - 1][j - 1])) % MOD;
            }

            else if (i - 1 != (-1))
            {
                Matrix[i][j] = (Matrix[i][j] * Matrix[i - 1][j]) % MOD;
            }

            else if (j - 1 != (-1))
            {
                Matrix[i][j] = (Matrix[i][j] * Matrix[i][j - 1]) % MOD;
            }
        }
    }

    
    int Q;

    scanf("%d", &Q);

    long long int ans;
    int query[4];

    for (int z = 0; z < Q; z++)
    {
        scanf("%d %d %d %d", &query[0], &query[1], &query[2], &query[3]);

        ans = Matrix[query[2]][query[3]];

        if (query[0] - 1 != (-1) && query[1] - 1 != (-1))
        {
            ans = (ans * Matrix[query[0] - 1][query[1] - 1]) % MOD;
            ans = (ans * inv(Matrix[query[0] - 1][query[3]])) % MOD;
            ans = (ans * inv(Matrix[query[2]][query[1] - 1])) % MOD;
        }

        else if (query[0] - 1 != (-1))
        {
            ans = (ans * inv(Matrix[query[0] - 1][query[3]])) % MOD;
        }

        else if (query[1] - 1 != (-1))
        {
            ans = (ans * inv(Matrix[query[2]][query[1] - 1])) % MOD;
        }

        printf("%lld\n", ans);
    }

    return 0;
}