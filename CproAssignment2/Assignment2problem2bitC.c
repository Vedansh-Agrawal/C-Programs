#include <stdio.h>
int main()
{
    int gender,x = 0;
    
    
    long long int n,m;

    scanf("%lld %lld",&n,&m);

    int male[n],female[n];
    
    for (int i = 0;i<n;i++)
    {
        male[i] = 0;
        female[i] = 0;
    }
    
 
    
    for (int i = 0; i<n;i++)
    {
        for (int j = 0; j<m;j++)
        {
            
            scanf("%d",&gender);
            
            

             if (gender == 0)
            {
                male[i] += 1;
            }

            if (gender == 1)
            {
                female[i] += 1;
            }
            
        }
    }
    
   for (int i = 0;i<n - 1;i++)
  {
      for (int j = i + 1;j<n;j++)
      {
       if (male[i] > male[j])
       {
           male[j] = 0;
       }
       
       else if (male[i] < male[j])
       {
           male[i] = 0;
           break;
       }
      }
  }

   for (int i = 0;i<n - 1;i++)
  {
      for (int j = i + 1;j<n;j++)
      {
       if (female[i] > female[j])
       {
           female[j] = 0;
       }
       
       else if (female[i] < female[j])
       {
           female[i] = 0;
           break;
       }
      }
  }
    
     for (int i = 0;i<n;i++)
  {
      if (male[i] != 0)
      {
          
          printf("%d ",i + 1);
          break;
      }

      if (male[i] == 0)
      {
          x++;
      }
  }

  if (x == n)
  {
      printf("-1 ");
      
  }
  x = 0;

    for (int i = 0;i<n;i++)
  {
      if (female[i] != 0)
      {
          printf("%d",i + 1);
          
          break;
      }

      if (male[i] == 0)
      {
          x++;
      }
  }

  if (x == n)
{
    printf("-1");
}
   
    
    return 0;
}