// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82
#include <stdio.h>
#include <vector>
#include <iostream>

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head)
{
    if( head == NULL )
        return NULL;
    
    Node *current = head;
    while( current != NULL )
    {
        Node *inserted = new Node( current->val );
        inserted->next = current->next;
        current->next = inserted;
        current = inserted->next;
    }

    current = head;
    while( current != NULL )
    {
        if( current->random != NULL )
        {
            current->next->random = current->random->next;
        }
        current = current->next->next;
    }


    current = head;
    Node *new_head = head->next;
    Node *new_tail = new_head;
    Node *temp;

    //      NT
    // C    NH    T
    // a -> a' -> b -> b' -> c -> c' -> d -> d' -> e -> e' 
    
    while( current != NULL )
    {
        temp = NULL;
        if( current->next != NULL )
        {
            temp = current->next->next;
        }
        if( temp != NULL )
        {
            new_tail->next = temp->next;
        }
        current->next = temp;
        new_tail = new_tail->next;
        current = temp;
    }
    
    return new_head;
}


int main( int argc, char **argv)
{
    printf("Leetcode #0138 - Copy List With Random Pointer\n");
    {
    }
    return 0;
}
