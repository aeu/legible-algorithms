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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int dfs(TreeNode *root, int &max_diameter)
{
    if( root == nullptr )
        return 0;
    int llength = dfs(root->left, max_diameter );
    int rlength = dfs(root->right, max_diameter );
    max_diameter = std::max( max_diameter, (llength + rlength ));
    return 1 + std::max( llength, rlength );
}

int diameterOfBinaryTree(TreeNode* root)
{
    int max_diameter = INT_MIN;
    dfs(root, max_diameter);
    return max_diameter;
}

TreeNode *buildTree(std::vector<int> &nums)
{
    TreeNode *root = new TreeNode(nums[0]);
    std::queue<TreeNode *> bqueue;
    bqueue.push(root);
    int index=1;
    while( index < nums.size() )
    {
        TreeNode *curr = bqueue.front();
        bqueue.pop();
        TreeNode *left = new TreeNode(nums[index] );
        curr->left = left;
        bqueue.push( left );
        index++;
        if( index < nums.size() )
        {
            TreeNode *right = new TreeNode(nums[index]);
            curr->right = right;
            bqueue.push(right);
        }
        index++;
    }
    return root;
}
    
int main(int argc, char **argv)
{
    std::cout << std::endl << "0543-diameter-of-binary-tree" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {1,2,3,4,5};
        int expected = 3;
        TreeNode *root = buildTree(nums);
        int result = diameterOfBinaryTree(root);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums  = {1,2};
        int expected = 1;
        TreeNode *root = buildTree(nums);
        int result = diameterOfBinaryTree(root);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
