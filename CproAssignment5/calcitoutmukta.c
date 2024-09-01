#include <stdio.h>

#define M 1000000007

int modinverse(int m)
{
    long long int a1 = 1, a2 = 0, a3 = m;
    long long int b1 = 0, b2 = 1, b3 = M;

    while (1)
    {
        if (b3 == 0)
        {
            return 1;
        }
        if (b3 == 1)
        {
            return b1 % M;
        }

        long long int q = a3 / b3;
        long long int t1 = a1 - (q * b1);
        long long int t2 = a2 - (q * b2);
        long long int t3 = a3 - (q * b3);

        a1 = b1, a2 = b2, a3 = b3;
        b1 = t1, b2 = t2, b3 = t3;
    }
}

/*long long int gcdExtended(long long int a, long long int b, long long int *x, long long int *y)
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

long long int modinverse(long long int a)
{
    long long int x, y;
    gcdExtended(a, M, &x, &y);

    // m is added to handle negative x
    long long int res = (x % M + M) % M;
    return res;
}*/

int main()
{
    long long int n, m;
    scanf("%lld %lld", &n, &m);

    long long int a[n][m], p[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%lld", &a[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0)
            {
                p[i][j] = a[i][j] % M;
                continue;
            }
            p[i][j] = (a[i][j] * p[i - 1][j]) % M;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            p[i][j] = (p[i][j] * p[i][j - 1]) % M;
        }
    }

    /*for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%lld ", p[i][j]);
        }
        printf("\n");
    }*/

    int queries;
    scanf("%d", &queries);

    int q[queries][4];
    for (int i = 0; i < queries; i++)
    {
        scanf("%d %d %d %d", &q[i][0], &q[i][1], &q[i][2], &q[i][3]);
    }

    for (int i = 0; i < queries; i++)
    {
        int x1 = q[i][0];
        int y1 = q[i][1];
        int x2 = q[i][2];
        int y2 = q[i][3];

        long long int total = p[x2][y2] % M;
        printf("70:%lld ", total);

        if (x1 > 0 && y1 > 0)
        {
            total = (total * p[x1 - 1][y1 - 1]) % M;
        }

        if (x1 > 0)
        {
            total = (total * modinverse(p[x1 - 1][y2])) % M;
        }
        if (y1 > 0)
        {
            total = (total * modinverse(p[x2][y1 - 1])) % M;
        }

        printf("%lld\n", total % M);
    }
    return 0;
}