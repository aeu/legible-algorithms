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


// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82
ListNode* reverseList(ListNode* head)
{
    if(( head == nullptr ) || ( head->next == nullptr ))
        return head;
    
    ListNode *prev = nullptr;
    ListNode *curr = head;

    while( curr != nullptr )
    {
        ListNode *ntemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = ntemp;
    }
    return prev;
}

void monoLess(std::vector<int> nums)
{
    std::vector<int> lessers( nums.size(), -1 );
    std::stack<int>  mstsack;

    for(int index =0;index<nums.size();index++)
    {
        while(( ! mstack.empty() ) && ( nums[ mstack.top() ] > nums[index] ))
        {
            mstack.pop();
        }
        if( ! mstack.empty() )
            lessers[index] = mstack.top() ;
        mstack.push(index);
    }
}


int doWork()
{
    return 1;
}

void dumpValues(std::vector<int> values)
{
    bool first = false;
    
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {1,2,3};
        int expected = 0;
        int result = doWork();
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
