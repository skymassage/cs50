// https://cs50.harvard.edu/x/2023/psets/1/credit/
// Luhn’s Algorithm: check the number is a credit card number.
// Then determine which company the credit card belongs to.
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long number;
    do
    {
        number = get_long("Number: ");
    }
    while (number < 0);

    // Use the Luhn algorithm to compute the checksum of the number.
    long remainder, division = 10, _number = number;
    int digit, _digit, sum = 0, count = 0;
    while (division <= (number * 10))
    {
        remainder = _number % division;
        digit = remainder / (division / 10);
        if ((count % 2) == 0)
        {
            sum += digit;
        }
        else if ((count % 2) == 1)
        {
            _digit = 2 * digit;
            if (_digit < 10)
            {
                sum += _digit;
            }
            else
            {
                sum = sum + (_digit / 10) + (_digit % 10);
            }
        }
        _number -= digit * (division / 10);
        division *= 10;
        count++;
    }

    // According to the checksum determine if the number is a credit card numer.
    if ((sum %= 10) != 0)
    {
        printf("INVALID\n");
    }
    // According to the rules to determine which company the credit card belongs to.
    else
    {
        if ((number / 10000000000000) == 34 || (number / 10000000000000) == 37)
        {
            printf("AMEX\n");
        }
        else if ((number / 100000000000000) >= 51 && (number / 100000000000000) <= 55)
        {
            printf("MASTERCARD\n");
        }
        else if ((number / 1000000000000) == 4 || (number / 1000000000000000) == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
}