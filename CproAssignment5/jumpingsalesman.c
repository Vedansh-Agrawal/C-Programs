#include <stdio.h>

int lds(int arr[], int N, int M)
{
    int lds[M - N + 1], ans;

    for (int i = 0; i < M - N + 1; i++)
    {
        lds[i] = 1;
    }

    for (int i = N + 1; i <= M; i++)
    {
        for (int j = N; j < i; j++)
        {
            if (arr[i] < arr[j])
            {
                if (lds[j - N] + 1 > lds[i - N])
                {
                    lds[i - N] = lds[j - N] + 1;
                }
            }
        }
    }

    ans = lds[0];
    for (int i = 0; i < M - N + 1; i++)
    {
        if (lds[i] > ans)
        {
            ans = lds[i];
        }
    }

    return ans;
}

int ldsfinal(int arr[], int N, int M)
{
    int lds[M - N + 1];

    for (int i = 0; i < M - N + 1; i++)
    {
        lds[i] = 1;
    }

    for (int i = N + 1; i <= M; i++)
    {
        for (int j = N; j < i; j++)
        {
            if (arr[i] < arr[j])
            {
                if (lds[j - N] + 1 > lds[i - N])
                {
                    lds[i - N] = lds[j - N] + 1;
                }
            }
        }
    }

    return lds[M];
}

int main()
{
    int k, M, ans = 0;
    scanf("%d %d", &k, &M);

    int building[k];

    for (int i = 0; i < k; i++)
    {
        scanf("%d", &building[i]);
    }

    if (M >= k)
    {
        ans = lds(building, 0, k - 1);
    }
    else if (M == 1)
    {
        ans = 1;
        ans += lds(building, 1, k - 1);
    }
    else
    {
        ans = ldsfinal(building, 0, M - 1);
        ans += lds(building, M, k - 1);
        int x = lds(building,0,k-1);
        if (x>ans)
        {
            ans = x;
        }
    }

    printf("%d", ans);
    return 0;
}