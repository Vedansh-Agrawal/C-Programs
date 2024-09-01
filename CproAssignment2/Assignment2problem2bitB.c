#include <stdio.h>
#define FLOORS 3
#define ROOMS 3
int main()
{
    int gender;
    long long int female = 0,male = 0;
    double ans,ans1;
    long long int n,m;

    scanf("%lld %lld",&n,&m);

    
    
    for (int i = 0; i<n;i++)
    {
        for (int j = 0; j<m;j++)
        {
           
            scanf("%d",&gender);
            
           

             if (gender == 0)
            {
                male += 1;
                
            }
            
            else if (gender == 1)
            {
                female += 1;
            }
        }
 ans =(float) male*100/m;
  ans1 =(float) female*100/m;

 printf("%lf %lf\n",ans,ans1);
    male = 0;
female = 0;
    }
    

   
    
    return 0;
}