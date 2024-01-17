#include <cs50.h>
#include <stdio.h>

// Define a new struct called "candidate"
typedef struct
{
    string name;
    int votes;
}
candidate;

candidate get_candidate(void);

int main(void)
{
    int n = get_int("The number of canditates: ");
    candidate c[n];
    // Prompt user for a candidate
    for (int i = 0; i < n; i++)
    {
        c[i] = get_candidate();   // Note that you can't retrun arrays.
    }

    for (int i = 0; i < n; i++)
    {
        printf("%s: %i\n", c[i].name, c[i].votes);
    }
}

candidate get_candidate(void)
{
    // Declare a new candidate
    candidate c;

    // Initialize the candidate's attributes
    c.name = get_string("Enter a name: ");
    c.votes = get_int("Enter a number of votes: ");

    // Return the new candidate
    return c;
}