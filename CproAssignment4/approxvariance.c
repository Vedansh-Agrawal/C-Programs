/*#include <stdio.h>

int main(int argc, char *argv[])

{
    FILE *ptr, *ptr1, *ptr2;

    ptr = fopen(argv[1], "r");
    ptr1 = fopen(argv[2], "w");

    long long int N = 0;
    long double mean = 0, variance = 0, x = 0,Marks;
    

    while (fscanf(ptr, "%Lf", &Marks) != EOF)
    {

        N++;

        x += Marks;
        mean = x / N;

        variance += ((Marks - mean) * (Marks - mean));
        fprintf(ptr1, "%Lf\n", variance / (N - 1));
    }

    fclose(ptr);
    fclose(ptr1);

    return 0;
}*/

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
    FILE *input;
    input = fopen("data.txt", "r");
    FILE *output;
    output = fopen("ans4b.txt", "w");
    FILE *Mean;
    Mean = fopen("ans4.txt", "w");
    double num = 0;
    int n = 0;
    double sum = 0;
    double sum_of_square = 0, square_of_sum = 0;
    double var = 0, variance = 0;
    double mean = 0;

    while (fscanf(input, "%lf\n", &num) != EOF)
    {
        sum += num;
        n++;
        mean = sum / n;
        
        var += ((num - mean) * (num - mean));
        if (n == 1)
        {
            variance = var / n;
        }
        else
        {
            variance = var / (n - 1);
        }

        fprintf(output, "%d : %lf\n", n, variance);
    }

    fprintf(Mean, "Mean : %lf\n",  mean);

    fclose(input);
    fclose(output);
    fclose(Mean);
    return 0;
}