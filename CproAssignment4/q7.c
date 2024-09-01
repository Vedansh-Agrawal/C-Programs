#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(char *words[], int N)
{
    char temp[21];

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (strcmp(words[i], words[j]) > 0)
            {
                strcpy(temp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], temp);
            }
        }
    }
}

int main(int argc, char **argv)
{

    FILE *ptr, *ptr1;

    ptr = fopen(argv[1], "w");

    char *words[(argc-2)*1000], temp[21];
    int  i = 0, j = 1;

    

    for (int k = 2; k < argc; k++)
    {
        ptr1 = fopen(argv[i], "r");

        while (fscanf(ptr1, "%s", temp) != EOF)
        {
            words[i] = (char *)malloc(strlen(temp) + 1);
            strcpy(words[i], temp);
            i++;
        }
    }

    char *ans[i];
    int count[i];

    sort(words, i);

    ans[0] = (char *)malloc(strlen(words[0]) + 1);

    strcpy(ans[0], words[0]);

    count[0]++;

    for (int k = 1; k < i; k++)
    {
        if (strcmp(words[k], words[k - 1]) != 0)
        {
            ans[j] = (char *)malloc(strlen(words[k]) + 1);
            strcpy(ans[j], words[k]);
            count[j]++;
            j++;
        }

        else
        {
            count[j - 1]++;
        }
    }

    for (int k = 0; k < j; k++)
    {
        fprintf(ptr, "%s:%d\n", ans[k], count[k]);
    }

    return 0;
}