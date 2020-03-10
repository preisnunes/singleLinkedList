#include <stdio.h>
#include <stdlib.h>
#include "singleLinkedList.h"

sllnode* sum(sllnode *a, sllnode *b);
sllnode* sumForward(sllnode *a, sllnode *b);
sllnode* sumRecursive(sllnode *a, sllnode *b, sllnode *c, int* carry);

int main(void)
{
    sllnode *a = NULL;
    insert(&a, 1);
    insert(&a, 1);
    insert(&a, 6);
    insert(&a, 1);
    insert(&a, 7);
    
    sllnode *b = NULL;
    insert(&b, 5);
    insert(&b, 9);
    insert(&b, 5);
    
    sllnode *c = sum(a, b);
    printLinkedList(a);
    printLinkedList(b);
    printLinkedList(c);

    destroy(a);
    destroy(b);
    destroy(c);

    printf("\n");
    
    sllnode *aForward = NULL;
    
    insert(&aForward, 7);
    insert(&aForward, 1);
    insert(&aForward, 6);
    insert(&aForward, 1);
    insert(&aForward, 1);
    
    sllnode *bForward = NULL;
    insert(&bForward, 5);
    insert(&bForward, 9);
    insert(&bForward, 5);

    sllnode *cForward = sumForward(aForward, bForward);
    printLinkedList(aForward);
    printLinkedList(bForward);
    printLinkedList(cForward);
    
    destroy(aForward);
    destroy(bForward);
    destroy(cForward);
}

sllnode* sum(sllnode *a, sllnode *b)
{
    sllnode *c = malloc(sizeof(sllnode));
    sllnode *temp;
    int carry = 0;

    //initialize linked list with the sum result
    c->value = 0;
    c->next = NULL;
    temp = c;
    
    //loop while the two linked lists (numbers) don't end
    while (a != NULL || b != NULL)
    {
        int aVal = 0;
        if (a != NULL){
            aVal = a->value;
            a = a->next;
        }
        
        int bVal = 0;
        if (b != NULL){
            bVal = b->value;
            b = b->next;
        }
        
        int sum = aVal + bVal;
        int digit = (sum % 10) + carry;
        carry = sum/10;
        
        sllnode * digitNode = malloc(sizeof(sllnode));
        digitNode->next = NULL;
        digitNode->value = digit;
        
        temp->next = digitNode; 
        temp = temp->next;
    }
    
    deleteNode(&c, 0);
    return c;
}

sllnode* sumForward(sllnode *a, sllnode *b)
{
    sllnode *c = malloc(sizeof(sllnode));
    int carry = 0;

    sllnode *tmpA = a;
    sllnode *tmpB = b;

    while(tmpA != NULL || tmpB != NULL)
    {
        if (tmpA == NULL)
        {
            insert(&a, 0);
            tmpB = tmpB->next;
            continue;
        }
        if (tmpB == NULL)
        {
            insert(&b, 0);
            tmpA = tmpA->next;
            continue;
        }

        tmpA = tmpA->next;
        tmpB = tmpB->next;
    }

    return sumRecursive(a, b, c, &carry);
}

sllnode* sumRecursive(sllnode *a, sllnode *b, sllnode *headOfSum, int* carry)
{
    if(a == NULL && b == NULL)
    {
        return NULL;
    }

    sllnode* head = sumRecursive(a->next, b->next, headOfSum, carry);
    
    int sum = a->value + b->value;
    int digit = (sum % 10) + *carry;
    *carry = sum/10;
    
    sllnode *digitNode = malloc(sizeof(sllnode));
    digitNode->value = digit;
    digitNode->next = head;
    
    return digitNode;
}
