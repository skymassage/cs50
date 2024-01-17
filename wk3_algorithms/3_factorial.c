// Single recursive case:
// Find factorial with recursion.
#include <cs50.h>
#include <stdio.h>

int fact(int n);

int main(void)
{
    int n;
    do
    {
        n = get_int("n: ");
    }
    while (n < 0);
    printf("%i!: %i\n", n, fact(n));
}

int fact(int n)
{
    // Base case: 0! = 1
    if (n == 0)
        return 1;
    // Recursive case: n! = n * (n-1)!
    else
        return n * fact(n - 1);
}
