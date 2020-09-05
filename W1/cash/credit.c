#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    // prompt user to give correct cash till it is greater than 0 and less than 1
    long ccnum = 0;
    while (ccnum <= 0)
    {
        ccnum = get_long("Number: ");
    }
    // Get the legnth of card number
    double cclenght = floor(1.0 + log10((double) llabs(ccnum)));
    int lenght = cclenght;
    // Validate the card legnth
    if ((lenght != 13) && (lenght != 15) && (lenght != 16))
    {
        printf("INVALID\n");
    }
    else // Check Luhn’s Algorithm
    {
        int ccnumber[lenght];
        int cclast = 0;
        int ccsecodlast = 0;
        for (int i = 0; i < lenght; i++)
        {
            ccnumber[i] = ccnum % 10;
            if (i % 2 == 0)
            {
                cclast += ccnumber[i];
                // printf("last %i\n", ccnumber[i]);
            }
            else
            {
                int p_dig = ccnumber[i] * 2;
                // split 2 digite numbers to separate digites
                if (p_dig > 9)
                {
                    ccsecodlast += p_dig % 10;
                    ccsecodlast += p_dig / 10;
                }
                else
                {
                    ccsecodlast += p_dig;
                }
                // printf("second last %i\n", ccnumber[i]);
            }
            ccnum /= 10;
        }
        // printf("Last total: %i and Secondlast total: %i\n", cclast, ccsecodlast);
        // Final validation
        if ((cclast + ccsecodlast) % 10 == 0)
        {
            if (lenght == 13)
            {
                // Check for Visa 13 digite
                if (ccnumber[12] == 4)
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
            else if (lenght == 15)
            {
                // Check for Amex 15 digite
                if (ccnumber[14] == 3)
                {
                    if ((ccnumber[13] == 4) || (ccnumber[13] == 7))
                    {
                        printf("AMEX\n");
                    }
                    else
                    {
                        printf("INVALID\n");
                    }
                }
            }
            else if (lenght == 16)
            {
                // Check for Visa 16 digite
                if (ccnumber[15] == 4)
                {
                    printf("VISA\n");
                }
                // Check for MasterCard 16 digite
                else if (ccnumber[15] == 5)
                {
                    if ((ccnumber[14] == 1) || (ccnumber[14] == 2) || (ccnumber[14] == 3) || (ccnumber[14] == 4) || (ccnumber[14] == 5))
                    {
                        printf("MASTERCARD\n");
                    }
                    else
                    {
                        printf("INVALID\n");
                    }
                }
                else
                {
                    printf("INVALID\n");
                }
            }
            // printf("%i\n", (cclast + ccsecodlast) % 10);
        }
        else
        {
            printf("INVALID\n");
        }
    }
    // printf("count is: %i\n", lenght);
}
