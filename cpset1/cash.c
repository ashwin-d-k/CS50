#include<stdio.h>
#include<math.h>

//Start the main function
int main(void){
    
    //Declare the variables that are to be used
    float cash;
    int change, coins = 0;

    //Prompt the user to input amount of cash owed in dollars
    do{
        printf("Cash owed = ");
        scanf("%f", &cash);
    }
    while(cash<0.01);

    //Round down the value and store in a different variable
    change = round(cash*100);

    //Using looping constructs to check for no of 25c coins that can be used and update coins
    while(change > 25){
        change = change - 25;
        coins++;

    }

    while(change > 10){
        change = change - 10;
        coins++;
    }

    while(change > 5){
        change = change - 5;
        coins++;

    }

    while(change >= 1){
        change = change - 1;
        coins++;

    }

    printf("Coins = %i\n", coins);
}
