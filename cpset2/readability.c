#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

//Begin the main program without any parameters
int main(void){
    
    //Initialise letters, words and sentences. Remember that words = spaces + 1
    int letters=0, sentences=0;
    int words=1;
    
    //Define the string variable
    char str[100000];
    
    //Ask for the text input
    printf("Text : ");
    
    //Use fgets to read the text. Remember that scanf cannot read spaces and to set
    //last but one character of str to '\0' to prevent new line as fgets sets it to '\n'    
    fgets(str, 100000, stdin);
    str[strlen(str)-1] = '\0';
    
    //Store the string length in a variable
    int text_length = strlen(str);

    //For loop for counting the number of alphabets sifting through the characters
    //using 'isalpa()' function
    for(int i=0; i < text_length; i++){
        if(isalpha(str[i])){
            letters++;
        }
    }

    //For loop for counting number of words sifting through no of blank space characters
    //in the string array
    for(int i=0; i<text_length; i++){
        if(isspace(str[i])){
            words++;
        }
    } 
    
    //For loop to count number of sentences using '.', '!' & '?' chars as end signifier
    for(int i=0; i<text_length; i++){
        if(str[i]=='.' || str[i]== '?' || str[i]=='!'){
            sentences++;
        } 
    }
    
    //Use the Coleman-Liau algorithm to find out the grade of the text and output based on the level
    float grade_f = 0.0588*((letters* 100)/words) -0.296*((sentences*100)/words) -15.8;
    int grade = round(grade_f);

    if(grade < 1){
        printf("Before grade 1\n");
    }

    else if(grade > 16){
        printf("Grade 16+\n");
    }

    else{
        printf("Grade : %i\n", grade);
    }
    
}
