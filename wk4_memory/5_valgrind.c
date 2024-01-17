#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // This is how we request enough memory for an array as before: int x[];
    // Here's how to manually requesting a chunk of memory for an array of 3 elements:
    // "malloc" returns the address of the first byte you get back and we store it in the address "*x".
    int *x = malloc(3 * sizeof(int)); // "sizeof" is to obtain how many bytes the data types or variables take up on the system. Here "sizeof(int)" is "4", so we ask for 12 bytes from memory.
    if (x == NULL)
    {
        return 1;
    }
    x[1] = 72;
    x[2] = 73;
    x[3] = 33;
    // Compile this program first by command "make" and run.
    // And it seems to work fine without bugs, but it doesn't mean there aren't bugs latent in the software.
    // You can use command "valgrind" to find memory errors while executing.
    // You will find some lines in the terminal window indicating errors:
    // 1) Invalid write of size four:
    //    After the allocating 12 bytes of memory, we somehow wrote (changed) 4 bytes incorrectly.
    //    That is, you assign a value to "x[3]" which is too far past the requested chunk of memory and shouldn't be touched.
    // 2) 12 bytes in 1 blocks are definitely lost in loss record 1 of 1:
    //    This means the memory is lost. AKA, this is a memory leak.
    //    You didn't call "free" to free the requested memory that results in memory leak.

    // Common memory errors:
    // Failing to free every block of memory which we've malloc'd.
    // Failing to fclose every file we've fopened.
    // Using more memory than we've allocated. ex: the length of a string larger than the allocated memory.

    /*
    // You can modify your code as follows and run valgrind again to check if memory errors:
    x[0] = 72;
    x[1] = 73;
    x[2] = 33;
    free(x);
    */

    return 0;
}