/*
 
CS50's Pset 1 - Mario(Less)
by Pedro Moura

*/

#include <stdio.h>
#include <cs50.h>

int main()
{
    int height;
    
    // Checks the user input
    do
    {
        height = get_int("Height: ");
    }
    while (height > 8 || height < 1);
    
    // Print the pyramid
    for (int i = 0; i < height; i++)
    {
        // Put spaces from the wall
        for (int space = height - 1; i < space; space--)
        {
            printf(" ");
        }
        
        // Put hashes, making the pyramid
        for (int j = 0; j < i; j++)    
        {
            printf("#");
        }
   
        printf("#\n");
    }
    return 0;
}
