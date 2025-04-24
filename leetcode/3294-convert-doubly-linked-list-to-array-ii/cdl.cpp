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
    Node* prev;
    Node* next;
    Node() : val(0), next(nullptr), prev(nullptr) {}
    Node(int x) : val(x), next(nullptr), prev(nullptr) {}
    Node(int x, Node *prev, Node *next) : val(x), next(next), prev(prev) {}
};

std::vector<int> toArray(Node *node)
{
    std::vector<int> retval;
    std::deque<Node *> deq;

    Node *curr = node;
    while( curr != nullptr )
    {
        deq.push_back(curr);
        curr = curr->next;
    }

    curr = node->prev;
    while( curr != nullptr )
    {
        deq.push_front(curr);
        curr = curr->prev;
    }
    
    for(const auto &curr : deq )
    {
        retval.push_back( curr->val );
    }
    return retval;
}        

int main(int argc, char **argv)
{
    std::cout << std::endl << "3294-convert-doubly-linked-list-to-array-ii" << std::endl << std::endl;
    int test_case = 1;
    {
        Node *one   = new Node(1);
        Node *two   = new Node(2);
        Node *three = new Node(3);
        Node *four  = new Node(4);
        Node *five  = new Node(5);

        one->next   = two;
        two->next   = three;
        three->next = four;
        four->next  = five;

        two->prev   = one;
        three->prev = two;
        four->prev  = three;
        five->prev  = four;
        
        std::vector<int> expected  = {1,2,3,4,5};
        std::vector<int> result = toArray(five);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
