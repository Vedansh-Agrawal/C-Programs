#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 127

int main()
{
    int xorg[N];
    int zerozero = 0, zeroone = 0, x, count = 0, zero = 0, one = 0;

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

            if (xorg[x] == 0)
            {
                if (xorg[126] == 0)
                {
                    zerozero++;
                }

                if (xorg[126] == 1)
                {
                    zeroone++;
                }
            }
        }

        else
        {
            xorg[x] = xorg[x - 1] ^ xorg[x];

            if (xorg[x] == 0)
            {
                if (xorg[x - 1] == 0)
                {
                    zerozero++;
                }

                if (xorg[x - 1] == 1)
                {
                    zeroone++;
                }
            }
        }

        if (xorg[x] == 1)
        {
            one++;
        }

        else
        {
            zero++;
        }
    }

    printf("probability for 0 after 0 = %lf\n", (double)zerozero / zero);
    printf("probability for 0 after 1 = %lf\n", (double)zeroone / one);

    zerozero = 0;
    zero = 0;
    zeroone = 0;
    one = 0;

    for (int i = N + 1; i < 1000000; i++)
    {
        x = i % 127;
        if (x == 0)
        {
            xorg[x] = rand() % 2;

            if (xorg[x] == 0)
            {
                if (xorg[126] == 0)
                {
                    zerozero++;
                }

                if (xorg[126] == 1)
                {
                    zeroone++;
                }
            }
        }

        else
        {
            xorg[x] = rand() % 2;

            if (xorg[x] == 0)
            {
                if (xorg[x - 1] == 0)
                {
                    zerozero++;
                }

                if (xorg[x - 1] == 1)
                {
                    zeroone++;
                }
            }
        }

        if (xorg[x] == 1)
        {
            one++;
        }

        else
        {
            zero++;
        }
    }

    printf("probability for 0 after 0 using rand()= %lf\n", (double)zerozero / zero);
    printf("probability for 0 after 1 using rand() = %lf\n", (double)zeroone / one);

    return 0;
}