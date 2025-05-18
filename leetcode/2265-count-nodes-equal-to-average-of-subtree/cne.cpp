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
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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

std::pair<int,int> dfs(TreeNode *root,
                       int &match_count)
{
    if( root == nullptr )
        return { 0, 0 };
    
    auto [lsum, lcount ] = dfs(root->left,match_count);
    auto [rsum, rcount ] = dfs(root->right,match_count);

    int total_sum = lsum + rsum + root->val;
    int total_count = lcount + rcount + 1;
    
    if( root->val == total_sum / total_count)
        match_count++;

    return { total_sum, total_count };
}

int averageOfSubtree(TreeNode* root)
{
    int match_count = 0;
    dfs(root,match_count);
    return match_count;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "2265-count-nodes-equal-to-average-of-subtree" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::optional<int>> values = {4,8,5,0,1,std::nullopt,6};
        TreeNode *root = buildTree(values);
        int expected   = 5;
        int result     = averageOfSubtree(root);

        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::optional<int>> values = {1};
        TreeNode *root = buildTree(values);
        int expected   = 1;
        int result     = averageOfSubtree(root);

        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
