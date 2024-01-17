// Find the prime numbers between min and max.
#include <cs50.h>
#include <stdio.h>

bool prime(int number);

// Return the prime numbers.
int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

bool prime(int number)
{
    /* // use while loop
    int count = 0;
    int i = 1;
    while (count < 1 || i < number)
    {
        if (number % i == 0)
        {
            count++;
        }
        i++;
    }

    if (count == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
    */

    // use for loop
    int count = 0;
    for (int i = 1; i < number; i++)
    {
        if ((number % i) == 0)
        {
            count++;
        }

        if (count > 1)
        {
            return false;
            break;
        }
        else if (count == 1 && i == (number - 1))
        {
            return true;
            break;
        }
    }

    return 0;  // Sometimes there is a bug without "return 0;" which indicates that the program exits normally and returns to the main program to continue execution.
}