#include <stdio.h>
#include <stdlib.h>

float sub1(int polynomial[],float N)
{
    float z;

    z = (polynomial[0]*N*N) + (polynomial[1]*N) + (polynomial[2]);

    return z;
}

float sub2(int polynomial[],float N)
{
    float a;

    a = (polynomial[0]*2*N) + (polynomial[1]);

    return a;
}

float Newton(int polynomial[],float N, float M)
{
    float x;

     x = M - (sub1(polynomial,M)/((sub1(polynomial,M) - sub1(polynomial,N))/(M - N)));

    if (x - M <= 0.0001 && x - M >= -0.0001)
    {
        return x;
    }

    else
    {
        
         return Newton(polynomial,M,x);
    }

}






int main()
{

    int polynomial[3];
    float max,x,y,Max;
    
    for (int i = 0;i<3;i++)
    {
        scanf("%d",&polynomial[i]);
    }

    max = (float) -polynomial[1]/(2*polynomial[0]);

    max += 1;
    Max = max + 1;

    if (sub1(polynomial,max) == 0)
    {
        printf("%f %f",max - 2,max);
        return 0;
    }

    if (sub1(polynomial,Max) == 0)
    {
        printf("%f %f",Max - 4,Max);
    }
    
    x = Newton(polynomial,max,Max);

    max -= 2;
    Max -= 4;

    y = Newton(polynomial,Max,max);
    
    printf("%f %f",y,x);
   
    return 0;

}