#include <stdio.h>

int lds(int N, int height[], int start)
{
    int index = 0, curr = 1, max = 0;

    for (int i = start; i < N - 1; i++)
    {
        index = i;
        for (int j = i + 1; j < N; j++)
        {
            if (height[index] > height[j])
            {
                curr++;
                index = j;
            }
        }
        if (curr > max)
        {
            max = curr;
        }
        curr = 1;
    }
    return max;
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    int height[N];
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &height[i]);
    }

    int maxsum = 0,maxsum1 = 0;
    if (M == 1)
    {
        maxsum = lds(N, height, 1);
        printf("%d", maxsum + 1);
    }

    else if (M >= N)
    {
        maxsum = lds(N, height, 0);
        printf("%d", maxsum);
    }

    else
    {
        maxsum = lds(M, height, 0);
        maxsum1 = lds(N, height, M);
        printf("%d %d", maxsum,maxsum1);
    }

    return 0;
}
