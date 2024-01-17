#include <cs50.h>
#include <stdio.h>

// "main" will take command line arguments at the prompt on the terminal window.
int main(int argc, string argv[])  // argc: argument count; argv: argument vector
// "argv[]" will be all of the words that you type at the prompt.
// "argv" is an array of strings which stores, one string per element, the actual text the user typed at the command-line when the program was executed.
// Everything in argv is stored as a string, even if you type numbers in the command-line argument.

// "argc" is a integer-type variable which will store the number of command-line arguments the user typed when the program was executed.
// You can get the length of the string using strlen, but you can't get the length of the array of strings (the number of command-line arguments).
// Because arrays don't keep track of their own length except for strings, it is the convention to declare "int argc".
{
    printf("How many command-line arguments you type at the prompt: %i\n", argc);

    // argv[0] is the first element that you type at the prompt. The program name itself counts as a command-line argument.
    // argv[1] is the second element that you type at the prompt, and so on.
    // We don't know what argv[i>= argc] returns. It depends on what is located at the memory where argv[i>= argc] would be expected to be.
    for (int i = 0; i < argc; i++)    // go through every element of the array of command-line arguments
    {
        printf("argv[%i] is %s\n", i, argv[i]);
    }
    printf("---------------------------------------------\n");
    printf("The last element of agrv is %s\n", argv[argc - 1]);
}