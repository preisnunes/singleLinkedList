#include <stdio.h>
#include <stdlib.h>
#include "singleLinkedList.h"

void printLinkedList(sllnode *linkedList);
void removeDuplicatesWithBuffer(sllnode *linkedList, int maximumValue);
void removeDuplicates(sllnode *linkedList);

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
    insert(&listHeader, 6);
    insert(&listHeader, 6);
    
    printLinkedList(listHeader);
    removeDuplicates(listHeader);
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
            deleteNodeByPointer(node, sllnodePre);
            node = sllnodePre;
            continue;
        }
        
        duplicates[node->value] = 1;
        sllnodePre = node;
    }
}



void removeDuplicates(sllnode *linkedList)
{
    for (sllnode *node = linkedList; node != NULL; node = node->next)
    {
        int value = node->value;
        sllnode *tempNode = node;
        for (sllnode *nodeAhead = node->next; nodeAhead != NULL; nodeAhead = nodeAhead->next)
        {
            if (nodeAhead->value == value)
            {
                deleteNodeByPointer(nodeAhead, tempNode);
                nodeAhead = tempNode;
                continue;
            }
            tempNode = nodeAhead;
        }
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
