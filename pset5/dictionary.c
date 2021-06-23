#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <strings.h>

#include "dictionary.h"

// Hash Table size.
const int HASHTABLE_SIZE = 65536;

// Defines Single-Linked List node.
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Creates Hash Table.
node *hash_table[HASHTABLE_SIZE];

// Returns integer hash value for a given a string
// Hash link: https://www.reddit.com/r/cs50/comments/1x6vc8/pset6_trie_vs_hashtable/cf9nlkn/
int hash(const char* needs_hashing)
{
    unsigned int hash = 0;
    for (int i=0, n = strlen(needs_hashing); i < n; i++)
    {
        hash = (hash << 2) ^ needs_hashing[i];
    }
    return hash % HASHTABLE_SIZE;
}

//  Returns true if word is in dictionary else false.
bool check(const char *word)
{
    char lower_case[LENGTH + 1];

    // Converts to lowercase chars.
    for (int i = 0; i < LENGTH + 1; i++)
    {
        lower_case[i] = tolower(word[i]);
    }

    // Starts the Single-Linkes List.
    node *cursor = hash_table[hash(lower_case)];

    // Travels trought the list.
    while (cursor != NULL)
    {
        // Checks if the word is on the dictionary.
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        // Goes to next node.
        cursor = cursor->next;
    }
    return false;
}

// Loads dictionary into memory and returns true if successful else false.
bool load(const char *dictionary)
{
    char word[LENGTH + 1];

    // Opens the dictionary.
    FILE *dict = fopen(dictionary, "r");

    // Iterate through dictionary words.
    while (fscanf(dict, "%s", word) != EOF)
    {
        // Makes a new word.
        node *new_node = malloc(sizeof(node));

        // Checks for error assigning memory.
        if (new_node == NULL)
        {
            fclose(dict);
            return false;
        }
        else
        {
            // Copy word into node.
            strcpy(new_node->word, word);
            
            // Insert word into the linked list.
            int n = hash(new_node->word);
            
            new_node->next = hash_table[n];
            hash_table[n] = new_node;
        }
    }
    
    // close dictionary
    fclose(dict);

    return true;
}

// Returns number of words in dictionary.
unsigned int size(void)
{
    int counter = 0;

    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        // Set the pointer to head of list.
        node *cursor = hash_table[i];

        // Travel throught the list.
        while (cursor != NULL)
        {
            counter++;
            cursor = cursor->next;
        }
    }
    return counter;
}

// Unloads dictionary from memory and returns true if successful else false.
bool unload(void)
{
    // iterate through hashtable
    for (int i = 0; i < HASHTABLE_SIZE; i++)
    {
        // set pointer to head of list
        node *cursor = hash_table[i];

        // traverse list
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
        free(cursor);
    }
    return true;
}
