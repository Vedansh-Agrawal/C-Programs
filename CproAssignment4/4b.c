/*#include <stdio.h>

int main(int argc,char **argv)
{
    FILE *ptr, *ptr1, *ptr2;

    ptr = fopen(argv[1], "r");
    ptr1 = fopen(argv[2], "r");
    ptr2 = fopen(argv[3], "w");

    long long int N = 0;
    long double mean = 0, variance = 0, Marks;

    fscanf(ptr1, "%Lf", &mean);

    while (fscanf(ptr, "%Lf", &Marks) != EOF)
    {
        variance += (Marks - mean) * (Marks - mean);
        N++;
    }

    variance = variance / N;
    fprintf(ptr2,"%Lf",variance);

    fclose(ptr);
    fclose(ptr1);
    fclose(ptr2);

    return 0;
}*/

#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *input;
    input = fopen("data.txt", "r");
    FILE *output;
    output = fopen("ans.txt", "w");
    FILE *Mean;
    Mean = fopen("ans4.txt", "r");
    double num = 0;
    int n = 0;
    
    
    double var = 0, variance = 0;
    double mean = 0;
    fscanf(Mean,"%lf",&mean);

    while (fscanf(input, "%lf\n", &num) != EOF)
    {
        var += ((num - mean) * (num - mean));   
        n++;    
    }
     variance = var / (n);

    
    fprintf(output, "Actual Variance : %lf\n", variance);

    fclose(input);
    fclose(output);
    fclose(Mean);
    return 0;
}