#include<stdio.h>


int main()

{

  long long int N;
  float P;
  long long int  count = 0;
  double ans;

  scanf("%lld %f",&N,&P);

  double Marks[N];
 
  
  for (int i = 0;i<N;i++)
  {
     
      scanf("%lf",&Marks[i]);
    
    if (Marks[i] >= P)
    {
        count += 1;
    }
  }

  for (int i = 0;i<N;i++)
  {
    if (Marks[i] > 100)
    {
      printf("INVALID INPUT");
      return 0;
    }
  }

  ans = (double) count*100/N;
  
  printf("%lf",ans);
  
  return 0;
}