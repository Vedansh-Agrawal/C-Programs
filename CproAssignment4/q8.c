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

int main(int argc,char **argv)
{

    FILE *ptr, *ptr1, *ptr2;

    ptr = fopen(argv[3], "w");
    ptr1 = fopen(argv[1], "r");
    ptr2 = fopen(argv[2], "r");

    char *words[2000000], temp[16];
    int i = 0, j = 1;

    while (fscanf(ptr1, "%s", temp) != EOF)
    {
        words[i] = (char *)malloc(strlen(temp) + 1);
        strcpy(words[i], temp);
        i++;
    }

    while (fscanf(ptr2, "%s", temp) != EOF)
    {
        words[i] = (char *)malloc(strlen(temp) + 1);
        strcpy(words[i], temp);
        i++;
    }

    sort(words, i);

    fprintf(ptr, "%s\n", words[0]);

    for (int k = 1; k < i; k++)
    {
        if (strcmp(words[k], words[k - 1]) != 0)
        {
            fprintf(ptr, "%s\n", words[k]);
        }

        else
        {
            continue;
        }
    }

    return 0;
}