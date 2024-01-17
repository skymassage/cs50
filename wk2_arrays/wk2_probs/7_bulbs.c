// https://cs50.harvard.edu/x/2023/psets/2/bulbs/#specification
#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO
    string message = get_string("Message: ");

    int binary[BITS_IN_BYTE], quotient;

    for (int i = 0, length = strlen(message); i < length; i++)
    {
        quotient = message[i];
        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            if (quotient != 0)
            {
                binary[BITS_IN_BYTE - j - 1] = quotient % 2; // Note that the order of bits is printed from the left.
                quotient /= 2;
            }
            else
            {
                binary[BITS_IN_BYTE - j - 1] = 0;
            }
        }

        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            print_bulb(binary[j]);
        }

        printf("\n");
    }

    printf("\n");
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
