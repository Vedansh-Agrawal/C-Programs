#include <stdio.h> 
int main()
{
    int gender;
    long long int female = 0,male = 0;
    double ans,ans1;
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
        }
    }
    
    ans = (float) male*100/(n*m);
    ans1 = (float) female*100/(n*m);
    
    printf("%lf ",ans);
    printf("%lf",ans1);
            
    
    return 0;
}