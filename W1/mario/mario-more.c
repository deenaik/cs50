#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // prompt user to give height till height is greater than 0 and less than 9
    int height = 0;
    while (height < 1 || height > 8)
    {
        height = get_int("Height: ");
    }
    // To Generate correct Number of rows
    for (int hashes = 0; hashes < height; hashes++)
    {
        // To make Pyramid right-align
        for (int hash = height; hash > hashes + 1; hash-- )
        {
            printf(" ");
        }
        // Building left side of pyramid
        for (int hash = 0; hash < hashes + 1; hash++ )
        {
            printf("#");
        }
        // Creating gap between two sides
        printf("  ");
        // Building right side of pyramid
        for (int hash = 0; hash < hashes + 1; hash++ )
        {
            printf("#");
        }
        printf("\n");
    }
}
