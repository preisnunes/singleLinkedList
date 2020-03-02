#include <stdio.h>
#include <stdlib.h>
#include "singleLinkedList.h"

void deleteMiddleNode(sllnode *head, int value);

int main(void)
{
    sllnode *header = NULL;
    insert(&header, 9);
    insert(&header, 8);
    insert(&header, 7);
    insert(&header, 6);
    insert(&header, 5);
    insert(&header, 4);
    insert(&header, 3);
    insert(&header, 2);
    insert(&header, 1);
    
    deleteMiddleNode(header, 3);
    printLinkedList(header);

    destroy(header);
}

void deleteMiddleNode(sllnode *head, int value)
{
    sllnode *aheadNode = head->next;

    for (sllnode *node = head; node != NULL; node = node->next)
    {
        if (aheadNode->next == NULL)
        {
            break;
        }
        if (aheadNode->value == value)
        {
            node->next = aheadNode->next;
            free(aheadNode);
            break;
        }
        aheadNode = aheadNode->next;
    }
}