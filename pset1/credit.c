/*
 
CS50's Pset 1 - Mario(More)
by Pedro Moura

*/

#include <stdio.h>
#include <cs50.h>

int main()
{
    long card_number;
    
    // promp user
    do
    {
        card_number = get_long("Number: ");
    }
    while (card_number < 0); // check user input
    
    int num_digits = 0; // Number of digits
    long copy_cn = card_number; // Copy of the Card Number.
    
    // increases "num_digits" by 1 until "copy_cn" is an integer greater than zero.
    while (copy_cn > 0)
    {
        copy_cn /= 10;
        num_digits++;
    }
    
    // Checks if the number of digits is valid or not
    if ((num_digits != 13) && (num_digits != 15) && (num_digits != 16))
    {
        printf("INVALID\n");
        return 0;
    }
    
    int digit[num_digits];
    int first_digit;
    int second_digit;
    
    for (int i = 0; i < num_digits; i++)
    {   
        // Stores each single digit from the card number
        digit[i] = card_number % 10;
        card_number /= 10;
        
        if (i == num_digits - 1)
        {
            // Stores 1st card's number digit
            first_digit = digit[i];
        }
        else if (i == num_digits - 2)
        {
            // Stores 2nd card's number digit
            second_digit = digit[i];
        }
        
    }
    
    int sum_even = 0;
    
    // Adds up all digits which location on the sequence is even.
    // Example: num = 4312. "3" and "4" are evens digits because of it location.
    for (int i = 0; i < num_digits; i = i + 2)
    {
        sum_even += digit[i];
    }
    
    int xablau[2];  // An array of two elements to store the 1st and 2nd card's number digit.
    int sum_odd = 0;
    
    // Multiplies by 2 all digits which location on the sequence is odd, then add all.
    // Example: num = 4312. "4" and "1" are odds digits because of it location.    
    for (int i = 1; i <= num_digits; i = i + 2)
    {
        digit[i] *= 2;
        
        // Checks if, after multiply by 2, the new i'th digit is a two digit number.
        // Example: if digit[i] = 6, so 6*2 = 12. --> [1][2] the two digits
        if (digit[i] > 9)
        {
            for (int j = 0; j < 2; j++)
            {
                // Stores only 1st and 2nd digits of the card number
                xablau[j] = digit[i] % 10;
                digit[i] /= 10;
            }
            //Sum the two digit number. Continuing exemp: [1]+[2] = 3
            digit[i] = xablau[0] + xablau[1];
        }
        sum_odd += digit[i];
    }
    
    // Check sum
    if ((sum_even + sum_odd) % 10 != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        // Makes the first two digits number.
        // Example: 1st = 3 and 2nd = 4, so the first two digits are 34.
        int first2digits = (first_digit * 10 + second_digit);
    
        // Checks if the card is a VISA
        if ((num_digits == 13 || num_digits == 16) && first_digit == 4)
        {
            printf("VISA\n");
        }

        // Checks if the card is an AMERICA EXPRESS
        else if (num_digits == 15 && (first2digits == 34 || first2digits == 37))
        {
            printf("AMEX\n");
        }
    
        // Checks if the card is a MASTER CARD
        else if (num_digits == 16 && (first2digits == 51 || first2digits == 52 || first2digits == 53 ||
                                      first2digits == 54 || first2digits == 55))
        {
            printf("MASTERCARD\n");
        }
        
        else
        {
            printf("INVALID\n");
        }
    }
    return 0;
}
