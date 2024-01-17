// https://cs50.harvard.edu/x/2023/problems/3/atoi/
// convert the string data type of a positive number to int.
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // TODO
    int n = strlen(input);
    if (n == 0)
    {
        return 0;
    }

    int temp = input[n - 1] - '0';
    input[n - 1] = '\0';
    return 10 * convert(input) + temp;
}