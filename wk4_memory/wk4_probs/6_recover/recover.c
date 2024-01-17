// https://cs50.harvard.edu/x/2023/psets/4/recover/
// Execute: ./recover card.raw
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover card.raw\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {return 1;}

    FILE *outfile = NULL;
    BYTE buffer[BLOCK_SIZE];
    char *outfile_name = malloc(8 * sizeof(char));  // Don't declare "char outfile_name[8]", because "outfile_name" is constant and can't be changed.
                                                    // Declaring "char *outfile_name = NULL" will result in a segfault, because you don't prescribe the length and it touches the untouchable memory.
    int count = 0;
    bool open = false;

    while (fread(buffer, 1, BLOCK_SIZE, file))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)  // The bitwise-AND operator '&' compares each bit of its first operand to the corresponding bit of its second operand. If both bits are 1, the corresponding result bit is set to 1. Otherwise, the corresponding result bit is set to 0.
        {
            if (open)  // Note that the output file must be closed after each opening.
            {
                fclose(outfile);
                open = false;
            }
            sprintf(outfile_name, "%03i.jpg", count);  // "sprintf" stores a formatted string at a location in memory, where "%03i" means to print an integer with three digits to represent it.
            outfile =  fopen(outfile_name, "w");
            count++;
            open = true;
        }

        if (outfile != NULL)
            fwrite(buffer, 1, BLOCK_SIZE, outfile);
    }

    free(outfile_name);
    fclose(outfile);  // Note the last output file is closed here, not in the "while" loop.
    fclose(file);

    return 0;
}