// https://cs50.harvard.edu/x/2023/problems/5/trie/
// Input a name and confirm it if in "dog_names.txt".
#include <cs50.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_OF_ALPHABET 26
#define MAXCHAR 20

typedef struct node
{
    bool is_word;
    struct node *children[SIZE_OF_ALPHABET];
}
node;

// Function prototypes
bool check(char *word);
bool unload(void);
void unloader(node *current);

// Root of trie
node *root;

// Buffer to read dog names into
char name[MAXCHAR];

int main(int argc, char *argv[])
{
    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./trie infile\n");
        return 1;
    }

    // File with names
    FILE *infile = fopen(argv[1], "r");
    if (!infile)
    {
        printf("Error opening file!\n");
        return 1;
    }

    // Allocate root of trie
    root = malloc(sizeof(node));

    if (root == NULL)
    {
        return 1;
    }

    root->is_word = false;
    for (int i = 0; i < SIZE_OF_ALPHABET; i++)
    {
        root->children[i] = NULL;
    }

    // Add words to the trie
    while (fscanf(infile, "%s", name) == 1)  // "fscanf" can find the string in the file pointer and store it in a pointer.
    {
        node *cursor = root;

        for (int i = 0, n = strlen(name); i < n; i++)  // We don't need "\0".
        {
            int index = tolower(name[i]) - 'a';
            if (cursor->children[index] == NULL)
            {
                // Make node
                node *new = malloc(sizeof(node));
                new->is_word = false;
                for (int j = 0; j < SIZE_OF_ALPHABET; j++)
                {
                    new->children[j] = NULL;
                }
                cursor->children[index] = new;
            }

            // Go to node which we may have just been made
            cursor = cursor->children[index];
        }

        // if we are at the end of the word, mark it as being a word
        cursor->is_word = true;
    }

    if (check(get_string("Check word: ")))
    {
        printf("Found!\n");
    }
    else
    {
        printf("Not Found.\n");
    }

    if (!unload())
    {
        printf("Problem freeing memory!\n");
        return 1;
    }

    fclose(infile);
}

// TODO: Complete the check function, return true if found, false if not found
bool check(char* word)
{
    node *cursor = root;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        int index = toupper(word[i]) - 'A';
        if (cursor->children[index] == NULL)
        {
            return false;
        }
        else
        {
            cursor = cursor->children[index];
        }

        if (cursor->is_word)
        {
            return true;
        }
    }

    return false;
}

// Unload trie from memory
bool unload(void)
{
    unloader(root); // The recursive function handles all of the freeing
    return true;
}

void unloader(node* current)
{
    for (int i = 0; i < SIZE_OF_ALPHABET; i++) // Iterate over all the children to see if they point to anything and go there if they do point.
    {
        if (current->children[i] != NULL)
        {
            unloader(current->children[i]);
        }
    }
    free(current); // After we check all the children point to null we can get rid of the node and return to the previous iteration of this function.
}
