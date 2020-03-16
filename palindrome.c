#include <stdio.h>
#include <stdlib.h>
#include "singleLinkedList.h"

bool palindrome(sllnode *list);
bool palindromeRecursive(sllnode *list, int pos, sllnode **next);

int main(void)
{
    sllnode *list = NULL;
    insert(&list, 1);
    insert(&list, 2);
    insert(&list, 3);
    
    insert(&list, 3);
    insert(&list, 2);
    insert(&list, 1);
    
    printf("%d\n", palindromeRecursive(list, 6, &list));
    destroy(list);
}

/*
* Algorithm to check if a linked list is a palindrome
* This procedure is very straightforard:
* 1. Reverse the original linked list
* 2. Scan the two linked lists at the same time
* 3. If there is a divergence at some position then the linked list is not a palindrome. 
* 4. If the scan reaches the end the linked list is a palindrome
* Complexity: O(n)
*/
bool palindrome(sllnode *list)
{
    sllnode *reverseList = NULL;
    sllnode *tmpList = list;
    
    while (tmpList != NULL)
    {
        insert(&reverseList, tmpList->value);
        tmpList = tmpList->next;
    }
    
    tmpList = list;
    sllnode *reverseTmpList = reverseList;
    bool isPalindrome = true;
    
    while(tmpList != NULL)
    {
        if (tmpList->value != reverseTmpList->value)
        {
            isPalindrome = false;
            break;
        }
        tmpList = tmpList->next;
        reverseTmpList = reverseTmpList->next;
    }
    
    destroy(reverseList);
    return isPalindrome;
}

/*
* Check recursively if a linked list represents a palindrome. 
* This procedure is recursive. It goes until the middle of the linked list, adding a palindromeRecursive function
* to the stack for each position. 
* Then after that the stack is unfolded but the double pointer continues scaning the list until the end. 
* This way at the moment of each palindromeRecursive call the node and next variables represent 
* linked list mirrored positions. 
*/
bool palindromeRecursive(sllnode *node, int length, sllnode **next)
{
    if (length == 0 || node == NULL)
    {
        *next = node;
        return true;
    }
    else if (length == 1) 
    {
        *next = node->next;
        return true;
    }
    
    length = length - 2;
    
    bool isPalindrome = palindromeRecursive(node->next, length, next);
    
    if (node->value != (*next)->value)
    {
        isPalindrome = false;
    }
    *next = (*next)->next;
    return isPalindrome;
}
