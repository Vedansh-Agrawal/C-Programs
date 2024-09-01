#include <stdio.h>
#include <string.h>

int main()
{
    int K, L, m,j;

    scanf("%d %d %d", &L, &K, &m);
  

    char dna[L + 1];

    scanf("%s", dna);

    for (int i = 0; dna[i] != '\0'; i = i + K - m)
    {
        for (j = i; j < i + K && dna[j] != '\0'; j++)
        {
            printf("%c", dna[j]);
        }

        if (dna[j] == '\0')
        {
            break;
        }
       
        printf("\n");
    }

    return 0;
}

