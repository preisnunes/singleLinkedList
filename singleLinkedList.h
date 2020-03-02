#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <stdbool.h>

typedef struct sllnode
{
    int value;
    struct sllnode *next;
} sllnode;

// Prototypes

sllnode* create(int value);
bool find(sllnode* head, int value);
bool findRecursively(sllnode* head, int value);
void insert(sllnode** head, int value);
void destroy(sllnode* head);
void deleteNode(sllnode** head, int value);
void deleteNodeByPointer(sllnode *nodeToDelete, sllnode *previousNode);
void printLinkedList(sllnode *linkedList);

#endif // DICTIONARY_H