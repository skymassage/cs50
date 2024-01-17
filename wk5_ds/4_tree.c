// Implements a list of numbers as a binary search tree
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Represents a node
typedef struct node
{
    int number;
    struct node *left;
    struct node *right;
}
node;

void free_tree(node *root);   // Free tree
void print_tree(node *root);  // Print tree
bool search(node *tree, int number);  // Search whether the number exists in the tree

int main(int argc, char *argv[])
{
    // Tree of size 0
    node *tree = NULL;

    node *n = malloc(sizeof(node));  // Add number "2" to list.
    if (n == NULL)
    {
        return 1;
    }
    n->number = 2;
    n->left = NULL;
    n->right = NULL;
    tree = n;

    n = malloc(sizeof(node));  // Add number "1" to list.
    if (n == NULL)
    {
        free_tree(tree);  // Remember free the allocated memory.
        return 1;
    }
    n->number = 1;
    n->left = NULL;
    n->right = NULL;
    tree->left = n;

    n = malloc(sizeof(node));  // Add number "3" to list.
    if (n == NULL)
    {
        free_tree(tree);
        return 1;
    }
    n->number = 3;
    n->left = NULL;
    n->right = NULL;
    tree->right = n;

    print_tree(tree);

    if (argc != 2)
    {
        printf("Usage: ./tree <number>\n");
        free_tree(tree);  // Remember free the memory before returning.
        return 1;
    }

    if (search(tree, atoi(argv[1])))
    {
        printf("\"%s\" is in the tree.\n", argv[1]);
    }
    else
    {
        printf("\"%s\" is not in the tree.\n", argv[1]);
    }

    free_tree(tree);
    return 0;
}

void free_tree(node *root)
{
    if (root == NULL)
    {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
    //return;
}

void print_tree(node *root)
{
    if (root == NULL)
    {
        return;
    }
    print_tree(root->left);
    printf("%i\n", root->number);
    print_tree(root->right);
    //return;
}

bool search(node *tree, int number)
{
    if (tree == NULL)
    {
        return false;
    }
    else if (number < tree->number)
    {
        return search(tree->left, number);
    }
    else if (number > tree->number)
    {
        return search(tree->right, number);
    }
    else // number == tree->number
    {
        return true;
    }
}