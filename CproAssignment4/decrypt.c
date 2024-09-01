#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main(int argc, char ** argv){
    int key[127] = {0};
    int input;
    int i = 0;

    FILE * fp = fopen(argv[1], "r");

    while(fscanf(fp, "%1d", &input) != EOF){
        key[i++] = input;
    }

    fclose(fp);

    FILE * enc = fopen(argv[2] , "r");
    FILE * ans2 = fopen(argv[3] , "w");

    int bin[8];
    int retval = 0;
    int x = 127;

    while(retval != -1){
        for(int i = 0; i < 8 ; i++){
            retval = fscanf(enc, "%1d", &bin[i]);

            key[x % 127] = key[(x - 1)% 127] ^ key[(x - 127) % 127];
            bin[i] = key[x % 127] ^ bin[i];
            x++;
        }

        int ascii = 0;
        for(int i = 0;i < 8; i++){
        ascii += bin[i] * pow(2,7 - i);
        }

        if(retval != -1){
        fprintf(ans2, "%c", ascii);
        }

    }

    fclose(enc);
    fclose(ans2);

}