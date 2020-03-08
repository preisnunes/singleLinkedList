#include <stdio.h>
#include <stdlib.h>
#include "singleLinkedList.h"

sllnode* sum(sllnode *a, sllnode *b);

int main(void)
{
    
    sllnode *a = NULL;
    
    insert(&a, 6);
    insert(&a, 1);
    insert(&a, 7);
    
    sllnode *b = NULL;
    insert(&b, 2);
    insert(&b, 9);
    insert(&b, 5);
    
    printLinkedList(a);
    printLinkedList(b);
    
    sllnode *c = sum(a, b);
    printLinkedList(c);
    
    destroy(a);
    destroy(b);
    destroy(c);
}

sllnode* sum(sllnode *a, sllnode *b)
{
    
    sllnode *c = malloc(sizeof(sllnode));
    sllnode *temp;
    int carry = 0;

    c->value = 0;
    c->next = NULL;
    temp = c;
    
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
        int algarism = (sum % 10) + carry;
        carry = sum/10;
        
        sllnode * newNode = malloc(sizeof(sllnode));
        newNode->next = NULL;
        newNode->value = algarism;
        
        temp->next = newNode; 
        temp = temp->next;
    
    }

    return c;
}
