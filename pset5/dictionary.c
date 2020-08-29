/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * 
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdint.h>

#include "dictionary.h"

#define hashSize 2048


//Define hash table:
typedef struct node {
    char word[LENGTH + 1];
    struct node* next;
} node; 

// prototype
int hashIt(const char* word);

// global word varialbes
int wordCount = 0;

//create the hashTable
node* hashtable[hashSize] = {NULL};
/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    
    int v = hashIt(word);
    node* new_node = hashtable[v];

    while(new_node != NULL) {
        if (strcasecmp(word, new_node -> word) == 0) {
            return true;
        } 
        new_node = new_node -> next;
    }
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // open input file 
    FILE* inptr = fopen(dictionary, "r");
    if (inptr == NULL)
    {
        return false;
    }

    while(!feof(inptr)) {
    
        //Lets malloc a new node
        node* new_node = malloc(sizeof(node));
        
        //and take a word from the file and put it in the new node
        fscanf(inptr, "%s\n", new_node->word); 

        //run the word through hash to find the location
        char* word = new_node->word;
        int v = hashIt(word);
        wordCount++;
        //if that bucket is empty set it
        if (hashtable[v] == NULL) {
            new_node -> next = NULL;
            hashtable[v] = new_node;
            
        }else{
            new_node -> next = hashtable[v] -> next;
            hashtable[v] -> next = new_node;
        }
    }

    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return wordCount;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    for (int i = 0; i < hashSize; i++){
        
        node* cursor = hashtable[i];
        while (cursor != NULL) {
            node* nodes = cursor;
            cursor = cursor->next;
            free(nodes);
        }
    }
     
    return true;
}

//HASH FUNCTION NEEDS IMPROVING IN ORDER TO INCREASE THE SPEED OF THE PROGRAM:
int hashIt(const char *word) {
    int len = strlen(word);
    int hash = 0;

    for(int i = 0; i < len; i++) {
        int x = word[i];
        if (x > 64 && x < 91) {
            hash += word[i] + 32;
        } else {
            hash += word[i];
        }
    }
    
    return hash % hashSize; 
}
/*
uint32_t hashIt(const char* word)
{
    unsigned len = strlen(word);
    uint32_t hash = 2166136261;
    for(int i = 0; i<len; i++){
        
        int x = word[i];
        if (x > 64 && x < 91) {
            x = word[i] + 32;
        } else {
            x = word[i];
        }
        
        hash =( hash * 16777619) ^ x;
    }
    return hash % hashSize;
}
*/
