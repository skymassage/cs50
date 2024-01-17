#include <stdio.h>
#include <cs50.h>

int main(void)
{
    /*
    char c = get_char("Do you agree? ");
    if (c == 'Y' || c == 'y' )
    {
        printf("Agree.\n");
    }
    else if (c == 'N' || c == 'n')
    {
        printf("Not agree.\n");
    }
    */

    /*
    int x = get_int("What's x? ");
    int y = get_int("What's y? " );
    if(x < y)
    {
        printf("x is less than y\n");
    }
    else if(x > y)
    {
        printf("x is greater than y\n");
    }
    else
    {
        printf("x is equal to y\n");
    }
    */

    /*   // In C, every non-zero value is equivalent to true, and zero is false.
    int n = get_int("Number: ");
    if (n)   // if 'n' is non-zero value, it will be true; if 'n' is zero, it will be false
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
    */

    // ternary operator: "conditional_expression ? expression1 : expression2;"
    // if "conditional_expression" is true the the value of "expression1" is returned
    // if "conditional_expression" is false the the value of "expression2" is returned
    // Note that "expression1" and "expression1" must be the same type. ex: "... ? "\n" : '\n'" will be an error.
    int x = get_int("x: ");
    string result = (x == 10) ? ("x is equal to 10.\n") : ("x is not 10.\n");
    printf("%s", result);
    // Simplify the above into one line as two following examples.
    //printf("%s", get_int("x: ") == 10 ? "x is equal to 10.\n" : "x is not 10.\n");
    //get_int("x: ") == 10 ? printf("x is equal to 10.\n") : printf("x is not 10.\n");

    // Use "switch" statement to make decisions.
    char letter_grade = get_char("Enter the letter grade you expect on the exam: ");
    switch (letter_grade) // "letter_grade" is used to compare, and it must be an integer (characters are okay because they can be converted to intger)
    {
        case 'a':  // Check if "letter_grade == 'a'". Note that "..." in "case ...:" must be a constant.
        case 'A':  // So we cannot use "case 'a' || 'A' :".
            printf("You need a 90 or above, study hard!\n");
            break;  // If "break" is omitted, it will continue to run the next "case" until that "case" has a "break", or run all remaining cases if none of them have a break.
        case 'b':
        case 'B':
            printf("You need 80-89 for a B, go study!\n");
            break;
        case 'c':
        case 'C':
            printf("You need 70-79 for an average grade.\n");
            break;
        case 'd':
        case 'D':
            printf("Hmm, you should strive for a better grade. All you need is 60-69.\n");
            break;
        case 'f':
        case 'F':  //  If we want to declare variables inside "case" or "defalut", we must use curly braces "{...}".
        {
            char confirm = get_char("Are you sure (Y/N)? ");
            if (confirm == 'y' || confirm == 'Y')
                printf("OK, I guess you didn't study...\n");
            else if (confirm == 'n' || confirm == 'N')
                printf("Good- go study!\n");
            else
                printf("Illegal choice.\n");
            break;
        }

        default:  // "default" don't need to use "break", because it is the last one.
            printf("Sorry, not a valid grade\n");
    }
}