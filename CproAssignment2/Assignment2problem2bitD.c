#include <stdio.h> 
int main()
{
    int gender;
    long long int female = 0,male = 0,empty = 0;;
    
    long long int m,n;

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

            else
            {
                empty += 1;
            }
        }
    }

    for (int i = empty ;i>0;i--)
    {
        if (male % m != 0)
        {
            male += 1;
        }

        else if (female % m != 0)
        {
            female += 1;
        }
    }




    
   if (male % m == 0 && female % m == 0)
   {
       printf("FANCY");
   }

   else 
   {
       printf("NOT FANCY");
   }
    
    return 0;
}