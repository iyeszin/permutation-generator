// C program to print all permutations handle duplicates
// BI14110048 Ang Iye Szin
#include <stdio.h>
#include <stdlib.h>>
#include <string.h>
#include <stdbool.h>

/* Main program */
int main()
{
    char str[7];
    
    printf("Permutation generator");
    printf("\n\nEnter:");
    scanf("%[^\n]s",str);
    
   while(strlen(str)>7){
    	printf("\nThe element is more than 7 characters.");
    	printf("\nEnter again:");
    	scanf("%[^\n]s",str);
		getchar();
	};

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

/*Needed for qsort function*/
int compare(const void *x, const void *y){
	return(*(char *)x -*(char *)y);
}

int findCeil(char str[], char first, int l, int h){
	// initialize index of ceiling element
    int ceilIndex = l;
    int i;
 
    // Now iterate through rest of the elements and find
    // the smallest character greater than 'first'
    for (i = l+1; i <= h; i++){
        if (str[i] > first && str[i] < str[ceilIndex])
            ceilIndex = i;
 	}
    return ceilIndex;
}
 
/*Print all permutation in sorted order*/
void permutation(char str[])
{
	//sorting
	qsort(str, strlen(str), sizeof(str[0]),compare);
	
	bool isFinished = false;
    while (!isFinished)
    {
        // print this permutation
        printf("%s \n",str);
 
        // Find the rightmost character which is smaller than its next
        // character. Let us call it 'first char'
        int i;
        for (i = strlen(str) - 2; i >= 0; --i)
            if (str[i] < str[i+1])
                break;
 
        // If there is no such chracter, all are sorted in decreasing order,
        // means we just printed the last permutation and we are done.
        if (i == -1)
            isFinished = true;
        else
        {
            // Find the ceil of 'first char' in right of first character.
            // Ceil of a character is the smallest character greater than it
            int ceilIndex = findCeil(str, str[i], i + 1, strlen(str) - 1);
 
            // Swap first and second characters
            swap(&str[i], &str[ceilIndex]);
 
            // Sort the string on right of 'first char'
            qsort(str + i + 1, strlen(str) - i - 1, sizeof(str[0]), compare);
        }
	}
}
 

