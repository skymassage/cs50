#include <stdio.h>
#include <cs50.h>
#define PI 3.141592653  // At the time your program is compiled, "#define" goes through your code and replaces "PI" with "3.141592653"; use uppercase conventionally such as "PI".

int main(void)
{
    int x = 0, y = 1;
    x = y;  // "=": this doesn't mean two variable are the same, it just copies the value of "y" to "x".
    printf("%i, %i\n", x, y);
    y = 100;
    printf("%i, %i\n", x, y);

    // Note that the data type "string" is only from library "cs50.h".
    string first = get_string("What's your first name? ");
    string last = get_string("What's your last name? ");
    printf("hello %s %s!\n", first, last);          // % is a palceholder; %c: char; %i: int; %f: float, double; &li: long
    printf("I got 100%%.\n");    // Tpye '%' twice to print '%'.

    const int n = get_int("What's your number? ");  // const: declare the variable is a constant which cannot be changed, otherwise it will have a bug.
    printf("Your number is %i.\n", n);
}
