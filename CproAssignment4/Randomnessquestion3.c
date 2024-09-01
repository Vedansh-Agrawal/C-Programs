#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define INTERVAL 1000000


int main()
{
    long long int interval = 100;
    double x , y , circle, pi,total = 0,circlepoints = 0;

    srand(time(0));

    for (int i = 0;i<10;i++)
    {
        for (int j = 0;j<interval;j++)
        {
          x = rand() % (INTERVAL + 1);
          x = (double) x / INTERVAL;

          y = rand() % (INTERVAL + 1);
          y = (double) y / INTERVAL;

          circle = (x*x) + (y*y);

          if (circle <= 1)
          {
              circlepoints += 1;
          }

          total += 1;
        }

        pi = (double) 4*circlepoints/total;
        printf("%lld points we estimate pi to be %lf\n",interval,pi);
        circlepoints = 0;
        total = 0;
        interval = interval * 5;
    }

    return 0 ;


}