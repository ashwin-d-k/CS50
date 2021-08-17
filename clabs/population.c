#include<stdio.h>

//Call the main function
int main(void){

    //Declare the variables and initialize the years argument
    int start_size, end_size, years = 0;

    //Prompt for user input for starting population size until it is greater than 9
    do{
        printf("Start size: ");
        scanf("%d", &start_size);    
    }
    while(start_size<9);

    //Prompt for user input for target population size until it's greater than initial size
    do{ 
        printf("End size: ");
        scanf("%d", &end_size);
    }
    while(end_size<start_size);

    //Initiate a loop to update the variable n and compare it with target size
    while(start_size < end_size){
        start_size = start_size + start_size/3 - start_size/4;
        years ++;
    }
   
    //Print the number of years it takes to reach the target size
    printf("Years: %d\n", years);

}
