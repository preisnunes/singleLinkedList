#include <stdio.h>
#include <stdlib.h>
#include "singleLinkedList.h"

void findElementsFromKthToLast(sllnode *linkedList, int k);
sllnode* kthToLastElement(sllnode *head, int k, int *i);
sllnode *findKthToLastElement(sllnode *head, int k);
sllnode *findKthToLastElementIteratively(sllnode *head, int k);

int main(void)
{
    sllnode *listHeader = NULL;
    insert(&listHeader, 9);
    insert(&listHeader, 8);
    insert(&listHeader, 3);
    insert(&listHeader, 7);
    insert(&listHeader, 5);
    insert(&listHeader, 6);
    insert(&listHeader, 2);
    insert(&listHeader, 10);
    
    sllnode *kElem = findKthToLastElement(listHeader, 4);
    printLinkedList(kElem);

    sllnode *kElemIter = findKthToLastElementIteratively(listHeader, 4);
    printLinkedList(kElemIter);

    destroy(listHeader);
}

sllnode *findKthToLastElement(sllnode *head, int k)
{
    int i = 0;
    return kthToLastElement(head, k, &i);
}

/*
* Function findKthToLastElementIteratively
* ----------------------------------------
* Returns pointer for the kth to last element in a single linked list
* For instance for a single linked list with 10 elements, if k = 2, 
* this function returns the pointer for the 8th element. 
* This function does the job recursively. 
* It adds a kthToLastElement funtion to stack until the end of list is reached.
* Then each kthToLastElement call is counted and when it is equal to k the pointer at that position is returned.
*/
sllnode* kthToLastElement(sllnode *head, int k, int* i)
{
    if (head == NULL)
    {
        return NULL;
    }

    sllnode *nd = kthToLastElement(head->next, k, i);
    (*i)++;
    
    if (*i == k)
    {
        return head;
    }
    return nd;
}

/*
* Function findKthToLastElementIteratively
* ----------------------------------------
* Find the kth to last element pointer in a single linked list
* For instance for a single linked list with 10 nodes, if k = 2, 
* this function returns the pointer for the 8th node. 
* This function does the job iteratively. 
* It uses two pointers that run through the list at the same pace: one starts k position ahead the start and one at the begin of the list.
* When the pointer at the front reaches the end of the list, the latter one is at the desired position. 
*
*/
sllnode *findKthToLastElementIteratively(sllnode *head, int k)
{
    sllnode *nodeAhead = head;
    
    for (int i = 0; i < k; i++)
    {
        nodeAhead = nodeAhead->next;
    }
    
    sllnode *kthNode = head;
    
    for (sllnode *node = nodeAhead; node != NULL; node = node->next)
    {
        kthNode = kthNode->next;
    }

    return kthNode;
}





