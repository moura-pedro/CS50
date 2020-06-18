/*
 
CS50's Pset 1 - Cash
by Pedro Moura

*/

#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main()
{
    float dollars;

    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);  // ensure that the user’s input is not that it is non-negative.

    // convert the user’s inputted dollars to cents
    int cents = round(dollars * 100);

    // minimize the number of coins
    int quarters, dimes, nickels, pennies;
    quarters = cents / 25;
    dimes = (cents % 25) / 10;
    nickels = ((cents % 25) % 10) / 5;
    pennies = ((cents % 25) % 10) % 5;

    int coins_total = quarters + dimes + nickels + pennies;
    // prints the minimum number of coins
    printf("%d\n", coins_total);

    return (0);

}
