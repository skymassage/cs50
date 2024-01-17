// https://cs50.harvard.edu/x/2023/psets/5/speller/
// Compare all words in the .txt file to the dictionary and find misspelled words.
// Suggested reading order: load -> unload -> size -> hash -> check

// "./speller dictionaries/large texts/.txt" is same as "./speller texts/.txt", because "speller" will use "dictionaries/large" by default.
// "./speller dictionaries/small texts/.txt", if you want to use the small dictionary.
// Run the staff’s solution: "./speller50 texts/.txt" or "./speller50 dictionaries/small texts/.txt"

// You can compare your "speller" and staff's "speller50":
// "./speller texts/.txt > student.txt".....create two .txt files
// "./speller50 texts/.txt > staff.txt"
// "diff -y student.txt staff.txt"......... compare them side by side in the same window with a program like "diff"
// "diff -y student.txt keys/.txt"..... ....or just compare "student.txt" (the output of "speller") with the .txt file of the same name in "keys", without running "./speller50 texts/.txt > staff.txt".
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

#define ASCII 255  // Values ​​in the ASCII table are from 0 to 255.

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: choose number of buckets in hash table
const unsigned int N = LENGTH * 255;   // Consider the maximum ASCII value for each character, so the ASCII sum (the sum of ASCII value for one string) is from "0" to "LENGTH * 255".
node *table[N];  // Hash table

// TODO: returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Check "word" if in "table". Here we assume case insensitivity, i.e., no difference between uppercase and lowercase.
    char *lower_word = malloc(strlen(word)+1);  // Convert each "word" input to lowercase.
    if (lower_word == NULL)
    {
        return false;
    }
    for (int i = 0, n = strlen(word) + 1; i < n; i++)
    {
        lower_word[i] = tolower(word[i]);
        if (i == n)
        {
            lower_word[i+1] = '\0';
        }
    }

    unsigned int index = hash(lower_word);  // Find "word" might be located in which element of "table".
    for (node *ptr = table[index]; ptr != NULL; ptr = ptr->next)  // Confirm if "word" is in this linked list.
    {
        if (strcmp(lower_word, ptr->word) == 0)
        {
            free(lower_word);
            return true;
        }
    }

    free(lower_word);
    return false;
}

// TODO: hashes word to a number
unsigned int hash(const char *word)
{
    // The hash code is the ASCII sum of "word". Here we assume case insensitivity, i.e., no difference between uppercase and lowercase.
    unsigned int ascii_sum = 0;
    for (int i = 0, n = strlen(word); i < n; i++)  // The ASCII value of '\0' is 0, so we don't need to consider it.
    {
        ascii_sum += tolower(word[i]);  // Use lowercase letters to compute the ASCII value, because each string in the dictionary are lowercase.
    }
    return ascii_sum;
}

// TODO: loads dictionary into memory, returning true if successful, else false
// Method 1: read a string at a time using "scanf" (faster)
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");  // Each word in the dictionary ends with '\n' instead of '\0'.
    if (dictionary == NULL)
    {
        printf("Unable to open %s\n", dictionary);
        return false;
    }

    char s[LENGTH + 1];  // Initialise word array
    while (fscanf(file, "%s", s) != EOF)  // "fscanf" ends on reading a space or '\n', so it can scan a string from a file.
    {
        node *str = malloc(sizeof(node));  // Create new node for each word
        if (str == NULL)
        {
            return false;
        }

        strcpy(str->word, s);  // copy word into node using strcopy
        int index = hash(s);  // Hash word to obtain hash value

        str->next = table[index];  // Insert node into hash table at that location
        table[index] = str;
    }

    fclose(file);
return true;
}

// Method 2: read one character at a time using "fread" (slower)
/*bool load(const char *dictionary)
{
    // Classify each string according to the ASCII sum, i.e., each string will be assigned to the index of "table" corresponding to its the ASCII sum.
    // If the strings have the same ASCII sum, we will create the linked list in the element of "table" corresponing to this ASCII sum.
    for (int i = 0, n = N; i < n; i++)  // Initialize each pointer in "table" to NULL.
    {
        table[i] = NULL;
    }

    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    node *str = malloc(sizeof(node));  // Create a node to hold the scanned word and make the pointer in "table" point to it.
    if (str == NULL)
    {
        fclose(file);
        return false;
    }
    str->next = NULL;

    char c;
    int c_count = 0;
    while(fread(&c, sizeof(char), 1, file)) // "fread" returns the number of chunk it reads, here one chunk is "1 * sizeof(char)" bytes.
    {
        if (c != '\n')  // Each word in the dictionary ends with '\n' instead of '\0'.
        {
            str->word[c_count] = c;
            c_count++;
        }
        else
        {
            str->word[c_count] = '\0';  // Adding '\0' allows us to recognize the string.
            unsigned int ascii_sum = hash(str->word);
            if (table[ascii_sum] != NULL)  // If the strings in the dictionary have the same ASCII sum, we will build a linked list for "table[ascii_sum]".
            {
                for (node *ptr = table[ascii_sum]; ptr != NULL; ptr = ptr->next)
                {
                    if (ptr->next == NULL)
                    {
                        ptr->next = str;
                        break;
                    }
                }
            }

            else  // if table[ascii_sum] == NULL
            {
                table[ascii_sum] = str;
            }

            str = malloc(sizeof(node));  // Initialize the node.
            if (str == NULL)
            {
                unload();  // Don't forget to free all pointers in "table", if str == NULL.
                fclose(file);
                return false;
            }
            str->next = NULL;
            c_count = 0;
        }
    }

    free(str);
    fclose(file);
    return true;
}*/

// TODO: returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // Compute the number of nodes in "table".
    unsigned int count = 0;
    for (int i = 0, n = N; i < n; i++)
    {
        if (table[i] != NULL)
        {
            for (node *ptr = table[i]; ptr != NULL; ptr = ptr->next)
            {
                count++;
            }
        }
        else
        {
            continue;
        }
    }

    return count;
}

// TODO: unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Free the linked list corresponding to each pointer in the table.
    for (int i = 0, n = N; i < n; i++)
    {
        if (table[i] != NULL)
        {
            while (table[i] != NULL)
            {
                node *ptr = table[i]->next;
                free(table[i]);
                table[i] = ptr;
            }
        }
        else
        {
            continue;
        }
    }

    return true;
}