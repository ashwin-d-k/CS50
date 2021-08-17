#include<stdio.h>

//Start the main function
int main(void){
    
    //Declare the variable height and prompt for user input
    int h;
    do{
        printf("Enter the height: ");
        scanf("%d", &h);
    }
    while(h < 0 && h > 8);

    for(int i = 0; i < h; i++){
        
        for(int j = h-i; j > 0; j--){
            printf(" ");
        }
        
        for(int j=0; j <= i; j++){
            printf("#");
        }
        
        printf("  ");

        for(int j = 0; j <=i; j++){
            printf("#");
        }
        printf("\n");
    }

}
