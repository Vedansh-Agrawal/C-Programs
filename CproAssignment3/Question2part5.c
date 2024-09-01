//actual
#include <math.h>
#include <stdio.h>


void root(double a,double b,double c) 

{
    double discriminant, root1, root2, realPart, imagPart;
    

    discriminant = b * b - 4 * a * c;

    
    if (discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        imagPart = 0;
        printf("%lf %lf\n %lf %lf\n", root1,imagPart, root2,imagPart);
    }


    else if (discriminant == 0) {
        root1 = root2 = -b / (2 * a);
        imagPart = 0;
        printf("%lf %lf\n %lf %lf\n", root1,imagPart,root2,imagPart);
    }

    
    else {
        realPart = -b / (2 * a);
        imagPart = sqrt(-discriminant) / (2 * a);
        printf("%lf %lf \n%lf %lf\n", realPart, imagPart, realPart, -imagPart);
    }


} 


int main()
{
    int N;
    scanf("%d",&N);

    double equations[N][3];

    for (int i = 0;i<N;i++)
    {
        for(int j =0;j<3;j++)
        {
            scanf("%lf",&equations[i][j]);
        }
    }

    for (int i = 0;i<N;i++)
    {
        root(equations[i][0],equations[i][1],equations[i][2]);
    }
    return 0;
}
