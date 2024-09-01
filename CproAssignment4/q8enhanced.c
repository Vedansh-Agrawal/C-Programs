#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    char str1[16], str2[16];
    int retval1, retval2;

    FILE *ptr, *ptr1, *ptr2;

    ptr = fopen(argv[3], "w");
    ptr1 = fopen(argv[1], "r");
    ptr2 = fopen(argv[2], "r");

    retval1 = fscanf(ptr1, "%s", str1);
    retval2 = fscanf(ptr2, "%s", str2);

    while (1)
    {
        if (retval1 == EOF)
        {
            fprintf(ptr, "%s\n", str2);
            while (fscanf(ptr2, "%s", str2) != EOF)
            {
                fprintf(ptr, "%s\n", str2);
            }
            break;
        }

        else if (retval2 == EOF)
        {
            fprintf(ptr, "%s\n", str1);
            while (fscanf(ptr1, "%s", str1) != EOF)
            {
                fprintf(ptr, "%s\n", str1);
            }
            break;
        }

        else if (strcmp(str1, str2) <= 0)
        {
            fprintf(ptr, "%s\n", str1);
            retval1 = fscanf(ptr1, "%s", str1);
        }

        else
        {
            fprintf(ptr, "%s\n", str2);
            retval2 = fscanf(ptr2, "%s", str2);
        }
    }
}