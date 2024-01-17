// Sorted list using linked list.
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

        if (list == NULL) // If list is empty.
        {
            list = n;
        }

        else if (n->number < list->number) // If number belongs at beginning of list.
        {
            n->next = list;
            list = n;
        }
        else // If number belongs later in list.
        {
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                if (ptr->next == NULL) // If at end of list.
                {
                    ptr->next = n;
                    break;
                }

                if (n->number < ptr->next->number) // If in middle of list.
                {
                    n->next = ptr->next;
                    ptr->next = n;
                    break;
                }
            }
        }
    }

    for (node *ptr = list; ptr != NULL;)
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