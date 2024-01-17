// Stack using linked list.
#include <stdio.h>
#include <stdlib.h>

// Any time you're building a node, a linked list in memory, this is just the paradigm:
typedef struct node  // Preemptively call this whole thing struct "node", you can refer to the thing on the inside as a struct "node *".
{
    int number;
    struct node *next;  // The thing the pointer "next" pointing to is a structure, so the type declared must be a structure, i.e., using "struct".
                        // Note that you must declare the structure "node" preemptively for self-reference.
}
node;  // It is not necessary to use "node" to name this data structure, you can change it to other names.

void free_list(node *list);  // It can free the entire linked list.

int main(int argc, char *argv[])
{
    // The name of an array is technically a label for an memory address. The program knows maps to a specific location in memory, so the name of an array does not take up space.
    // However, you do need that extra space when implementing a linked list so that you can determine if the list is of size zero there's nothing being pointed at ("NULL") and konw where is the start of the list.
    node *list = NULL;

    for (int i = 1; i < argc; i++)
    {
        int number = atoi(argv[i]);  // "argv[i]" is a string, so you need to convert it to "int".

        node *n = malloc(sizeof(node));  // Allocate the enough bytes for one node whose size equals to the bytes of a structure declared as "node".
        if (n == NULL)
        {
            if (list != NULL)     // Note that when calling malloc in this loop, it's fine if the first call to "malloc" fails and returns "NULL".
            {                     // But if the first call fails, "NULL" will be returned, causing a memory leak, because the previous memory successfully allocated using "malloc" has not been freed.
                free_list(list);  // It should write a function to free any previously created nodes.
            }
            return 1;
        }
        n->number = number; // "n->number" means (*n).number: the arrow operator "->" goes to an address and looks inside of a structure.
        n->next = NULL; // Get rid of the garbage value in "(*n).next".

        n->next = list;
        list = n;
    }

    for (node *ptr = list; ptr != NULL; ptr = ptr->next) // Create a pointer to indicate which node is currently in "while" loop.
    {
        printf("%i\n", ptr->number);
    }

    node *ptr = list;
    while (ptr != NULL)  // Can also use "for" loop as above.
    {
        node *next = ptr->next; // Create a temporary variable to avoid not finding the next node after free "ptr".
        free(ptr);
        ptr = next;
    }

    /*while (list != NULL)  // Or use this loop to free memory.
    {
        node *ptr = list->next;
        free(list);
        list = ptr;
    }*/

    //free_list(list);  // You can also replace the above "while" loop with this line to free memory.

    return 0;
}


// "free_list" can be written in two ways.
// Method 1: recursion
void free_list(node *list)
{
    if (list == NULL)
    {
        free(list);
        return;
    }
    free_list(list->next);
    free(list);
    return;
}

// Method 2: loop
/*void free_list(node *list)
{
    while (list != NULL)
    {
        node *ptr = list->next;
        free(list);
        list = ptr;
    }
}*/