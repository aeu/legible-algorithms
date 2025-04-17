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

void dumpList(ListNode *list)
{
    ListNode *curr = list; 
    while(curr != nullptr )
    {
        std::cout << curr->val << "->";
        curr = curr->next;
    }
    std::cout << std::endl;
}


struct NodeSorter {
    bool operator() (const ListNode *lhs, const ListNode *rhs)
    {
        return lhs->val > rhs->val;
    }
};
        

ListNode *mergeKLists(std::vector<ListNode *> &lists )
{
    std::priority_queue<ListNode *, std::vector<ListNode *>, NodeSorter> squeue;
    for(auto curr : lists )
    {
        ListNode *cand = curr;
        squeue.push( cand );
    }

    ListNode *newhead = nullptr;
    ListNode *last_added = nullptr;
    while ( ! squeue.empty() )
    {
        ListNode *curr = squeue.top();
        squeue.pop();
        if( newhead == nullptr )
        {
            newhead = curr;
            last_added = newhead;
        }
        else
        {
            last_added->next = curr;
            last_added = curr;
        }
        if( curr->next != nullptr )
        {
            squeue.push(curr->next);
        }
    }
    return newhead;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "0023-merge-k-sorted-lists" << std::endl << std::endl;
    int test_case = 1;
    {
        ListNode *five = new ListNode(5);
        ListNode *four = new ListNode(4,five);
        ListNode *one  = new ListNode(1,four);
        ListNode *l1_head = one;

        four = new ListNode(4);
        ListNode *three = new ListNode(3,four);
        one = new ListNode(1,three);
        ListNode *l2_head = one;

        ListNode *six = new ListNode(6);
        ListNode *two = new ListNode(2,six);
        ListNode *l3_head = two;

        std::vector<ListNode *> lists;
        lists.push_back(l1_head);
        lists.push_back(l2_head);
        lists.push_back(l3_head);

        dumpList( l1_head );
        dumpList( l2_head );
        dumpList( l3_head );
        
        ListNode *merged = mergeKLists(lists);
        dumpList( merged );
        
    }
    return 0;
}
