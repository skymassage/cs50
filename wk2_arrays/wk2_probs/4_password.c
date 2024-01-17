// Check that a password has at least one lowercase letter, uppercase letter, number and symbol.
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    bool digit = false, upper = false, lower = false, symbol = false;
    int i = 0;
    while (password[i] != '\0')            // for (int i = 0, length = strlen(word); i < length; i++)
    {
        if (isdigit(password[i]))
        {
            digit = true;
        }
        else if (isupper(password[i]))
        {
            upper = true;
        }
        else if (islower(password[i]))
        {
            lower = true;
        }
        else
        {
            symbol = true;
        }
        i++;
    }

    if (digit == true && upper == true && lower == true && symbol == true)
    {
        return true;
    }
    return false;
}