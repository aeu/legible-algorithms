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

//int max_zags = 0;

struct TreeNode {
    int val;
    TreeNode  *left;
    TreeNode  *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void dumpValues(const std::vector<std::optional<int>> &values )
{
    bool first_time = true;
    std::cout << "[";
    for( auto current : values )
    {
        if( ! first_time )
            std::cout << ", ";
        if( current.has_value() )
            std::cout << current.value();
        else
            std::cout << "null";
        first_time = false;
    }
    std::cout << "]" << std::endl;
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


// walk down the tree, passing down the direction we came in from.  If
// we go down the opposite direction with the next step, increment the
// length of the zag.  otherwise reset it to 0.
int dfs(TreeNode * root,
        int direction,
        int zag_count,
        int &max_zags)
{
    if( root == nullptr )
        return 0;
    int next_zag_count;

    max_zags = std::max(max_zags, zag_count);
    next_zag_count = zag_count;
    // we came from either the right or tree root, and are about to go
    // left, increment zag count
    if( ( direction == 0 ) || ( direction == 1 ) )
        next_zag_count++;
    else
        next_zag_count = 1;
    dfs(root->left,-1,next_zag_count, max_zags);

    next_zag_count = zag_count;
    // we came from either the left or tree root, and are about to go
    // right, increment zag count
    if( ( direction == 0 ) || ( direction == -1 ) )
        next_zag_count++;
    else
        next_zag_count = 1;
    dfs(root->right,1,next_zag_count, max_zags);

    return max_zags;
}

int longestZigZag(TreeNode * root )
{
    int max_zags  = 0;
    int direction = 0;
    int zag_count = 0;
    dfs(root,direction,zag_count,max_zags);
    return max_zags;
}

int main(int argc, char **argv)
{
    std::cout << "Leetcode #1372 - Longest ZigZag Path in a Binary Tree" << std::endl;
    int test_case = 1;
    {
        std::vector<std::optional<int>> values =
            { 1, std::nullopt,1,1,1,std::nullopt,std::nullopt,1,1,std::nullopt,1,std::nullopt,std::nullopt,std::nullopt,1 };

        TreeNode * root = buildTree(values);
        int result = longestZigZag(root);
        int expected = 3;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::optional<int>> values =
            { 1,1,1,std::nullopt,1,std::nullopt,std::nullopt,1,1,std::nullopt,1};
        TreeNode * root = buildTree(values);
        int result = longestZigZag(root);
        int expected = 4;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::optional<int>> values = { 1 };
        TreeNode * root = buildTree(values);
        int result = longestZigZag(root);
        int expected = 0;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return -1;
}
