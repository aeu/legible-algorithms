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

Node* insert(Node* head, int insertVal)
{
    Node *savedhead = head;
    if( head == nullptr )
    {
        Node *newhead = new Node(insertVal);
        newhead->next = newhead;
        return newhead;
    }

    if( head->next == nullptr )
    {
        Node *newnode = new Node(insertVal);
        head->next = newnode;
        newnode->next = head;
        return head;
    }

    Node *prev = head;
    Node *curr = head->next;
    bool did_insert = false;
    bool did_loop = false;
    while(( curr != nullptr ) && ( ! did_insert ))
    {
        // std::cout << "checking if " << insertVal << " can go between " << prev->val << " and " << curr->val << std::endl;
        if(
           (( prev->val <= insertVal ) && ( curr->val >= insertVal ))
           || (( prev->val >= insertVal ) && ( curr->val <= insertVal ))
           )
        {
            // std::cout << "\tcan" << std::endl;
            Node *newnode = new Node(insertVal);
            newnode->next = curr;
            prev->next = newnode;
            did_insert = true;
            // std::cout << "good insert" << std::endl;
            continue;
        }
                
        if( did_loop == true )
        {
            if(( prev->val <= insertVal ) || ( curr->val >= insertVal ))
            {
                // we looped all the way around without finding a
                // place to slot it in (for example adding a 3, to a
                // list that has only 1 & 2 in it will not hit the
                // previous if statement, so just insert it whenver we
                // can.
                Node *newnode = new Node(insertVal);
                newnode->next = curr;
                prev->next = newnode;
                did_insert = true;
                // std::cout << "fallback insert" << std::endl;
            }
            
        }
        curr = curr->next;
        prev = prev->next;
        if( curr == savedhead )
            did_loop = true;
    }
    return savedhead;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "0708-insert-into-a-sorted-circular-linked-list" << std::endl << std::endl;
    int test_case = 1;
    {
        Node *one = new Node(1);
        Node *thr = new Node(3);
        Node *fou = new Node(4);

        one->next = thr;
        thr->next = fou;
        fou->next = one;

        insert(thr,2);
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

        insert(thr,5);
    }
    return 0;
}
