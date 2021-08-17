#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(int argc, char *argv[]){
    
    if(argc!=2){
        printf("Usage ./caesar key\n");
        return 1;
    }

    int str_len = strlen(argv[1]);

    for(int i=0; i<str_len; i++){
        if(!isdigit(argv[1][i])){
            printf("Usage ./caesar key\n");
            return 1;
        }
    }
    
    int key = atoi(argv[1]);

    char text[100000];
    printf("Plaintext : ");
    fgets(text, 100000, stdin);
    text[strlen(text)-1] ='\0';
    int text_len = strlen(text);

    printf("Ciphertext: ");
    for(int i =0; i< text_len; i++){
        if(isupper(text[i])){
            printf("%c", (((text[i]-65) + key) % 26) + 65);
        }

        else if(islower(text[i])){
            printf("%c", (((text[i]-97) + key) % 26) + 97);
        }

        else{
            printf("%c", text[i]);
        }
                
    }

    printf("\n");

}

