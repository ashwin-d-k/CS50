#include <stdio.h>
#include<string.h>

int main( ) {

   char str[100];
   
   //Enter a name or a sentence
   printf( "Enter a name or place: ");

   //Use the fgets function to read in the word are a line of text 
   fgets(str, 100, stdin);

   //Set the index number before end of string to 0 to prevent a new line
   str[strlen(str)-1] = '\0';
   int ln = strlen(str);

   //Print the phrase/name      
   printf( "Hello, %s \n", str);
   

   return 0;
}
