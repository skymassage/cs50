// Multiple recursive case:
// The Collatz conjecture is applies to positive integers and speculates that it is always possible to get "back to 1" if you follow these steps:
// • If n is 1, stop.
// • Otherwise, if n is even, repeat this process on n/2.
// • Otherwise, if n is odd, repeat this process on 3n + 1.
// Write a recursive function collatz(n) that calculates how many steps it takes to get to 1 if you start from n and recurse as indicated above.
#include <cs50.h>
#include <stdio.h>

int collatz(int n);

int main(void)
{
    int n;
    do
    {
        n = get_int("n: ");
    }
    while (n < 1);
    printf("collatz(%i): %i\n", n, collatz(n));
}

int collatz(int n)
{
    // base case
    if (n == 1)
        return 0;
    // recursive case 1: even numbers
    else if ((n % 2) == 0)
        return 1 + collatz(n/2);
    // recursive case 2: odd numbers
    else
        return 1 + collatz(3 * n + 1);
}

// Ex: if n = 3
//   collatz(n = 3)
// = 1 + collatz(10)
// = 1 + 1 + collatz(5)
// = 1 + 1 + 1 + collatz(16)
// = 1 + 1 + 1 + 1 + collatz(8)
// = 1 + 1 + 1 + 1 + 1 + collatz(4)
// = 1 + 1 + 1 + 1 + 1 + 1 + collatz(2)
// = 1 + 1 + 1 + 1 + 1 + 1 + 1 + collatz(1), (collatz(1) = 0)
// = 7