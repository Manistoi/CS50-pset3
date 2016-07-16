/*
-----------------------Binary Search-------------------------

User first inputs the key or 'value' as a command line argument.
Then, user inputs length of array he/she would like to make.
User inputs array values/elements.
The program then uses binary search to look through the array 
and find out whether the key/value is in the array.

*/




#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(int argc, char* argv[]) 
{
    if (argc != 2)  //Ensure's proper usage
    {
        printf("Usage: BinarySearch needle\n");
        return 1;
    }
    
    printf("Create an array of how many values?\n");
    int x = GetInt();
    int values[x];    //declaring array of x integers
    int value = atoi(argv[1]); //Take second command line argument, convert it to int, store it in 'value'
    int min = 0;
    int n = sizeof(values)/sizeof(values[0]); // Gives number of elements in array
    int max = n - 1;
    bool binarySearch(int value, int values[], int min, int max); //prototype
    
    for (int i = 0; i < x; i++)   
    {
       printf("Please enter a value: \n");
       
       do { scanf("%d", (values + i)); }
       while (values[i] < 0);
    }
    
    
    //Check whether 'value' is within the 'values' array
    
    if(binarySearch(value, values, min, max)) 
    {
        printf("The value is in the array!\n");
        return 0;
    }
    else {
        printf("Sorry! The value isn't here!\n");
    }
    
}

bool binarySearch(int value, int values[], int min, int max)
{
    if (min <= max) //makes sure that array being searched is more than 1 element long
    {
        int mid = (min + max) / 2;
        
        if (value == values[mid])
            return true;
        else if (value > values[mid])
            return binarySearch(value, values, mid + 1, max);
        else if (value < values[mid])
            return binarySearch(value, values, min, mid - 1);
            
    }
    
    return false;
}
