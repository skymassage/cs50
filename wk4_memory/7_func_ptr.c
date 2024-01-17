// Arguments and returns of functions could be pointers.
#include <stdio.h>
#include <stdlib.h>

#define SIZE 7

// If you want to use a function to change the value outside this function, you must use pointers as below:
void swap(int *x, int *y);  // Input pointers as arguments to functions.
// C use pass-by-pointer instead of pass-by-reference, so if you cannot use '&' to wtrite this like in C++: "void swap(int &value1, int &value2);", it will be an error.

// Functions can also return pointers using "*" to declare function:
int *min(int *x, int *y);  // Note that adding "*" before the function "min".

// Treat the array as a pointer and input it into the function:
void replace(int *arr, int idx, int num);  // No "[]" for "arr" even though it is an array, otherwise it will cause errors.
// void replace(int arr[], int idx, int num)  To the compiler, this line is same as void replace(int *arr, int idx, int num).

// Treat the array as a pointer and input it into the function which will return a pointer:
int *max(int *arr);

// Accept two pointers as the parameters with "void", regardless of their data types.
int print_number(void *ptr1, void *ptr2);

int main()
{
    int a = 5, b = 33;
    int sequence[SIZE] = {13, 32, 67, 14, 22, 95, 76};

    // Swap a and b:
    swap(&a, &b);  //  Don't forget "&".
    printf("After swap: a = %i, b = %i\n", a, b);

    // Find the larger vaule between a and b:
    int *p = min(&a, &b);  // Note that there is no "*" before "min" here.
    printf("The smaller value: %i\n", *p);

    // Replace the element of array:
    int index = 4, number = 24;
    replace(sequence, index, number);  // No "&" for "sequence", because it's an array.
    printf("The sequence after replace one element: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf("%i ", sequence[i]);
    }
    printf("\n");

    // Print the maximum:
    int *maximum = max(sequence);  // No "&" for "sequence", because it's an array.
    printf("The maximun value of the sequence: %i\n", *maximum);

    // Use any pointers as the paremeters
    char *ptr = "one hunderd";
    int num = 100;
    printf("%i\n", print_number(ptr, &num));

    return 0;
}

void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int *min(int *x, int *y)
{
     if (*x < *y)
        return x;

    else
        return y;
}

void replace(int *arr, int idx, int num)
{
    *(arr+idx) = num;
}

int *max(int *arr)
{
    int *max_temp = arr;
    for (int i = 0; i < SIZE; i++)
    {
        if (*max_temp < *(arr+i))
            max_temp = arr+i;
    }
    return max_temp;
}

int print_number(void *ptr1, void *ptr2)
{
    return 100;
}
