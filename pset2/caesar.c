/*
 
CS50's Pset 2 - Caesar
by Pedro Moura

*/

#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Checks the number of arguments.
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return (1);
    }
    
    // Checks if the argument consists solely of digit characters.
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (isalpha(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return (1);
        }
    }
    
    // Converts the string to an integer.
    int key = atoi(argv[1]);
    
    // Promp user input.
    string text = get_string("plaintext: ");
    
    // Cipher the text.
    printf("ciphertext: ");
    
    for (int i = 0; i < strlen(text); i++)
    {
        // Checks for a lowercase character.
        if (islower(text[i]))
        {
            printf("%c", (((text[i] + key) - 97) % 26) + 97);
        }
        
        // Checks for a uppercase character.
        else if (isupper(text[i]))
        {
            printf("%c", (((text[i] + key) - 65) % 26) + 65);
        }
        
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}
