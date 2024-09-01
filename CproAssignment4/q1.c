#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int A[6],roll;
    for (int i = 0;i<6;i++)
    {
        A[i] = 0;
    }

  

    for (int i = 0;i<1000000;i++)
    {
       roll = rand() % 7;
       while (roll == 0)
       {
           roll = rand() % 7;
       }
       A[roll - 1] += 1;
    }

    for (int i = 0;i<6;i++)
    {
        printf("%d : %d\n",i+1,A[i]);
    }

    return 0;
}