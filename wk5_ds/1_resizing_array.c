// Implements a list of numbers with an array of dynamic size using realloc
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // List of size 3
    int *list = malloc(3 * sizeof(int));
    if (list == NULL)
    {
        return 1;
    }

    // Initialize list of size 3 with numbers
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // Resize list to be of size 4
    int *tmp = realloc(list, 4 * sizeof(int));  // "realloc" takes two arguments: one that asks you to specify the array you are attempting to copy, and one that asks you to specify the size to which you would like the final array to be.
                                                // Note that it creates a array of four integers and copies the values of "list" to this new array. Tnen, a pointer called "tmp" points to the location of memory of this new array.
    //list = realloc(list, 4 * sizeof(int));  // This line could lead to a memory leakage: if "realloc" fails and doesn't have enough memory for you, it will return "NULL". So "list" will be overwritten with "NULL, and "realloc" couldn't find the original "list" to free it.
    if (tmp == NULL)
    {
        free(list);  // Remember free the memory before exiting the program.
        return 1;
    }
    list = tmp;  // The pointer called list is pointed at the location of tmp, where the new array is located.

    // Add number to list
    list[3] = 4;

    // Print list
    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    // Free list
    free(list);  // You can replace this line with "free(tmp)", but chooing "list" is more readable because "list" is the main variable here.
    return 0;
}
