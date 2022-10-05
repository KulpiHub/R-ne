// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"
// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;
// TODO: Choose number of buckets in hash table
enum {N = 500};
// Hash table
node *table[N];
int dictionary_s = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int check_index = hash(word);

    node *current = table[check_index];

    while (current != NULL)
    {
        if (strcasecmp(current -> word, word) == 0)
        {
            return true;
        }
        current = current -> next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int val = 0;
    int hash_key = strlen(word);

    for (int i = 0; i < hash_key; i++)
    {
        val = val + (37 * tolower(word[i]));
    }
    val = val % N;
    return val;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *dictionary_p = fopen(dictionary, "r");
    char new_word[LENGTH + 1];

    if (dictionary == NULL)
    {
        printf("Program can't open %s\n", dictionary);
        return false;
    }

    while (fscanf(dictionary_p, "%s", new_word) != EOF)
    {

        node *next_node = malloc(sizeof(node));

        if (next_node == NULL)
        {
            return false;
        }

        strcpy(next_node -> word, new_word);
        next_node -> next = NULL;
        int hash_index = hash(new_word);

        if (table[hash_index] == NULL)
        {
            table[hash_index] = next_node;
        }
        else
        {
            next_node -> next = table[hash_index];
            table[hash_index] = next_node;
        }
        dictionary_s++;
    }
    fclose(dictionary_p);
    return true;
}



// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return dictionary_s;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        while (table[i] != NULL)
        {
            node *temp = table[i] -> next;
            free(table[i]);
            table[i] = temp;
        }
    }
    return true;
}
