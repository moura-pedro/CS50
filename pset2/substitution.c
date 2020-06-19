/*
 
CS50's Pset 2 - Substitution
by Pedro Moura

*/

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    string key = argv[1];   // Just for convention :)
    
    // Checks the number of arguments.
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return (1);
    }
    
    // Checks the number of chararcters on the argument.
    else if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return (1);
    }
    
    // Checks if contain repeated characters on argument.
    for (int i = 0; i < strlen(key); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (key[j] == key[i])
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }
    
    // Checks if the key only contain characters.
    for (int i = 0; i < strlen(key); i++)
    {
        if (isalpha(key[i]) == false)
        {
            printf("Key must only contain characters.\n");
            return 1;
        }
    }
    
    // Convertes all characters to lowercase.
    for (int i = 0; i < strlen(key); i++)
    {
        if (isupper(key[i]))
        {
            key[i] += 32;
        }
    }
    
    // Prompt user input.
    string text = get_string("plaintext: ");
    
    // Cipher the text from user.
    printf("ciphertext: ");
    
    for (int i = 0; i < strlen(text); i++)
    {
        // Checks for an alphabetic character.
        if (isalpha(text[i]))
        {
            int letter_location;
            
            // Checks for an uppercase character.
            if (isupper(text[i]))
            {
                // Gets the text[i] character location on alphabet.
                // Example: text[i] = 'D'. 'D' = 68 on ASCII table, so:
                // 68 - 65 = 3. Counting from 0, letter 'D' is on the 3rd position.
                letter_location = (text[i] - 65);
                printf("%c", key[letter_location] - 32);
            }
            else
            {
                // Same idea used above, but with lowercase characters.
                letter_location = (text[i] - 97);
                printf("%c", key[letter_location]);
            }
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}    
