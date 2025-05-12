// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <iostream>
#include <iomanip>
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
    ListNode *original = list;
    while(curr != nullptr )
    {
        std::cout << curr->val;
        if( curr->next != nullptr )
            std::cout << " -> ";
        curr = curr->next;
        if( curr == original )
        {
            std::cout << "endless loop, breaking" << std::endl;
            break;
        }
    }
    std::cout << std::endl;
}

bool ListNodeCompare(ListNode *lhs, ListNode *rhs)
{
    return lhs->val < rhs->val;
}


ListNode* sortList(ListNode* head)
{
    if(( head == nullptr ) || ( head->next == nullptr ))
        return head;

    std::vector<ListNode *> nvl;
    ListNode *curr = head;

    while( curr != nullptr )
    {
        nvl.push_back(curr);
        curr = curr->next;
    }
    
    std::sort(nvl.begin(),nvl.end(),ListNodeCompare);
    
    for(int index=1;index<nvl.size();index++)
    {
        ListNode *prev = nvl[index-1];
        ListNode *curr = nvl[index];
        prev->next = curr;
        curr->next = nullptr;
    }
    return nvl[0];
}



int main(int argc, char **argv)
{
    std::cout << std::endl << "0148-sort-list" << std::endl << std::endl;
    int test_case = 1;
    {
        ListNode *fou = new ListNode(4);
        ListNode *two = new ListNode(2);
        ListNode *one = new ListNode(1);
        ListNode *thr = new ListNode(3);

        fou->next = two;
        two->next = one;
        one->next = thr;

        dumpList(fou);
        ListNode *sorted = sortList(fou);
        dumpList(sorted);
        std::cout << "Test case : " << test_case++ << std::endl;
    }
    {
        ListNode *mio = new ListNode(-1);
        ListNode *fiv = new ListNode(5);
        ListNode *thr = new ListNode(3);
        ListNode *fou = new ListNode(4);
        ListNode *zer = new ListNode(0);

        mio->next = fiv;
        fiv->next = thr;
        thr->next = fou;
        fou->next = zer;
        
        dumpList(mio);
        ListNode *sorted = sortList(mio);
        dumpList(sorted);
        std::cout << "Test case : " << test_case++ << std::endl;
    }
    return 0;
}
