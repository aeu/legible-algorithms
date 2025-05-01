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
    Node *transition = nullptr;
    bool did_insert = false;
    bool did_loop = false;
    while(! did_insert )
    {
        // store the transition from high to low for later.
        if( prev->val > curr->val )
            transition = prev;
        
        std::cout << "checking if " << insertVal << " can go between " << prev->val << " and " << curr->val << std::endl;
        if((( prev->val <= insertVal ) && ( curr->val >= insertVal )))
           // || (( prev->val >= insertVal ) && ( curr->val >= insertVal )))
        {
            Node *newnode = new Node(insertVal);
            newnode->next = curr;
            prev->next = newnode;
            did_insert = true;
            std::cout << "\t yes, good insert" << std::endl;
            continue;
        }
        if( did_loop == true )
        {
            if( transition != nullptr )
            {
                // it couldn't insert, the new node is either higher
                // than the highest or lower than the lowest.
                Node *newnode = new Node(insertVal);
                newnode->next = transition->next;
                transition->next = newnode;
                did_insert = true;
                std::cout << "\tinserted at transition" << std::endl;
                continue;
            }
            else
            {
                // Or the list is all one value repeated, stick it anywhere
                Node *newnode = new Node(insertVal);
                newnode->next = curr;
                prev->next = newnode;
                did_insert = true;
                std::cout << "\t inserted anywhere all nodes were the same" << std::endl;
                continue;
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

        insert(thr,5);
        dumpList(thr);
        int expected = 0;
        int result = 0;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
