#include <stdio.h>
#include <stdbool.h>
#include "singleLinkedList.h"
#include <stdlib.h>
#include <ctype.h>

/*
Create a sllnode. Return a pointer to it
*/
sllnode* create(int value)
{
    sllnode* node = malloc(sizeof(sllnode));
    node->value = value;
    node->next = NULL;
    return node;
}

/*
Insert a node into the list. The node is always inserted at the beginning of the list.
The pseudocode for this operation is the following:
1. Create the node
2. Point the node's next property to the first element in the list
3. Change the list's head to point to the created node
*/
void insert(sllnode** head, int value)
{
    sllnode* node = create(value);
    if (*head != NULL)
    {
        node->next = *head;
    }

    *head = node;
}

/*
Find first node that contain value and return it
*/
bool find(sllnode* head, int value)
{
    for (sllnode *tmp = head; tmp != NULL; tmp = tmp->next)
    {
        if (tmp->value == value)
        {
            return true;
        }
    }
    return false;
}

/*
Same as find but done in a recursively way
*/
bool findRecursively(sllnode* head, int value)
{
    if (head->next == NULL)
    {
        return false;
    }
    if (head->value == value)
    {
        return true;
    }
    return findRecursively(head->next, value);
}

/*
Unload the list. Loop on the list and free the memory allocated for each node
*/
void destroy(sllnode* head)
{
    if (head->next != NULL)
    {
        destroy(head->next);
    }
    free(head);
    return;
}

/*
Delete a specific node identified by its value
Peseudo code:
1. Loop on the list
2. Maintain always a reference to the previous node
3. If a node is found, link the previouse node to the current's next node
4. Free the found node
5. If the found node is the first in the list, before free it, it's necessary to
change the list's head to reference the second node in the list
*/
void deleteNode(sllnode** head, int value)
{
    sllnode* previous = *head;
    int i = 0;

    for (sllnode *current = *head; current != NULL; current = current->next, i++)
    {
        if (current->value == value)
        {
            if (i == 0)
            {
                *head = current->next;
            }
            else
            {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
    }
}

void deleteNodeByPointer(sllnode *nodeToDelete, sllnode *previousNode)
{
    previousNode->next = nodeToDelete->next;
    free(nodeToDelete);
}

void printLinkedList(sllnode *linkedList)
{
    for (sllnode *tmp = linkedList; tmp != NULL; tmp = tmp->next)
    {
        printf("|%d - %p| -> ", tmp->value, tmp->next);
    }

    printf("\n");
}

