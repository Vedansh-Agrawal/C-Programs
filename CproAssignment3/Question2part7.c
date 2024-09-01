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

float Newton(int polynomial[],float N)
{
    float x;

     x = N - (sub1(polynomial,N)/sub2(polynomial,N));

    if (x - N <= 0.0001 && x - N >= -0.0001)
    {
        return x;
    }

    else
    {
        
         return Newton(polynomial,x);
    }

}






int main()
{

    int polynomial[3];
    float max,x,y;
    
    for (int i = 0;i<3;i++)
    {
        scanf("%d",&polynomial[i]);
    }

    max = (float) -polynomial[1]/(2*polynomial[0]);

    max += 1;
    if (sub1(polynomial,max) == 0)
    {
        printf("%f %f",max - 2,max);
        return 0;
    }
    
    x = Newton(polynomial,max);

    max -= 2;

    y = Newton(polynomial,max);
    
    printf("%f %f",y,x);
   
    return 0;

}