#include<stdio.h>
#include <math.h>


int main()

{
  long long int  N;
  scanf("%lld",&N);

  int Marks[N],marks[N];
  

  
  for (int i = 0;i<N;i++)
  {
      
      scanf("%d",&Marks[i]);
       if (Marks[i] > 100)
    {
      printf("INVALID INPUT");
      return 0;
    }
    
   marks[i] = Marks[i];
  }
  
  for (int i = 0;i<N-1;i++)
  {
      for (int j = i + 1;j<N;j++)
      {
       if (Marks[i] > Marks[j])
       {
           Marks[j] = 0;
       }
       
       else
       {
           Marks[i] = 0;
           break;
       }
      }
  }
  
   for (int i = 0;i<N-1;i++)
  {
      for (int j = i + 1;j<N;j++)
      {
       if (marks[i] < marks[j])
       {
          marks[j] = 101;
       }
       
       else
       {
           marks[i] = 101;
           break;
       }
      }
  }
  
  for (int i = 0;i<N;i++)
  {
      if (Marks[i] != 0)
      {
          printf("%d\n",Marks[i]);
      }
      if (marks[i] != 101)
      {
          printf("%d\n",marks[i]);
      }
  }

  
  return 0;
}