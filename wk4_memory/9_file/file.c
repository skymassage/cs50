#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // fopen(<file name>, <operation>): open or create a file and return a file pointer to it.
    FILE *file_pointer1 = fopen("file1.csv", "a"); // fopen(<file name>, <operation>): open a file and return a file pointer to it.
                                                  // fopen(<file_name>, "r"): let you read information from file
                                                  // fopen(<file_name>, "w"): let you pass the file pointer as an argument to any function that can write to this file.     // "w" is going to overwrite the entire file, i.e., deleting all the existing information and then starting writing at the very beginning.
                                                  // fopen(<file_name>, "a"): is "append". "a" will go to the end of the file if there's already text or information in it, and it will then start writing from there.
                                                  // "FILE" is typically termed an opaque data type which is a user-defined or built-in data type that is fully encapsulated.
    if (file_pointer1 == NULL) {return 1;} // Always check the return value to make sure you don’t get back NULL.
    char *name = get_string("Name: ");
    char *number = get_string("Number: ");
    fprintf(file_pointer1, "%s, %s\n", name, number);  // Write a formatted string to a file.

    FILE *file_pointer2 = fopen("file1.csv", "r");
    if (file_pointer2 == NULL) {return 1;}
    char str[10];
    fscanf(file_pointer2, "%s", str);  // "fscanf" ends on reading a space or '\n', so it can scan a string from a file.
    printf("%s\n", str);
    printf("---------------------------");

    // fgetc(<file pointer>): reads and returns the next character from the file pointed to.
    FILE *file_ptr1 = fopen("file1.csv", "r");  // The pointer must be "r" for read.
    if (file_ptr1 == NULL) {return 1;}
    char ch;
    while((ch = fgetc(file_ptr1)) != EOF)  // "EOF" is is the end of file character.
        printf("%c", ch);

    // fputc(<character>, <file pointer>): write or append the specified character to the pointed-to file.
    FILE *file_ptr2 = fopen("file2.csv", "w"); // The file pointer passed in as a parameter must be "w" or "a".
    if (file_ptr2 == NULL) {return 1;}
    FILE *file_ptr_for_fputc = fopen("file1.csv", "r"); // Declare a new file pointer for the next "fgetc"  because the previous file pointer has been read to "EOF" by the former "fgetc".
    if (file_ptr_for_fputc == NULL) {return 1;}
    while((ch = fgetc(file_ptr_for_fputc)) != EOF) // Copy the contents to another file.
        fputc(ch, file_ptr2);

    // fclose(<file pointer>): closes the file pointed to by the given file pointer.
    fclose(file_pointer1);  // make sure always to close files before program end to free memory and avoid memory leak.
    fclose(file_pointer2);
    fclose(file_ptr1);
    fclose(file_ptr2);
    fclose(file_ptr_for_fputc);
}

/*
// fread(<buffer>, <size>, <qty>, <file pointer>): read <qty> units of size <size> in bytes from the file pointed to and store them in memory in a buffer (usually an array) pointed to by <buffer>.
// "fread" returns the number of blocks of data which genelally equals to <qty>, if smaller than <qty>: "fread" encounters "EOF" or errors.
FILE *file_pointer = fopen("file1.csv", "r") // Note that <file pointer> must be "r" for read.
int buff[10]; // read 40 (= size of "int" times 10) bytes of information from the file1 pointed to by file_pointer, and store it in arr.
fread(buff, sizeof(int), 10, file_pointer);
double *buff = malloc(sizeof(double) * 80);  // We could also dynamically allocate a buffer using "malloc" to request 640 bytes.
fread(buff, sizeof(double), 80, file_pointer);
char c;  // Treat "fread" just like a call to "fgetc" as well. Note that "&c" because "c" is not an array.
fread(&c, sizeof(char), 1, file_pointer);  // Note that <buffer> is a pointer, i.e. "&c".
*/

// fwrite(<buffer>, <size>, <qty>, <file pointer>): writes <qty> units of size <size> to the file pointed to by reading them from a buffer (usually an array) pointed to by <buffer>. the operation is similar to "fread".