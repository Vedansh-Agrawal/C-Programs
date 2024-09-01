#include<stdio.h>
#include <math.h>


int main()

{
  long long int N;
  double Deviation,mean = 0,variance = 0;
  scanf("%lld",&N);
  int Ans[N];

  int Marks[N];
  
  
  
  for (int i = 0;i<N;i++)
  {
     
      scanf("%d",&Marks[i]);
      Ans[i] = 0;
      if (Marks[i] > 100)
    {
      printf("INVALID INPUT");
      return 0;
    }
     
    
    mean += Marks[i];
    
        
    
  }
  
mean = mean / N;

for (int i = 0;i<N;i++)
{
    variance += (mean - Marks[i])*(mean - Marks[i]);
}
variance = variance / N;
Deviation = sqrt(variance);


for (int j = 0; j<N;j++)
{
  for (int i = 0;i<N;i++)
  {
     if (Marks[i] >= mean - (j + 1)*Deviation && Marks[i] <= mean + (j + 1)*Deviation)
     {
       Ans[j] += 1;
     }
  } 

  if (Ans[j] == Ans[j - 1])
  {
    break;
  }
  printf("%d ",Ans[j]);
}







printf("0");


  
  return 0;
}