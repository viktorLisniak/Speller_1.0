/**
 * Implements a dictionary's functionality.
 */

#include "dictionary.h"

LLNode * hashtable[HASH_L];

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char * tofind){
    int box = hash(tofind);
    char tem[LENGTH]; for (int k = 0; k < LENGTH; k++){ tem[k] = 0; }
    if(box < 0) { printf("box: %d %s\n", box, tofind); return false;} ////debug negative indexes 
    LLNode * tempnode = hashtable[box];
    while(tempnode != NULL){
        strcpy(tem, tempnode->word);
        if(0 == strcasecmp(tofind, tem)){
            return true;
        }
        tempnode = tempnode->next;
    }
    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char * dictionary){
    char toload[LENGTH]; for(int k = 0; k < LENGTH; k++){ toload[k] = 0; }
    FILE * inputfile = fopen(dictionary, "r");
    while(fscanf(inputfile, "%s", toload) != EOF){
        int box = hash(toload);
        LLNode * node = addnewNode(box);
        if(node == NULL){
            return false;
        }
        strcpy(node->word, toload);
        //printf("node->word: %s\n", hashtable[box]->word); // debug
    }
    fclose(inputfile);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void){
    unsigned int size = 0;
    for(int i = 0; i < HASH_L; i++){
        size += length(hashtable[i]);
    }
    return size;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void){
    for(int i = 0; i < HASH_L; i++){
        destroy(hashtable[i]);
    }
    for(int no = 0; no < HASH_L; no++){
        hashtable[no] = NULL;
    }
    int nulls = 0;
    for(int i = 0; i < HASH_L; i++){
        if(hashtable[i] == NULL){
            nulls++;
        }
    }
    if(nulls == 26){
        return true;
    }
    return false;
}


/// these below are my own functions i've created to make implementation of 4 needed functions easier 

LLNode * addnewNode(int boxToAdd){
    LLNode * node = (LLNode*)malloc(1*sizeof(LLNode)); 
    if(node==NULL){
        printf("You're out of memory");
    }
    if(hashtable[boxToAdd]==NULL){
        hashtable[boxToAdd] = node;
    }else{
        node->next = hashtable[boxToAdd];
        hashtable[boxToAdd]->prev = node;
        hashtable[boxToAdd] = node;
    }
    return node;
}

void destroy(LLNode * head){
    if(head==NULL){
        return;
    }
    else
    {
        destroy(head->next);
        free(head);
    }
}

unsigned int length(LLNode * head){
    int length = 0;
    LLNode * temp = head;
    while(temp != NULL){
        length++;
        temp = temp->next;
    }
    return length;
}

unsigned int hash(const char * wordToHash){
    unsigned int num = 0;
    num = tolower(wordToHash[0]) - 'a';
    return num;
}