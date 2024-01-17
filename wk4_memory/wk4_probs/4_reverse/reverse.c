#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // TODO #1: ensure proper usage
    if (argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav\n");
        return 1;
    }

    // TODO #2: open input file for reading
    FILE *infile = fopen(argv[1], "r");
    if (infile == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // TODO #3: read header
    WAVHEADER header;
    fread(&header, sizeof(WAVHEADER), 1, infile);

    // TODO #4: use check_format to ensure WAV format
    if (!check_format(header))
    {
        printf("Input is not a WAV file.\n");
        return 1;
    }

    // TODO #5: open output file for writing
    FILE *outfile = fopen(argv[2], "w");
    if (outfile == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // TODO #6: write header to file
    fwrite(&header, sizeof(WAVHEADER), 1, outfile);

    // TODO #7: use get_block_size to calculate size of block
    int block_size = get_block_size(header); // block_size = 4 bytes (two channel and two bytes per channel)
    //printf("%i\n", header.numChannels);    // 2 channels
    //printf("%i\n", header.bitsPerSample);  // 16 bits per sample (2 bytes per sample)

    // TODO #8: write reversed audio to file
    BYTE buffer[block_size];  // Four elements in "buffer", each element is one byte, and each sample per channel is 2 bytes (elements).

    // fseek(file pointer, num, start):
    // for the file pointer, the position incidactor in the file advances "num" bytes (advance in bytes, negative means backward) from "start",
    // where "start" is "SEEK_SET", "SEEK_CUR" or "SEEK_END", corresponding to the "starting", "current" and "ending" positions of the file respectively.

    fseek(infile, 0, SEEK_END); // The file position indicator advances "0" byte from the end, so the current position is at the end of the file and the value is 0.
    long header_size = sizeof(WAVHEADER);
    long audio_size = ftell(infile) - header_size; // ftell(file pointer): obtain the current file position indicator for the file pointer, where the type of the file position indicator is "long".
    long audio_block_num = audio_size / block_size;

    /* // Method 1
    for (long i = audio_block_num; i > 0; i--)  // Declare "long", because "audio_block_num" may be very large.
    {
        fseek(infile, -block_size, SEEK_CUR);
        fread(buffer, block_size, 1, infile);
        fwrite(buffer, block_size, 1, outfile);
        fseek(infile, -block_size, SEEK_CUR);
    }*/

    // Method 2
    while (ftell(infile) != header_size)
    {
        fseek(infile, -block_size, SEEK_CUR);
        fread(buffer, block_size, 1, infile);
        fwrite(buffer, block_size, 1, outfile);
        fseek(infile, -block_size, SEEK_CUR);
    }

    /* // Method 3
    for (long i = audio_block_num - 1; i >= 0; i--)  // Note that we read backward from the position "header_size + (audio_block_num - 1) * block_size" and loop "audio_block_num" times.
    {
        fseek(infile, header_size + i * block_size, SEEK_SET);
        fread(buffer, block_size, 1, infile);
        fwrite(buffer, block_size, 1, outfile);
    }
    */

    fclose(infile);
    fclose(outfile);
}

int check_format(WAVHEADER header)
{
    // TODO #4
    if (header.format[0] == 'W' && header.format[1] == 'A' && header.format[2] == 'V' && header.format[3] == 'E')
    {
        return true;
    }

    return false;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    return header.numChannels * (header.bitsPerSample / 8);
    // The type of "header.numChannel"s and "header.bitsPerSample" is actually "uint16_t".
    // For "unsigned int" corrsponding to "uint16_t", the range of "uint16_t" is 0x0000~0xFFFF (0~65535).
    // For non-negative integer, it can't exceed 65535, but the compuational result can exceed 65535 if the range of the type of result declared is over exceed.
    // However, if the type of computional result declared is "uint16_t", the result can only cycle through 0 to 65535
    // Ex: take uint8_t as the example
    //     uint8_t a = 255, b = 2;  // "a" and "b" can't exceed 255
    //     int c = a * b;           // "c" is 510 because it's "int".
    //     uint8_t d = a * b;       // "d" is 254, because "d" is "uint8_t" and it can only cycle through 0 to 255.
}