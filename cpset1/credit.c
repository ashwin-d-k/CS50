#include<stdio.h>

int main(void){

        int count = 0;
        long num;

        do{
            printf("Enter a card number : ");
            scanf("%li", &num);
        }
        while(num<0);

        long c_num = num;

        int d_1, d_2, d_3, d_4, d_5, d_6, d_7, d_8;

        //Get every other digit starting from seconf last digit and multiply them by 2
        d_1 = ((num%100)/10)*2;
        d_2 = ((num%10000)/1000)*2;
        d_3 = ((num%1000000)/100000)*2;
        d_4 = ((num%100000000)/10000000)*2;
        d_5 = ((num%10000000000)/1000000000)*2;
        d_6 = ((num%1000000000000)/100000000000)*2;
        d_7 = ((num%100000000000000)/10000000000000)*2;
        d_8 = ((num%10000000000000000)/1000000000000000)*2;

        //If the numbers are two digits then add the two digits else keep as it is
        d_1 = d_1%10 + d_1/10;
        d_2 = d_2%10 + d_2/10;
        d_3 = d_3%10 + d_3/10;
        d_4 = d_4%10 + d_4/10;
        d_5 = d_5%10 + d_5/10;
        d_6 = d_6%10 + d_6/10;
        d_7 = d_7%10 + d_7/10;
        d_8 = d_8%10 + d_8/10;
        
        //Add the digits
        int sum_e = d_1 + d_2 + d_3 + d_4 + d_5 + d_6 + d_7 + d_8;
        //  printf("%i %i %i %i %i %i %i %i", d_1, d_2, d_3, d_4, d_5, d_6, d_7, d_8);
        
        int sum_o = ((num%1000000000000000)/100000000000000) + ((num%10000000000000)/1000000000000) + ((num%100000000000)/10000000000) + 
                    ((num%1000000000)/100000000) + ((num%10000000)/1000000) + ((num%100000)/10000) + ((num%1000)/100) + num%10;
        
        int mc = num/100000000000000;
        int amx = num/10000000000000;
        int v;

        while(c_num > 0){
            c_num = c_num/10;
            count++;

        }
        
        if(count == 16) v = num/1000000000000000;
        else v = num/1000000000000;

        int check_sum = sum_o + sum_e;

        // printf("%i %i %i %i %i\n", check_sum, count, mc, amx, v);
        
        if(check_sum%10 != 0){
            printf("INVALID\n");
            return 1;
        }

        else {
            if(count==16){
                if(mc == 22 || mc == 51 || mc == 52 || mc == 53 || mc == 54 || mc == 55){
                    printf("MASTERCARD\n");
                    return 0;
                } 
                else if(v ==4){
                    printf("VISA\n");
                    return 0;
                }
                else {
                    printf("INVALID\n");
                    return 1;
                }
            }

            else if(count==15){
                if(amx == 34 || amx == 37){
                    printf("AMERICAN EXPRESS\n");
                    return 0;
                }

                else{
                    printf("INVALID\n");
                    return 1;
                }
            }

            else if(count==13){
                if(v==4){
                    printf("VISA\n");
                    return 0;
                }

                else {
                    printf("INVALID\n");
                    return 1;
                }
            }

            else {
                printf("INVALID\n");
                return 1;
            }

        }
        
}
