/*
 
CS50's Pset 1 - Mario(More)
by Pedro Moura

*/

#include <stdio.h>
#include <cs50.h>

int main()
{
    int height;
    
    // checks the user input
    do
    {
        height = get_int("Height: ");
    }
    while (height > 8 || height < 1);
    
    // prints 2 pyramids
    for (int i = 0; i < height; i++)
    {
        // spaces from the wall
        for (int space = height - 1; i < space; space--)
        {
            printf(" ");
        }
        
        // left pyramid
        for (int j = 0; j <= i; j++)    
        {
            printf("#");
        }
        
        // the space between the pyramids
        printf("  ");
        
        // right pyramid
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
    return 0;
