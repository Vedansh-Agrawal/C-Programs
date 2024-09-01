#include <stdio.h>

int main(int argc, char *argv[])

{
    FILE *ptr, *ptr1;

    ptr = fopen(argv[1], "r");
    ptr1 = fopen(argv[2], "w");

    long double mean = 0;
    long long int N = 0;

    long double Marks;

    while (fscanf(ptr, "%Lf", &Marks) != EOF)
    {
        mean += Marks;
        N++;
    }

    mean = mean / N;

    fprintf(ptr1, "%Lf", mean);

    fclose(ptr);
    fclose(ptr1);

    return 0;
}