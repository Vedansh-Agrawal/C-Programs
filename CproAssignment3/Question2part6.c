#include <stdio.h>
#include <stdlib.h>

float sub(int polynomial[],float N)
{
    float x;

    x = (polynomial[0]*N*N) + (polynomial[1]*N) + (polynomial[2]);

    return x;
}

float bisectionMethod(int polynomial[],float N,float M)
{
    if (sub(polynomial,(N+M)/2) == 0)
    {
        return (N+M)/2;
    }

    else if (sub(polynomial,(N+M)/2)*sub(polynomial,M) < 0)
    {
        return bisectionMethod(polynomial,(N+M)/2,M);
    }

     else if (sub(polynomial,(N+M)/2)*sub(polynomial,N) < 0)
    {
        return bisectionMethod(polynomial,N,(N+M)/2);
    }

}

int main()
{

    int polynomial[3];
    float i,max,x,y;
    
    for (int i = 0;i<3;i++)
    {
        scanf("%d",&polynomial[i]);
    }

    max = (float) -polynomial[1]/(2*polynomial[0]);
    

    

    i = max;

    while (sub(polynomial,max)*sub(polynomial,i) >= 0)
    {
        i++;
    }

    

    x = bisectionMethod(polynomial,max,i);

    i = max;

     while (sub(polynomial,max)*sub(polynomial,i) >= 0)
    {
        i--;
    }

    y = bisectionMethod(polynomial,i,max);

    printf("%f %f",y,x);

    return 0;

}