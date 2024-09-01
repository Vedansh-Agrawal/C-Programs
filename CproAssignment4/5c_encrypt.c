#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define N 127

int main()
{
    FILE *ptr, *ptr1, *ptr3;
    ptr = fopen("small_image.png", "r");
    ptr1 = fopen("key.txt", "w");
    ptr3 = fopen("enc.txt", "w");

    int xorg[N], x = 0, b, count = 0;
    int a = 128;
    char msg;

    srand(0);
    for (int i = 0; i < N; i++)
    {
        xorg[i] = rand() % 2; //generate key
    }

    for (int i = 0; i < N; i++)
    {
        fprintf(ptr1, "%d", xorg[i]); //print key
    }

    while (1)
    {
        msg = fgetc(ptr); // take each char

        if (feof(ptr))
        {
            break; //check each time for eof
        }

        for (int j = 7; j >= 0; j--)
        {
            b = msg & a; //a = 128 i.e 10000000, Hence b contains most significant bit
            b = b >> j;  // shifting the most significant bit to the right to make it 0 or 1

            x = x % 127;// x = 0
            if (x == 0)
            {
                xorg[x] = xorg[126] ^ xorg[x];
            }

            else
            {                                         // generating the next bits of the seed
                xorg[x] = xorg[x - 1] ^ xorg[x];
            }

            fprintf(ptr3, "%d", xorg[x] ^ b); // print the xor bit
            a = a / 2; // a = 128/2 i.e 01000000
            x++;
        }
        a = 128;//initializing a back to 128 for next char
    }

    fclose(ptr);
    fclose(ptr1);
    fclose(ptr3);

    return 0;
}