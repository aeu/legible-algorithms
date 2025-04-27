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

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

 
struct Higher {
    bool operator()(const ListNode *lhs, const ListNode *rhs)
    {
        return lhs->val > rhs->val;
    }
};



ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{
    std::priority_queue<ListNode *, std::vector<ListNode *>, Higher> pqueue;

    if( list1 != nullptr )
        pqueue.push( list1 );
    if( list2 != nullptr )
        pqueue.push( list2 );
    ListNode *newhead = nullptr ;
    ListNode *newtail = nullptr ;
    while( ! pqueue.empty() )
    {
        ListNode *curr = pqueue.top();
        pqueue.pop();
        ListNode *saved = curr->next;
        if( newhead == nullptr )
        {
            newhead = curr;
            newtail = curr;
        }
        else 
        {
            newtail->next = curr;
            newtail = curr;
        }
        if( saved != nullptr )
            pqueue.push(saved);
    }
    return newhead;
    
}

void dumpList(ListNode *head)
{
    bool first = true;
    ListNode *curr = head;
    while( curr != nullptr )
    {
        if( ! first )
            std::cout << "->";
        first = false;
        std::cout << curr->val ;
        curr = curr->next;
    }
    std::cout << std::endl;
}


    
int main(int argc, char **argv)
{
    std::cout << std::endl << "0021-merge-two-sorted-lists" << std::endl << std::endl;
    int test_case = 1;
    {

        ListNode *one = new ListNode(1);
        ListNode *two = new ListNode(2);
        ListNode *four = new ListNode(4);
        
        ListNode *oone = new ListNode(1);
        ListNode *othree = new ListNode(3);
        ListNode *ofour = new ListNode(4);

        one->next = two;
        two->next = four;

        oone->next = othree;
        othree->next = ofour;

        dumpList(one);
        dumpList(oone);
        
        ListNode *merged = mergeTwoLists(one,oone);
        dumpList(merged);
        
        
        int expected = 0;
        int result = 0;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
