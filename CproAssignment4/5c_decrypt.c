#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define N 127

int main()
{
    FILE *ptr, *ptr1, *ptr2;

    ptr = fopen("enc.txt", "r");
    ptr1 = fopen("key.txt", "r");
    ptr2 = fopen("ans.png", "w");

    char decrypt[800000], xorg[N + 1];
    int x = 0, b;
    char a = 0;

    for (int i = 0; i < N + 1; i++)
    {
        fscanf(ptr1, "%s", &xorg[i]);
        xorg[i] = xorg[i] - '0';
    }

    fscanf(ptr, "%s", decrypt);

    for (int i = 0; decrypt[i] != '\0'; i = i + 8)
    {
        for (int j = 7; j >= 0; j--)
        {
            x = (i + 7 - j) % 127;
            if (x == 0)
            {
                xorg[x] = xorg[126] ^ xorg[x];
            }

            else
            {
                xorg[x] = xorg[x - 1] ^ xorg[x];
            }

            b = ((decrypt[i + 7 - j] - '0') ^ xorg[x]);
            b = b << j;
            a = a | b;
        }
        fprintf(ptr2, "%c", a);
        a = 0;
    }

    fclose(ptr);
    fclose(ptr1);
    fclose(ptr2);

    return 0;
}