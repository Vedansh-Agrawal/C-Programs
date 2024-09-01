#include <stdio.h>

int prettyPrint(int arr[],int N,int n)
{
   int count = 0,x = 0;

   for (int i = 0;i<N+1;i++)
   {
       if (arr[i] == 0)
       {
           x += 1;
       }
   }

    if (N == 0)
    {
        printf("%d",arr[0]);
        return 0;
    }
    
    if (arr[0] != 0 && x == N)
    {
        printf("%d",arr[0]);
        return 0;
    }


    for (int i = N;i>=0;i--)
    {
      if (i == N)
      {
          if (arr[i] == 0)
          {
              count += 1;
              N--;
              continue;
          }

          else if (arr[i] == -1)
          {
              printf("-");
          }

          else if (arr[i] != 1)
          {
              printf("%d",arr[i]);
          }
      }

      if (i<N && i != 0)
      {
          if (arr[i] == 0)
          {
              count += 1;
              continue;
          }

          else if (arr[i] == 1)
          {
              printf(" + ");
          }

          else if (arr[i] == -1)
          {
              printf(" - ");
          }

          else if (arr[i] > 0)
          {
              printf(" + %d",arr[i]);
          }

          else
          {
              printf(" - %d",-arr[i]);
          }
      }

      if (i == 0)
      {
          if (arr[i] == 0)
          {
              count += 1;
              continue;
          }

          else if (arr[i]>0)
          {
              printf(" + %d",arr[i]);
          }

          else
          {
              printf(" - %d",-arr[i]);
          }
      }

      if (i>1)
      {
          printf("x^%d",i);
      }

      if (i == 1)
      {
          printf("x");
      }
    }

    if (count == n)
    {
        printf("0");
    }
    return 0;
}

int main()
{
    int N,n;

    scanf("%d",&n);

    N = n - 1;

    int arr[N + 1],dif[N];

    for (int i = 0;i<N+1;i++)
    {
        scanf("%d",&arr[i]);
    }

    for (int i = N;i>0;i--)
    {
       dif[i - 1] = i*arr[i];
    }

    prettyPrint(dif , N - 1,N);

    return 0;
}