#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // prompt user to give correct cash till it is greater than 0 and less than 1
    float cash = -1;
    while (cash < 0)
    {
        cash = get_float("Change owed: ");
    }
    // To return lowest number of coins
    int cents = round(cash * 100);
    int coin = 0;
    coin += cents / 25;
    coin += (cents % 25) / 10;
    coin += ((cents % 25) % 10) / 5;
    coin += ((cents % 25) % 10) % 5;
    printf("%i\n", coin);
}
