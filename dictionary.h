/**
 * Declares a dictionary's functionality.
 */

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<strings.h>
#include<stdbool.h>
// maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45
#define HASH_L 26

typedef struct ll{
    struct ll * prev;
    struct ll * next;
    char word[LENGTH];
}LLNode;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word);

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary);

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void);

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void);

#endif // DICTIONARY_H

/// these below are additional functions i've created to make implementation of those 4 above functions easier 

LLNode * addnewNode(int boxToAdd); //// adds  new node (at the beginning) to the given linked list

void destroy(LLNode * head);   //// frees memory of one linked list

unsigned int length(LLNode * head);   //// returns the length given linked list

unsigned int hash(const char * wordToHash);  //// returns a "hash" number based on provided word
