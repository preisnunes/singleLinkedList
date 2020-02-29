#include <stdio.h>
#include <stdlib.h>
#include "singleLinkedList.h"

void printLinkedList(sllnode *linkedList);
void removeDuplicatesWithBuffer(sllnode *linkedList, int maximumValue);

int main(void)
{
    sllnode *listHeader = NULL;
    insert(&listHeader, 1);
    insert(&listHeader, 5);
    insert(&listHeader, 2);
    insert(&listHeader, 2);
    insert(&listHeader, 4);
    insert(&listHeader, 3);
    insert(&listHeader, 5);
    insert(&listHeader, 5);
    insert(&listHeader, 4);
    printLinkedList(listHeader);
    removeDuplicatesWithBuffer(listHeader, 5);
    printLinkedList(listHeader);
}

void removeDuplicatesWithBuffer(sllnode *linkedList, int maximumValue)
{
    int *duplicates = malloc(maximumValue * sizeof(int));
    sllnode *sllnodePre = NULL;
    
    for (sllnode *node = linkedList; node != NULL; node = node->next)
    {
        if (duplicates[node->value])
        {
            sllnodePre->next = node->next;
            free(node);
            node = sllnodePre;
            continue;
        }
        
        duplicates[node->value] = 1;
        sllnodePre = node;
    }
}

void printLinkedList(sllnode *linkedList)
{
    for (sllnode *tmp = linkedList; tmp != NULL; tmp = tmp->next)
    {
        printf("|%d - %p| -> ", tmp->value, tmp->next);
    }

    printf("\n");
}
