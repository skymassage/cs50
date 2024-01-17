#include <stdio.h>

int main(void)
{
    printf("\n-----------------------------------------------------------------------------1\n");
    // '*': dereference operator ; '&': address operator
    int n = 50;   // "int* <variable>" is same as "int *<variable>", "int*<variable>", or "int * <variable>". Depends on coding habits.
    int *a = &n;  // The "*" here is used to declare a pointer which is a variable that stores an address. A pointer is nothing more than an address.
                  // "&" is extracting the address of an already existing variable.
    // Print out the address of n:
    printf("%p\n", &n);
    printf("%p\n", a);  // "a" is an address of the value "n".

    // Print out the value of n:
    printf("%i\n", *a);  // The "*" here means to get whatever is stored in the address "a", i.e., to point to the address "a".
                         // The syntax distinction between the two uses of '*': "int *a" (declaring the pointer "a") and "*a" (dereferencing the pointer "a").
    // address arithmetic:
    printf("%p %p %p\n", a, a+1, a+2);  // "a+1" means to advance 4 bytes ("a" is "int") from address "a".

    printf("\n-----------------------------------------------------------------------------2\n");
    /* When you create a pointer and you don’t set its value immediately, you should always set the value of the pointer to "NULL" to avoid segmentation fault.
       "NULL" is technically a pointer or an address. "NULL" is a synonym for zero, but it's specifically an address ("0x0") pointing to nothing or nowhere.
       Note that "NUL" is '\0, a single character and always initialize pointers. */
    int *address = NULL;
    printf("%p\n", address);
    int value = 10;
    address = &value;
    printf("%p\n", address);

    printf("\n-----------------------------------------------------------------------------3\n");
    // Example: change the address
    int m0 = 10, m1 = 11, *m_address = &m0;
    printf("%p\n", m_address);
    printf("%p\n", &m1);
    printf("%i\n", *m_address);
    m_address = &m1;  // The address "m_address" is changed to the address of "m1".
    *m_address = 100; // Thus, "m1" will change if "*m_address" changes.
    printf("%p\n", m_address);
    printf("%i\n", *m_address);
    printf("%i\n", m1);

    printf("\n-----------------------------------------------------------------------------4\n");
    int array[3] = {1, 2, 3};
    printf("%p %p\n", array,  &array);  // In short, the array name is not a pointer, but in most contexts it is treated as though it were a pointer.
    printf("%p %p %p\n", &array[0], &array[1], &array[2]);  // "&array[i]" is a pointer who value is the address of the i th element of array.
                                                            // There is a difference of 4 bytes between two consecutive elements of array because the size of int is 4 bytes (on our compiler).
    printf("%p %p\n", array, &array[0]);  // "&array" points to array's first element as the behalf of the address of this array.
    printf("%p %p\n", array+1, &array[1]);  // "array+i" is equivalent to "&array[i]". Mostly, we use "array+i" instead of "&array[1]" to get the address of the array element.
    printf("%i %i\n", *(array+1), array[1]);  // "*(array+1)" is equivalent to "array[i]"
    int *array_p = array;  // Declare a pointer to point "array".
    printf("%p %p\n", array, array_p);
    printf("%p %p\n", array+1, array_p+1);
    // array = array_p; // This line will cause error because the array name is like a constant pointer which can't be changed.

    printf("\n-----------------------------------------------------------------------------5\n");
    // String is a special case.
    // In fact, "string <variable>" in library "cs50.h" is "char *<variable>".
    char *s = "HI!";
    printf("%p\n", s);  // "s" is an address as "a" is declared above.
    printf("%s\n", s);  // "%s" in "printf" means to go to that address and print out every character up to "\0", so you don't need to add "*" in front of "s", unlike "*a" above example.
    printf("%p %p %p\n", &s[0], &s[1], &s[2]); // s[i] is "char". Add the "&" in front of s[i] to get its address. The address of each character in the same string are consecutive because the size of int is one byte.
    printf("%p %p \n", s+1, &s[1]);  //  "s+i" can also represents the address of each character like array.
    printf("%c %c\n", s[1], *(s+1)); // Like arrays.
    printf("%p %p\n", &s[1], s+1); // Like arrays.
    printf("%p %p\n", s, &s[0]);  // "s" is the address of the first character in a string, and also represents the address of this string.
    printf("%s %s %s\n", s, s+1, s+2); // For "%s" in "printf", "s+i" means to print the string from the i-th character to "\0".
    printf("%p %p\n", s, &s);  // Here is the difference between string and array: "array" and "&array" for arrays are same, but "s" and "&s" for strings are different.
                               // Because the pointer "s" is also a variable, there is the other address to store it.

    printf("\n-----------------------------------------------------------------------------6\n");
    // Here we declare an array instead of a pointer. All results are same as above example except "s" and "&s".
    char ss[] = "HI!";
    printf("%p\n", ss);
    printf("%s\n", ss);
    printf("%p %p %p\n", &ss[0], &ss[1], &ss[2]);
    printf("%p %p \n", ss+1, &ss[1]);
    printf("%c %c\n", ss[1], *(ss+1));
    printf("%p %p\n", ss, &ss[0]);
    printf("%s %s %s\n", ss, ss+1, ss+2);
    printf("%p %p\n", ss, &ss);  //  Here "ss" and "&ss" have the same address like arrays.

    // Note that the remaining elements of the string is NUL (the ASCII number of "NUL" is "0").
    char name[6] = "Lin";
    printf("%i %i %i %i %i %i\n", name[0], name[1], name[2], name[3], name[4], name[5]);
}
