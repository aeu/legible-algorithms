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


struct TreeNode {
    int val;
    TreeNode  *left;
    TreeNode  *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void dumpNodeList(std::vector<TreeNode *> values)
{
    bool first = true;
    for(const auto &curr : values )
    {
        if( ! first )
            std::cout << "->" ;
        first = false;
        std::cout << curr->val;
    }
    std::cout << std::endl;
}


TreeNode *buildTree(std::vector<std::optional<int>> tree_values)
{
    TreeNode *root = new TreeNode(tree_values[0].value());
    std::queue<TreeNode *>bqueue;
    int index=1;
    bqueue.push(root);
    while( index < tree_values.size() )
    {
        TreeNode *curr = bqueue.front();
        bqueue.pop();
        if( tree_values[index].has_value() )
        {
            TreeNode *left = new TreeNode( tree_values[index].value() );
            curr->left = left;
            bqueue.push(left);
        }
        index++;
        if( ( index < tree_values.size() ) && ( tree_values[index].has_value() ))
        {
            TreeNode *right = new TreeNode( tree_values[index].value() );
            curr->right = right;
            bqueue.push(right);
        }
        index++;
    }
    return root;
}


void dumpValues(std::vector<int> values)
{
    bool first = true;
    for(const auto &curr : values )
    {
        if( ! first )
            std::cout << ", ";
        first = false;
        std::cout << std::setw(3) << curr ;
    }
    std::cout << std::endl;
}



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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


std::vector<int> nextLesserIndices(std::vector<int> nums)
{
    std::vector<int> lessers( nums.size(), -1);
    std::stack<int> mstack;
    for(int index=nums.size()-1;index>=0;index--)
    {
        // if the number pointed to by the index at the top of the
        // stack is greater than the number we're currently testing,
        // pop it off the stack

        while( ( !mstack.empty()) && ( nums[mstack.top()] > nums[index] ))
        {
            mstack.pop();
        }
        // whatever the stack has on the top is less than what we were
        // testing against.
        if( ! mstack.empty() )
            lessers[index] = mstack.top();
        
        mstack.push(index);
    }
    return lessers;
}


std::vector<int> previousLesserIndices(std::vector<int> nums)
{
    std::vector<int> lessers( nums.size(), -1 );
    std::stack<int>  mstack;

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
    return lessers;
}

std::vector<int> previousGreaterIndices(std::vector<int> nums)
{
    std::vector<int> greaters( nums.size(), -1 );
    std::stack<int>  mstack;

    for(int index =0;index<nums.size();index++)
    {
        while(( ! mstack.empty() ) && ( nums[ mstack.top() ] < nums[index] ))
        {
            mstack.pop();
        }
        if( ! mstack.empty() )
            greaters[index] = mstack.top() ;
        mstack.push(index);
    }
    return greaters;
}


std::vector<int> nextGreaterIndices(std::vector<int> nums)
{
    std::stack<int> mstack;
    std::vector<int> greaters(nums.size(),-1);
    for(int index=nums.size()-1;index>=0;index--)
    {
        while(( ! mstack.empty() ) && ( nums[mstack.top()] < nums[index] ))
        {
            mstack.pop();
        }
        if( ! mstack.empty() )
            greaters[index] = mstack.top();
        mstack.push(index);
    }
    return greaters;        
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "Alfonso's Programming Cheatsheet" << std::endl << std::endl;
    
    int test_case = 1;
    {
        std::cout << std::endl << "Recipe: " << test_case++ << " - Reverse Linked List" << std::endl;
        ListNode *one = new ListNode(1);
        ListNode *two = new ListNode(2);
        ListNode *thr = new ListNode(3);
        ListNode *fou = new ListNode(4);
        ListNode *fiv = new ListNode(5);

        one->next = two;
        two->next = thr;
        thr->next = fou;
        fou->next = fiv;

        dumpList(one);
        ListNode *reversed = reverseList(one);
        dumpList(reversed);
    }
    {
        std::vector<int> nums  = {5,7,8,2,4,6,11,2,3};
        std::vector<int> result   = previousLesserIndices(nums);
        std::cout << std::endl << "Recipe: " << test_case++ << " - Monotonic stack - closest previous lesser indices" << std::endl;
        dumpValues(nums);
        dumpValues(result);
    }
    {
        std::vector<int> nums  = {5,7,8,2,4,6,11,2,3};
        std::vector<int> result   = nextLesserIndices(nums);
        std::cout << std::endl << "Recipe: " << test_case++ << " - Monotonic stack - closest subsequent lesser indices" << std::endl;
        dumpValues(nums);
        dumpValues(result);
    }
    {
        std::vector<int> nums  = {5,7,8,2,4,6,11,2,3};
        std::vector<int> result   = previousGreaterIndices(nums);
        std::cout << std::endl << "Recipe: " << test_case++ << " - Monotonic stack - closest previous greater indices" << std::endl;
        dumpValues(nums);
        dumpValues(result);
    }
    {
        std::vector<int> nums  = {5,7,8,2,4,6,11,2,3};
        std::vector<int> result   = nextGreaterIndices(nums);
        std::cout << std::endl << "Recipe: " << test_case++ << " - Monotonic stack - closest next greater indices" << std::endl;
        dumpValues(nums);
        dumpValues(result);
    }
    return 0;
}
