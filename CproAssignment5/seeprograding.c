#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int binarySearch(int A[], int key, int l, int r)
{
    int mid;
    mid = (l + r) / 2;

    if (l > r)
    {
        return -1;
    }

    if (key == A[mid])
    {
        return mid;
    }

    if (key < A[mid])
    {
        return binarySearch(A, key, l, mid - 1);
    }

    else
    {
        return binarySearch(A, key, mid + 1, r);
    }
}

int main()
{
    int n, m, count = 0;

    scanf("%d %d", &n, &m);

    int A[n], B[m];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &B[i]);
    }

    
    qsort(B, m,sizeof(int),cmpfunc);

    for (int i = 0; i < n; i++)
    {
        if (binarySearch(B, A[i], 0, m - 1) != -1)
        {
            count += 1;
        }
    }

    printf("%d",count);
    return 0;
}