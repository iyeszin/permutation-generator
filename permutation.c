// C program to print all permutations with duplicates allowed
// BI14110048 Ang Iye Szin
#include <stdio.h>
#include <string.h>

/* Main program */
int main()
{
    char str[7];
    
    printf("Permutation generator\n\n");
    printf("Enter:");
    scanf("%[^\n]s",str);
    
    if(strlen(str)>7){
    	printf("The element is more than 7 characters.");
    	printf("Enter again:");
    	scanf("%[^\n]s",str);
	}
    else
   	permutation(str, 0, strlen(str)-1);
   	
    return 0;
}


/* Function to swap values at two pointers */
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
 
/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void permutation(char *a, int start, int end)
{
   int i;
   if (start == end)
     printf("%s\n", a);
   else
   {
       for (i = start; i <= end; i++)
       {
          swap((a+start), (a+i));
          permutation(a, start+1, end);
          swap((a+start), (a+i)); //backtrack
       }
   }
}
 

