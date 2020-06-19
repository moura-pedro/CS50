/*
 
CS50's Pset 2 - Readability
by Pedro Moura

*/

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sent(string text);
void grade_check(float index);

int main()
{
    // Ask user for input(the text).
    string text = get_string("Text: ");
    
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sent(text);
    
    // The average number of letters and sentences per 100 words in the text.
    float L = ((float) letters / (float) words) * 100;
    float S = ((float) sentences / (float) words) * 100;
    
    // The Coleman-Liau index formula.
    float index = round(0.0588 * L - 0.296 * S - 15.8);
    
    grade_check(index);
    
    return (0);
}

/* ---------------------------------- Functions ---------------------------------- */

// Calculates and returns the number of letters on text.
int count_letters(string text)
{
    int num_letters = 0;
    
    for (int i = 0; i < strlen(text); i++)
    {
        // isalpha() is a function from "ctype.h" library. Checks for an Alphabetic Characters.
        if (isalpha(text[i]))
        {
            num_letters += 1;
        }
    }
    return num_letters;
}

// Calculates and returns the number of words on text.
int count_words(string text)
{
    int num_words = 0;
    
    for (int i = 0; i < strlen(text); i++)
    {
        // isblank() is a function from "ctype.h" library. Checks for blank spaces.
        if (isblank(text[i]))
        {
            num_words += 1;
        }
    }
    // Remember that end of texts it's not finished with space.
    // So, to count the last word, it's needed to add + 1.
    return (num_words + 1);
}

// Calculates and returns the number of sentences on text.
int count_sent(string text)
{
    int num_sent = 0;
    
    for (int i = 0; i < strlen(text); i++)
    {
        // Checks if is one of these ponctuations.
        if ((text[i] == '.') || (text[i] == '!') || (text[i] == '?'))
        {
            num_sent += 1;
        }
    }
    return num_sent;
}

// Checks index and prints the Grade.
void grade_check(float index)
{
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    
    else
    {
        printf("Grade %i\n", (int) index);
    }
}
