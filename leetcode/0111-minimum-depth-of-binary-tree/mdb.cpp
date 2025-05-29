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


int dfs(TreeNode *root,
        int depth,
        int &min_depth)
{
    if( root == nullptr )
        return 0;

    dfs(root->left,depth+1,min_depth);
    if(( root->left == nullptr ) && ( root->right == nullptr ))
    {
        min_depth = std::min( depth, min_depth );
    }
    dfs(root->right,depth+1,min_depth);
    return min_depth;
}


int minDepth(TreeNode* root)
{
    int min_depth = INT_MAX;
    dfs(root,1,min_depth);
    if( min_depth == INT_MAX )
        return 0;
    return min_depth;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0111-minimum-depth-of-binary-tree" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::optional<int>> nums  = {3,9,20,std::nullopt,std::nullopt,15,7};
        int expected = 2;
        TreeNode *root = buildTree(nums);
        int result = minDepth(root);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::optional<int>> nums  = {2,std::nullopt,3,std::nullopt,4,std::nullopt,5,std::nullopt,6};
        int expected = 5;
        TreeNode *root = buildTree(nums);
        int result = minDepth(root);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
