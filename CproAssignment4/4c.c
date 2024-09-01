#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *ptr, *ptr1, *ptr2;

    ptr = fopen(argv[1], "r");
    ptr1 = fopen(argv[2], "r");
    ptr2 = fopen(argv[3], "w");

    long double mean, Marks, percent;
    long long int N = 0, count = 0;

    fscanf(ptr1, "%Lf", &mean);

    while (fscanf(ptr, "%Lf", &Marks) != EOF)
    {
        if (Marks >= 0.8 * mean && Marks <= 1.2 * mean)
        {
            count++;
        }

        N++;
    }
    percent = (long double)count / N;

    fprintf(ptr2, "%Lf", percent * 100);

    fclose(ptr);
    fclose(ptr1);
    fclose(ptr2);

    return 0;
}