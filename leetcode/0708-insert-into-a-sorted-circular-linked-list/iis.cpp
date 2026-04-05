// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <iostream>
#include <optional>
#include <vector>
#include <queue>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <limits.h>

class Node {
public:
    int val;
    Node* next;
    
    Node() {}
    
    Node(int _val)
    {
        val = _val;
        next = NULL;
    }
    
    Node(int _val, Node* _next)
    {
        val = _val;
        next = _next;
    }
};


void dumpList(Node *list)
{
    Node *saved = list;
    Node *curr = list; 
    while(curr != nullptr )
    {
        std::cout << curr->val;
        if( curr->next != nullptr )
            std::cout << " -> ";
        curr = curr->next;
        if( curr == saved )
            break;
    }
    std::cout << std::endl;
}


Node* insert(Node* head, int insertVal)
{
    Node *provided = head;
    Node *inserted = new Node(insertVal);
    if( head == nullptr )
    {
        inserted->next = inserted;
        return inserted;
    }
    if( head->next == head )
    {
        head->next = inserted;
        inserted->next = head;
        return provided;
    }
    Node *transition = nullptr;
    Node *current = head;
    for(;;)
    {
        // handle perfact case where inserted value is between
        // the current and next
        if(( current->val <= insertVal ) && ( current->next->val >= insertVal ))
        {
            inserted->next = current->next;
            current->next  = inserted;
            return provided;
        }
        // we hit the transition.  we can tell if the next value is lower, or if the next
        // value is the same one that was passed in (if the list only has one value in it)
        if(( current->next->val < current->val )
           || ( current->next == provided ))
        {
            // inserted is going to ebe either bigger than the last node
            // or less than the new lowest
            if(( insertVal >= current->val ) || ( insertVal <= current->next->val ))
            {
                // either way, put it in after the current and before the first
                inserted->next = current->next;
                current->next  = inserted;
                return provided;
            }
        }
        current = current->next;
    }
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "0708-insert-into-a-sorted-circular-linked-list" << std::endl << std::endl;
    int test_case = 1;
    {
        Node *one = new Node(1);
        Node *thr = new Node(3);
        Node *fiv = new Node(5);

        thr->next = fiv;
        fiv->next = one;
        one->next = thr;

        dumpList(thr);
        insert(thr,0);
        dumpList(thr);
        int expected = 0;
        int result = 0;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        Node *thr = new Node(3);
        Node *fou = new Node(4);
        Node *one = new Node(1);

        one->next = thr;
        thr->next = fou;
        fou->next = one;

        dumpList(thr);
        insert(thr,2);
        dumpList(thr);
        int expected = 0;
        int result = 0;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        Node *one = new Node(1);
        Node *two = new Node(2);
        Node *thr = new Node(3);
        Node *fou = new Node(4);

        one->next = two;
        two->next = thr;
        thr->next = fou;
        fou->next = one;

        dumpList(thr);
        insert(thr,5);
        dumpList(thr);
        int expected = 0;
        int result = 0;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        Node *a3 = new Node(3);
        Node *b3 = new Node(3);
        Node *c3 = new Node(3);

        a3->next = b3;
        b3->next = c3;
        c3->next = a3;

        dumpList(a3);
        insert(a3,0);
        dumpList(a3);
        int expected = 0;
        int result = 0;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
