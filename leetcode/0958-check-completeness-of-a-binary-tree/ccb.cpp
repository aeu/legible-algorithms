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


bool isCompleteTree(TreeNode *root)
{
    if( root == nullptr )
        return false;

    std::queue<TreeNode *> bfs_queue;
    bfs_queue.push(root);
    bool null_seen = false;
    while( ! bfs_queue.empty() )
    {
        TreeNode *current_node = bfs_queue.front();
        bfs_queue.pop();
        if( current_node == nullptr )
        {
            // if we see a null, flag that we've seen a null and continue.
            null_seen = true;
        }
        else
        {
            // we got a node, but we've already seen a null before,
            // that means that somewhere there's a dangling non-null
            // node, so the tree isn't complete
            if( null_seen )
                return false;
            // note that unlike most bfs we don't check for nulls
            // before pushing, because the search actually depends on
            // the nulls
            bfs_queue.push( current_node->left );
            bfs_queue.push( current_node->right );
        }
    }
    return true;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "0958-check-completeness-of-a-binary-tree" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::optional<int>> values = {1,2,3,4,5,6,7,8,9,10,11,12,13,std::nullopt,std::nullopt,15};
        TreeNode *root = buildTree(values);
        bool expected = false;
        bool result = isCompleteTree(root);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::optional<int>> values = {1,2,3,4,5,6};
        TreeNode *root = buildTree(values);
        bool expected = true;
        bool result = isCompleteTree(root);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::optional<int>> values = {1,2,3,4,std::nullopt,7};
        TreeNode *root = buildTree(values);
        bool expected = false;
        bool result = isCompleteTree(root);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        
        std::vector<std::optional<int>> values = {1,2,3,std::nullopt,std::nullopt,7,8};
        TreeNode *root = buildTree(values);
        bool expected = false;
        bool result = isCompleteTree(root);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        
        std::vector<std::optional<int>> values = {1,2,3,4,5,6,7,8,9,10,11,12,13,std::nullopt,std::nullopt,15};
        TreeNode *root = buildTree(values);
        bool expected = false;
        bool result = isCompleteTree(root);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
