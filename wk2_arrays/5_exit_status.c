// Use the command "echo $?" to see what is returned:
// Generally, the sreen doesn't show what "main" returns.
// You can type the command "echo $?" at the end of program to see what "main" returns.
// If not specified, it will return "0" meaning the program exited without error, even in a loop and exits immediately.
// That's why we declare the type of "main" as int.
// Note that "return 0;" means to exit the entire program, but "break" means to exit the current loop.
// "return 0;" means this program is successful. Any integer other than "0" means some kind of failure to achieve the goal, and we typically set "return 1;".
#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Missing command-line argument\n");
        return 1;
    }
    printf("hello, %s\n", argv[1]);
    return 0;
}