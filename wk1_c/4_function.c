/* Defining a Function:
   return_type function_name(parameter list)
   {
       body of the function
   }

   The function name and the parameter list together constitute the function signature. */

/* When you pass variables as the parameters into a function it is "passed-by-value". A copy of the data is passed to the function.
   Whatever changes you makes to the parameter in the function does not affect the argument that was passed in. */
/* The variables passed to the function when it is called are "actual parameters".
   "Formal parameters" are the variables defined by the function that receives values when the function is called,
   The scope of formal parameters is local to the function definition in which they are used.
   Formal parameters are a copy of the actual parameters,
   so change in formal parameters would not be reflected in the actual parameters.
   It is common to call formal parameters as "parameters", and actual parameters as "arguments". */

#include <stdio.h>
#include <cs50.h>

/* If the functions you use in "main()" function are after main(), you should declare the function prototypes
   at the beginning of the program to hint the compiler that they will exist. /*
/* Function prototype:
   A declaration of a function that specifies the function's name and type signature (type signature is the number, types,
   and order of the arguments contained by a function), but omits the function body.
   Or just a declaration of the function signature. */
// Normally, as the programs get larger, these prototypes will end up going in a different file, in a ".h" file.

int get_size(void);
// int get_size(); // It also can omit declaring parameters for the prototype if there are no parameters for the function.
                   // However, you can put any arguments in this function when you are calling it, and it still can work. (But this will cause an error in C++)
                   // So using "void" in "()" tells the compiler you cannot put any arguments in this function, otherwise it be an error. */
void print_grid(int n); // void print_grid(int); Also can omit the arguments for the prototype.

int main(void)
{
    int n = get_size();
    print_grid(n);
}

int get_size(void) // int: declare the data type this function returns; void: means this function does not take any inputs as parameters.
{
    int n;
    do
    {
        n = get_int("Size: ");
    }
    while (n < 1);
    return n;
}

void print_grid(int n)  // void: means this function has no return value; the function has one argument, whose data type must be declared.
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
