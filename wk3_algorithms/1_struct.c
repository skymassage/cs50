#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Define the data structure as below:
// Method 1
struct student  // Build a structure called "student".
{
    string name;
    string number;
};

// Method 2
typedef struct
{
    string name;
    string number;
}
person;  //  All of that to be wrapped up into "typedef struct {...}" above called "person", one data type.

int main(void)
{
    // Method 1
    struct student myclass[4];  // Need to declare structure.
    myclass[0].name = "Carter";
    myclass[0].number = "+1-617-495-1000";
    myclass[1].name = "David";
    myclass[1].number = "+1-949-468-2750";
    myclass[2].name = "Brian";
    myclass[2].number = "+1-541-754-3010";
    myclass[3].name = "Lolyd";
    myclass[3].number = "+1-212-456-7890";
    for (int i = 0; i < 4; i++)
    {
        printf("%s: %s\n", myclass[i].name, myclass[i].number);
    }

    printf("-------------------------\n");

    // Method 2
    person people[4];  // No need to declare structure because this structure has been change to data type using "typedef".
    people[0].name = "Carter";
    people[0].number = "+1-617-495-1000";
    people[1].name = "David";
    people[1].number = "+1-949-468-2750";
    people[2].name = "Brian";
    people[2].number = "+1-541-754-3010";
    people[3].name = "Lolyd";
    people[3].number = "+1-212-456-7890";
    for (int i = 0; i < 4; i++)
    {
        printf("%s: %s\n", people[i].name, people[i].number);
    }

    return 0;
}