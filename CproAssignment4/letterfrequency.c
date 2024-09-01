#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    FILE *ptr, *ptr1;

    ptr = fopen(argv[1], "w");

    char word[21];
    int count[62];

    for (int i = 0; i < 62; i++)
    {
        count[i] = 0;
    }

    for (int i = 2; i < argc; i++)
    {
        ptr1 = fopen(argv[i], "r");
        while (fscanf(ptr1, "%s", word) != EOF)
        {
            for (int i = 0; word[i] != '\0'; i++)
            {
                if (word[i] >= '0' && word[i] <= '9')
                {
                    count[word[i] - '0'] += 1;
                }

                if (word[i] >= 'A' && word[i] <= 'Z')
                {
                    count[word[i] - '7'] += 1;
                }

                if (word[i] >= 'a' && word[i] <= 'z')
                {
                    count[word[i] - '='] += 1;
                }
            }
        }
    }

    for (int i = 0; i < 62; i++)
    {
        if (i <= 9)
        {
            fprintf(ptr, "%c:%d\n", i + '0', count[i]);
        }

        else if (i <= 35)
        {
            fprintf(ptr, "%c:%d\n", i + '7', count[i]);
        }

        else
        {
            fprintf(ptr, "%c:%d\n", i + '=', count[i]);
        }
    }
    return 0;
}