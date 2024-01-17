// Queue using linked list.
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

void free_list(node *list);

int main(int argc, char *argv[])
{
    node *list = NULL;
    node *last = list;

    for (int i = 1; i < argc; i++)
    {
        int number = atoi(argv[i]);

        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            if (list != NULL)
            {
                free_list(list);
            }
            return 1;
        }
        n->number = number;
        n->next = NULL;

        if (list == NULL)
        {
            list = n;
        }
        else
        {
            last->next = n;
        }

        last = n;
    }

    for (node *ptr = list; ptr != NULL;)  // Print and free simultaneously.
    {
        printf("%i\n", ptr->number);
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }

    return 0;
}

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