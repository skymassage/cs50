// While we can treat inidividual elements of arrays as variables, we cannot treat entire arrays themselves as variables.
// For example, we cannot assign one array to another using "=".
// Instead, we must use a loop to copy over the elements one at a time.
#include <stdio.h>

int main(void)
{
    int foo[5] = {1, 2, 3, 4, 5};
    int bar[5];

    // "bar = foo;" will give an error, so you must use a loop to copy the array.
    for (int i = 0; i < 5; i++)
    {
        bar[i] = foo[i];
    }
}