#include<stdio.h>
#include<string.h>
#include<ctype.h>

//Initiate the main program with arguments
int main(int argc, char *argv[]){
    
    //Check if the number of command line arguments is not 2
    if(argc != 2){
        printf("Usage: ./substitution key\n");
        return 1;
    }
    
    int arg_len = strlen(argv[1]); 
    
    //Check if the second input is a string of 26 characters
    if(arg_len != 26){
        printf("Key must contain 26 characters\n");
        return 1;
    }
    
    //Check if all the string characters passed in the arg are alphabets
    for(int i=0; i<arg_len; i++){
        if(!isalpha(argv[1][i])){
            printf("All keys must be alphabets\n");
            return 1;
        }
        
        //Check for repitition of characters
        for(int j= i+1; j<arg_len; j++){
            if(argv[1][i]==argv[1][j]){
                printf("Repeated characters\n");
                return 1;
            }
        }
    }
    
    //Enter the text to be encrypted
    char text[100000];
    printf("Plaintext:  ");
    fgets(text, 100000, stdin);
    text[strlen(text)-1] = '\0';

    int text_len = strlen(text);

    printf("Ciphertext: ");
    
    //For every character in the strng use ASCII value subtraction to point at ith loc of cipher key
    //i.e for 'A'(ASCII 65) should be swapped with first char of the key(0th location)
    //then output upper or lower case depending on plain text
    for(int i=0; i<text_len; i++){
        if(isupper(text[i])){
            printf("%c", toupper(argv[1][text[i]-65]));  // A->0, B->1, C->2 ..... alphabets from plain text, numbers are location of key char
        }

        else if(islower(text[i])){
            printf("%c", tolower(argv[1][text[i]-97])); // Similarly a->0, b->1, c->2...Subtract 97 to get the correct location of key char
        }

        else{
            printf("%c", text[i]);
        }
    }
    //Print a newline after the loop finishes
    printf("\n");

}
