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

int doWork()
{
    return 1;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode *buildTree(std::vector<std::optional<int>> values )
{
    TreeNode *root = new TreeNode(values[0].value());
    int index = 1;
    std::queue<TreeNode *> bqueue;
    bqueue.push(root);
    while( index < values.size() )
    {
        TreeNode *curr = bqueue.front();
        bqueue.pop();

        if( values[index].has_value() )
        {
            TreeNode *left = new TreeNode( values[index].value());
            curr->left = left;
            bqueue.push(left);
        }
        index++;
        if((index<values.size())&&(values[index].has_value()))
        {
            TreeNode *right = new TreeNode(values[index].value());
            curr->right = right;
            bqueue.push(right);
        }
        index++;
    }
    return root;
}


int bst(TreeNode *root, int low, int high)
{
    if( root == nullptr )
        return 0;

    int rval = 0;
    int lval = 0;

    if( root->val > low )
    {
        lval = bst( root->left, low, high );
    }
    if( root->val < high )
    {
        rval = bst( root->right, low, high ); 
    }

    int retval = 0;
    if(( root->val >= low ) && ( root->val <= high ))
    {
        retval += root->val;
    }
    retval += lval;
    retval += rval;
    return retval;
}

int rangeSumBST(TreeNode* root, int low, int high)
{
    return bst(root,low,high);
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "0938-range-sum-of-bst" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::optional<int>> nums  = {10,5,15,3,7,std::nullopt,18};
        int expected = 32;
        int low = 7;
        int high = 15;
        TreeNode *root = buildTree(nums);
        int result = rangeSumBST(root,low,high);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::optional<int>> nums  = {10,5,15,3,7,13,18,1,std::nullopt,6};
        int expected = 23;
        int low = 6;
        int high = 10;
        TreeNode *root = buildTree(nums);
        int result = rangeSumBST(root,low,high);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
