// print out the pyramid of hashes with a maximum height of 8 hashes, as below:
//    #  #
//   ##  ##
//  ###  ###
// ####  ####
#include <cs50.h>
#include <stdio.h>

int main()
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j < n - i - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }

        printf("  ");

        for (int c = 0; c < i + 1; c++)
        {
            printf("#");
        }

        printf("\n");
    }
}