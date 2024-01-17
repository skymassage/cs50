// Execute: ./license plates.txt
// Check for Memory Leaks: valgrind: ./license plates.txt
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./read infile\n");
        return 1;
    }

    char buffer[7];
    char *plates[8];  // Each element in the array is a pointer.

    FILE *infile = fopen(argv[1], "r");
    if (infile == NULL) {return 1;}

    int idx = 0;

    while (fread(buffer, 1, 7, infile) == 7)  // "fread" returns the number of blocks of data. If the return of "fread" is not 7, it means "fread" encounters the end of the file.
    {
        buffer[6] = '\0';  // Replace '\n' with '\0'

        plates[idx] = malloc((strlen(buffer)+1)*sizeof(char));  // Allocate the enough memory (depending on the string length) to each pointer for copying.
        if (plates[idx] == NULL) {return 1;}
        for (int i = 0; i < 7; i++)  // The names of "plates[idx]" and "buffer" are also pointing to the first character, so you should use loop to caopy.
        {
            *(plates[idx]+i) = *(buffer+i);
        }
        idx++;
    }

    for (int i = 0; i < 8; i++)
    {
        printf("%s\n", plates[i]);
    }

    for (int i = 0; i < 8; i++)
    {
        free(plates[i]);
    }
    fclose(infile);
    return 0;
}
