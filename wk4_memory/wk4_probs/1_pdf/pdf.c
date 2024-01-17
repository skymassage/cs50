// All PDFs will begin with a four byte sequence known as a file signature, corresponding to these integers: 37, 80, 68, 70.
// Similar for JPG files.
// Execute: ./pdf test.pdf
// Execute: ./pdf test.jpg
#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Improper usage.\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (input == NULL)  //check if file exists
    {
        printf("No such file found.\n");
        return 1;
    }

    uint8_t signature[] = {37, 80, 68, 70};  // A PDF file storeing the special type is "uint8_t" which is from the library "stdint.h".
    uint8_t buffer[4];  // uint8_t: the 8 denotes only 8 bits, a single byte for an integer. the underscore t here means that all that together, this unsigned integer of 8 bits, is going to be its own type.

    fread(buffer, 1, 4, input);  // sizeof(uint8_t) = 1
    fclose(input);  // close file here after "fread", so you don't close it before "return 0;" in both places below.

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", buffer[i]);
    }

    // Does the buffer signature match?
    for (int i = 0; i < 4; i++)
    {
        if (buffer[i] != signature[i])
        {
            printf("Likely not a PDF.\n");
            return 0;
        }
    }

    printf("Likely a PDF.\n");
    return 0;
}