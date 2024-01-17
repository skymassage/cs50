#include <stdio.h>

// Defining a custom data type as below:
// typedef <old name> <new name>;
typedef unsigned int nonnegative; // // "typedef" creates a new data type with the new name "byte" whose type is the old name "unsigned char". Note that this line shouled be at the top of a C file or in a library (.c file).
typedef char *string;  // The library "cs50.h" has this line of code that lets us declare a string using "string".

// Change the name of data stucture
// Method 1
struct people
{
    char *name;
    long number;
    int year;
    float score;
};

typedef struct people student;  // "struct people" is the old name, and "student" is the new name.

/*
// Method 2 (more succinct than above)
typedef struct people
{
    char *name;
    long number;
    int year;
    float score;
}
student;
*/

int main(void)
{
    nonnegative n = 100;  // new data type for declaring a variable
    printf("%i\n", n);
    printf("--------------------------\n");

    string word1 = "HI!";  // same as char *<variable>
    printf("%p\n", word1);
    printf("%s\n", word1);
    printf("%c %c %c\n", *word1, *(word1+1), *(word1+2));
    printf("%c %c %c\n", word1[0], word1[1], word1[2]);
    printf("%p %p %p\n", &word1[0], &word1[1], &word1[2]);
    printf("%s %s %s\n", word1, word1+1, word1+2);
    printf("--------------------------\n");

    char *word2 = "hi!";  // same as string <variable>
    printf("%p\n", word2);
    printf("%s\n", word2);
    printf("%c %c %c\n", *word2, *(word2+1), *(word2+2));
    printf("%c %c %c\n", word2[0], word2[1], word2[2]);
    printf("%p %p %p\n", &word2[0], &word2[1], &word2[2]);
    printf("%s %s %s\n", word2, word2+1, word2+2);
    printf("--------------------------\n");

    student class_A[2];  // new data structure for declaring an array
    class_A[0].name = "Alice";
    class_A[0].number = 12345678912345;
    class_A[0].year = 12;
    class_A[0].score = 99.9;
    class_A[1].name = "B0b";
    class_A[1].number = 54321987654321;
    class_A[1].year = 12;
    class_A[1].score = 59.9;
    printf("%s %li %i %f\n", class_A[0].name, class_A[0].number, class_A[0].year, class_A[0].score);
    printf("%s %li %i %f\n", class_A[1].name, class_A[1].number, class_A[1].year, class_A[1].score);
    printf("--------------------------\n");

    student Alice;  // new data structure for declaring a variable
    Alice.name = "Alice McNulty";
    Alice.number = 12345678912345;
    Alice.year = 12;
    Alice.score = 99.9;
    printf("%s %li %i %f\n", Alice.name, Alice.number, Alice.year, Alice.score);
}