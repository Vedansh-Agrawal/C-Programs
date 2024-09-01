#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int A[11],roll,roll1,roll2;
    for (int i = 0;i<11;i++)
    {
        A[i] = 0;
    }

  

    for (int i = 0;i<1000000;i++)
    {
       roll1 = rand() % 7;
       while (roll1 == 0)
       {
           roll1 = rand() % 7;
       }

       roll2 = rand() % 7;
       while (roll2 == 0)
       {
           roll2 = rand() % 7;
       }

       roll = roll1 + roll2;

       A[roll - 2] += 1;
    }

    for (int i = 0;i<11;i++)
    {
        printf("%d : %d\n",i+2,A[i]);
    }

    return 0;
}