#include<stdio.h>

int main(void){
    int step;
    printf("Enter the number of steps : ");
    scanf("%i",&step);

    for(int i=0; i<step; i++){
       
        for(int j=0; j<i+1; j++){
            printf("#");
        }
        printf("\n");
    }
    printf("\n");
}
