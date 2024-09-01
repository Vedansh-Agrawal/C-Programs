#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//encrypt funtion.
void encrypt(FILE *msg, int key[], FILE* ans){

    int input;
    int bin[8];
    int bit;
    int x = 127;

    while(fscanf(msg, "%c", &input) != EOF){

        for(int i = 7;i >= 0;i--){
        bin[i] = input % 2;
        input = input/2;
        }
        
       int y;
        for(int i = 0; i < 8;i++){

            key[x % 127] = key[(x - 1)% 127] ^ key[(x - 127) % 127];
            y = key[x % 127] ^ bin[i];
            x++;
            fprintf(ans, "%d", y);

        }
    }
}


int main(int argc, char **argv){

    int key[127];
    srand(time(0));

    FILE * keyfile = fopen(argv[2], "w");

    for(int i = 0;i < 127;i++){

    key[i] = rand() % 2;
    fprintf(keyfile, "%d",key[i]);
    }
    fclose(keyfile);

    FILE * msg = fopen(argv[1], "r");
    FILE * ans = fopen(argv[3], "w");
    encrypt(msg,key,ans);

    fclose(msg);
    fclose(ans);

    return 0;
}
