#include <stdio.h>

int main()
{
    long long int K, N, x = 0, i;

    scanf("%lld %lld", &N, &K);

    long long int arr[N];

    for (long long int j = 0; j < N; j++)
    {
        scanf("%lld", &arr[j]);
    }

    for (i = 0; i < N; i++)
    {
        if (arr[i] >= 8)
        {
            x += 8;
            if (i + 1 <N)
            {
                arr[i + 1] += arr[i]- 8;
            }
        }

        else if (arr[i] < 8)
        {
            x += arr[i];
        }

        if (x >= K)
        {
            break;
        }
    }


    if (x >= K)
    {
        printf("%lld", i + 1);
    }

    else 
    {
        printf("-1");
    }

    return 0;
}