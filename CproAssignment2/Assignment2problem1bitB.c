#include<stdio.h>
#include <math.h>


int main()

{
  long long int N;
  double Deviation,mean = 0,variance = 0;
 
  scanf("%lld",&N);

  int Marks[N];
  
  for (int i = 0;i<N;i++)
  {
      
      scanf("%d",&Marks[i]);
      
    
    mean += Marks[i];
    
        
    
  }
  
mean = mean / N;

for (int i = 0;i<N;i++)
{
    variance += (mean - Marks[i])*(mean - Marks[i]);
}
variance = variance / N;
Deviation = sqrt(variance);

 for (int i = 0;i<N;i++)
  {
    if (Marks[i] > 100)
    {
      printf("INVALID INPUT");
      return 0;
    }
  }

printf("%lf %lf %lf",mean,variance,Deviation);


  
  return 0;
}