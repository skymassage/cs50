#include <stdio.h>

/* The array name evaluates to the address of the first element of the array.
   So what's being passed into the function is the address of the first element of the array.
   That means that the function doesn't know how many elements are in the array.
   So when we pass arrays to functions, we also need to pass in the size of the array,
   so that we now know how many times to iterate.
   Note that "[]" follows the array name when using an array as an arugment. */
void set_array_zero(int array[], int size);

/* We can define function parameters as const parameters to tell the compiler
   that these parameters are read-only within the function body.
   Any attempt to modify them will result in a compiler error. */
void print_array(const int array[], int size);
void set_zero(int x);

int main(void)
{
    // Declare and initialize an array
    int array[3];
    array[0] = 10, array[1] = 20, array[2] = 30; // "array = {1,2,3}" will be errrors, you can't assign arrays becasue they are actually addresses.
    printf("%i %i %i\n", array[0], array[1], array[2]);
    printf("--------------------------------------------\n");

    // You can also declare and initialize arrays simultaneously.
    int numbers[] = {100, 200, 300, 400};  // For this syntax, you don't need to indicate the size of the array beforehand. "int numbers[10] = {100, 200, 300, 400}" is OK, but the size of this array is fixed to "10".
    printf("%i, %i, %i, %i\n", numbers[0], numbers[1], numbers[2], numbers[3]);
    printf("--------------------------------------------\n");

    // Arrays can consist of more than a single dimensions.
    // Note that you can't declare like "int m[][]" for more than one dimension.
    int n[2][3] = {{10, 20, 30}, {100, 200, 300}};
    printf("%i %i %i\n", n[0][0], n[0][1], n[0][2]);
    printf("%i %i %i\n", n[1][0], n[1][1], n[1][2]);
    printf("--------------------------------------------\n");

    /* When passing an array to a function, unlike passing variables to a function, we don't make a copy of the array,
       becasue we don't know how long the array is and maybe it could takes much time to copy a very long array.
       Thus, arrays given as arguments and passed to a function and then changing them inside the function,
       and accordingly these arrays are also changed outside of the function. */
    int a = 999;
    int b[] = {0, 1, 2, 3};
    printf("Before: %i and ", a);
    print_array(b, 4);
    set_zero(a);
    set_array_zero(b, 4);
    printf("After:  %i and ", a);
    print_array(b, 4);
}

void print_array(const int array[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%i ", array[i]);
    printf("\n");
    //array[0] = 1;  // It will be an error because "array" is const.
}

void set_array_zero(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = 0;
    }
}

void set_zero(int x)
{
    x++;  // Add this line to avoid the bug, but I don't know why.
    x = 0;
}
