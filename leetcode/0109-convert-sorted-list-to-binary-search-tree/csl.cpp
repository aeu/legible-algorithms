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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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

TreeNode *buildTree(ListNode *head)
{
    if( head == nullptr )
        return nullptr;
    TreeNode *root = nullptr;
    if( head->next ==  nullptr )
    {
        root = new TreeNode(head->val);
        return root;
    }
    ListNode *fast = head;
    ListNode *slow = head;
    ListNode *before_fast = head;
    ListNode *before_slow = head;
    int flipper = 1;
    while( fast != nullptr )
    {
        if(( flipper % 2 ) == 0 )
        {
            before_slow = slow;
            slow = slow->next;
        }
        flipper++;
        before_fast = fast;
        fast = fast->next;
    }
    before_slow->next = nullptr;
    root = new TreeNode(slow->val);
    root->left = buildTree(head);
    root->right = buildTree(slow->next);
    return root;
}

TreeNode* sortedListToBST(ListNode* head) 
{
    TreeNode *root = buildTree(head);
    return root;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "0109-convert-sorted-list-to-binary-search-tree" << std::endl << std::endl;
    int test_case = 1;
    {
        ListNode *mten = new ListNode(-10);
        ListNode *mthr = new ListNode(-3);
        ListNode *zer  = new ListNode(0);
        ListNode *fiv  = new ListNode(5);
        ListNode *nin  = new ListNode(9);

        mten->next = mthr;
        mthr->next = zer;
        zer->next  = fiv;
        fiv->next  = nin;
        sortedListToBST( mten );
        int expected = 0;
        int result = 0;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
