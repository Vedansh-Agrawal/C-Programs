#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 127

int main()
{
    int xorg[N];
    int zero = 0, one = 0, x;

    srand(time(0));
    for (int i = 0; i < N; i++)
    {
        xorg[i] = rand() % 2;
    }

    for (int i = N + 1; i < 1000000; i++)
    {
        x = i % 127;
        if (x == 0)
        {
            xorg[x] = xorg[126] ^ xorg[x];
        }

        else
        {
            xorg[x] = xorg[x - 1] ^ xorg[x];
        }

        if (xorg[x] == 0)
        {
            zero += 1;
        }

        else
        {
            one += 1;
        }
    }

    printf("probability for 0 = %lf\n", (double)zero / (zero + one));
    printf("probability for 1 = %lf\n", (double)one / (zero + one));

    zero = 0;
    one = 0;

    for (int i = N + 1; i < 1000000; i++)
    {
       xorg[x] = rand() % 2;

        if (xorg[x] == 0)
        {
            zero += 1;
        }

        else
        {
            one += 1;
        }
    }

    printf("probability for 0 with rand() = %lf\n", (double)zero / (zero + one));
    printf("probability for 1 with rand() = %lf\n", (double)one / (zero + one));

    return 0;
}