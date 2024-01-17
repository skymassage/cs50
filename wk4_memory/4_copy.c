#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // Using '=' for copying a string means to copy an address. This doesn't really copy a string.
    char *s1 = get_string("Input a lowercase string s1: ");

    char *t1 = s1;
    if (strlen(t1) > 0)  /* If the length of "t1" is zero, it may cause a segmentation fault (segfault).
                            For instance, if I just hit Enter, there's no characters to uppercase. This could theoretically create a segfault. */
    {
        t1[0] = toupper(t1[0]);  // Since "t1" and "s1" are the same address, the strings printed by "t1" and "s1" change simultaneously.
    }

    printf("s1: %s\n", s1);
    printf("t1: %s\n", t1);
    printf("s1: %p\n", s1);
    printf("t1: %p\n", t1);
    printf("--------------------------\n");

    //------------------------------------------------------------------------------------------------------------------------------------------------------

    // You should use the functions "malloc" and "free" from the library "stdlib.h" to copy a string as below:
    char *s2 = get_string("Input a lowercase string s2: ");
    if (s2 == NULL)      // Suppose you type a very long string into "get_string", such as an entire essay of text. And there's not enough memory to fit in such a big string.
    {                    // It turns out that "get_string" will return a special value, called "NULL", if something goes wrong.
        return 1;        // So if "s" equals to "NULL", then you better exit the program entirely and return like '1', or '2', or other value to signify that something went wrong. Don't go any further.
    }

    char *t2 = malloc(strlen(s2) + 1);  /* Use "malloc" to ask for computer to allocate "strlen(s) + 1" bytes in memory,
                                           and "malloc" will return a pointer pointing to a chunk of memory whose size is "strlen(s) + 1" bytes,
                                           where this address is actually the address of the first element in this array and also represents this chunk of memory.
                                           Note that we request a string here, so "strlen(s) + 1" means the length of the string plus '\0'. */
    if (t2 == NULL)  // Similarly with "malloc", it's possible to potentially return "NULL", because the computer might not provide you enough memory if you ask for too much memory, that could fail.
    {                // You should check for null after "malloc" when you are allocating the memory.
        return 1;    // In class, we tend not to do this above always because the code just gets so bloated and complicated.
    }                // However, you absolutely in practice need to start doing this to avoid encountering the freezes, and the crashes, and the reboots.

    for (int i = 0, length = strlen(s2) + 1; i < length; i++)  // Copy string into memory, including '\0'
    {
        t2[i] = s2[i];
    }

    if (strlen(t2) > 0)
    {
        t2[0] = toupper(t2[0]);
    }

    printf("s2: %s\n", s2);
    printf("t2: %s\n", t2);
    printf("s2: %p\n", s2);
    printf("t2: %p\n", t2);
    printf("--------------------------\n");

    free(t2); /* We asked the computer for memory via "get_string" and "malloc", and never technically hand it back.
                 So we should use the function "free" to free the memory we've asked for.
                 Henceforth, it is a rule, a law, if you will in C, whenever you allocate memory with "malloc", or certain other functions as well, you must free it when you're all done with it.
                 Technically, when programs quit, they'll free the memory automatically, so you're not going to break.
                 But for programs that are running all the time, like someone keeps a Chrome, their browser open, Microsoft Word.
                 If over time, you never call "free" and the program keeps running, bad things will happen. So always get into this habit here.
                 Here you don't need the free memory that comes from "get_string" because the "cs50.h" library automatically frees it for you.
                 Note that you still have the pointer "t2" after "free" this chunk of memory, so the value "t2" pointing is a garbage value, but you can assign a new pointer to "t2". */

    //------------------------------------------------------------------------------------------------------------------------------------------------------

    // You can alos use the "strcpy" from the library "stdlib.h" to copy a string:
    char *s3 = get_string("Input a lowercase string s3: ");
    if (s3 == NULL) {return 1;}

    char *t3 = malloc(strlen(s2) + 1);
    if (t3 == NULL) {return 1;}

    strcpy(t3, s3);  // Note that "strcpy" does the same job as our "for loop" in the previous example.

    if (strlen(t3) > 0)
    {
        t3[0] = toupper(t3[0]);
    }

    printf("s3: %s\n", s3);
    printf("t3: %s\n", t3);
    printf("s3: %p\n", s3);
    printf("t3: %p\n", t3);

    free(t3);

    return 0;
}
/* Dynamic memory allocation is the process of assigning the memory space during the execution time or the run time.
   Dynamically allocated memory comes from a pool of memory known as the "heap".
   Prior to this point, all memory we've been working with has been coming from a pool of memory known as the "stack".
   We get this dynamically-allocated memory by making a call to the C standard library function "malloc()", passing as its parameter the number of bytes requested.
   After obtaining memory for you (if it can), malloc() will return a pointer to that memory.
   What if malloc() can't give you memory? It'll hand you back "NULL".
   Dynamically-allocated memory is not automatically returned to the system for later use when the function in which it's created finishes execution.
   Failing to return memory back to the system when you're finished with it results in a memory leak which can compromise your system's performance.
   When you finish working with dynamically-allocated memory, you must free it by the function "free()". */