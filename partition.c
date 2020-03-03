#include <stdio.h>
#include <stdlib.h>
#include "singleLinkedList.h"

sllnode* partition(sllnode *head, int pivot);

int main(void)
{
    sllnode *listHeader = NULL;
    insert(&listHeader, 1);
    insert(&listHeader, 2);
    insert(&listHeader, 10);
    insert(&listHeader, 5);
    insert(&listHeader, 8);
    insert(&listHeader, 5);
    insert(&listHeader, 3);
    
    printLinkedList(listHeader);
    sllnode *newHeader = partition(listHeader, 5);
    
    printLinkedList(newHeader);
    destroy(newHeader);
}

/**
* This algorithm looks for doing a partition around a pivot. The only requirement is that all values
higher than pivot should come after all values less than the pivot, without any specific order.
For achieving this I loop through the list and every time that I find a value lower that the pivot,
I delete it and insert it again at the beginning of the list.
**/
sllnode* partition(sllnode *head, int pivot)
{
    if (head == NULL)
    {
        return NULL;
    }

    sllnode *prev = head;
    sllnode *node = head->next;
    bool pivotFound = false;

    while (prev != NULL && node != NULL)
    {
        if (!pivotFound && node->value == pivot)
        {
            pivotFound = true;
        }
        
        if (pivotFound && node->value < pivot)
        {
            prev->next = node->next;
            insert(&head, node->value);
            free(node);
            node = prev->next;
            continue;
        }
        
        prev = prev->next;
        node = prev->next;
    }

    return head;
}
