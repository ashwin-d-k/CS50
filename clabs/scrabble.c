#include<stdio.h>
#include<string.h>
#include<ctype.h>

//Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

//Prototype function declaration
int compute_score(char word[]);

//Function to compute the score of an input word using points table as reference 
int compute_score(char word[]){
    //Initialize the sum of letters to '0' and store length of the word called    
    int letter_sum =0, str_l =strlen(word);
    
    //Go through the entire word checking for case & punctuations and summing up based on points table 
    for(int i=0; i < str_l; i++){
    
        if(isupper(word[i])){
        
            letter_sum = letter_sum + POINTS[word[i] - 65]; //if uppercase deduct 65 from the ascii value to point to loc
        }

        else if(islower(word[i])){

            letter_sum = letter_sum + POINTS[word[i] - 97]; //if lowercase deduct 97 from ascii value to oint to loc
        }

        else {

            letter_sum = letter_sum; //no change if string element not an alphabet
        }

    }
    return letter_sum;
}

//Start the main function
int main(void){
    
    //Declare the two character arrays
    char word_1[20], word_2[20];
   
    //Ask user input for word 1
    printf("Player 1: ");
    fgets(word_1, 20, stdin);
    word_1[strlen(word_1)-1] = '\0';
    
    //Ask user input for word 2
    printf("Player 2: ");
    fgets(word_2, 20, stdin);
    word_2[strlen(word_2)-1] = '\0';
    
    //Call the compute_score function to calculate scores of both words and store them
    int score_1 = compute_score(word_1);
    int score_2 = compute_score(word_2);
    
    printf("\n");
    //Print both the scores
    printf("Score of Player 1 word : %i\n", score_1);
    printf("Score of Player 2 word : %i\n", score_2);
    
    printf("\n");

    //Print the comparison of the two scores and winning player
    if(score_1 > score_2){
        printf("Player 1 wins!\n");
    }

    else if(score_2 > score_1){
        printf("Player 2 wins!\n");
    }

    else{
        printf("Tie!\n");
    }

}
