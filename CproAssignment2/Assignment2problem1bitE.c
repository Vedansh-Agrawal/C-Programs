#include<stdio.h>
#include <math.h>


int main()

{
  long long int N;
  scanf("%lld",&N);
  
  int upperlimit = 9, lowerlimit = 0;
  int Marks[N];
 int marks[11];
  
  for (int i = 0;i<11;i++)
  {
      marks[i] = 0;
  }
 
 
  
  for (int i = 0;i<N;i++)
  {
      
      scanf("%d",&Marks[i]);
        if (Marks[i] > 100)
    {
      printf("INVALID INPUT");
      return 0;
    }
    
  
  }
  
  for (int j = 0;j<10;j++)
  {
      for (int i = 0;i<N;i++)
      
      {
     
          if (Marks[i] >= lowerlimit && Marks[i] <= upperlimit)
          {
              marks[j] += 1;
          }
      
      }
      
      lowerlimit += 10;
      upperlimit += 10;
  }
  
  lowerlimit = 0;
  upperlimit = 9;
  
  for (int i = 0;i<N;i++)
  {
      if (Marks[i] == 100)
      {
          marks[10] += 1;
      }
  }
  
  for (int i = 0;i<10;i++)
  {
      printf("%d ",marks[i]);
      
  }
  
  printf("%d",marks[10]);
  
  
  
 
  return 0;
}