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


void dumpValues(const std::vector<int> &values )
{
    bool first_time = true;
    std::cout << "[";
    for( auto current : values )
    {
        if( ! first_time )
            std::cout << ", ";
        std::cout << current;
        first_time = false;
    }
    std::cout << "]" << std::endl;
}

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x ) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


struct bfs_info {
    int level;
    TreeNode *node;
};

std::vector<std::vector<int>> levelOrder(TreeNode *root)
{
    std::vector<std::vector<int>> levels;
    if( root == nullptr )
        return levels;
    std::queue<bfs_info> bfs_queue;
    bfs_queue.push( { 0, root } );
    int current_level = 0;
    std::vector<int> values;
    while( ! bfs_queue.empty() )
    {
        bfs_info current = bfs_queue.front();
        bfs_queue.pop();

        if( current.level == current_level )
        {
            //            std::cout << "current level : " << current_level << " queue level " << current.level << std::endl;
            values.push_back( current.node->val );
            //            dumpValues( values );
        }
        else
        {
            //            dumpValues( values );
            //            std::cout << "level changed, add the current values vector (above) to levels" << std::endl;
            levels.push_back( values );

            //            std::cout << "now add the guy that triggered the change" << std::endl;
            values.clear();
            values.push_back( current.node->val );
            //            dumpValues( values );
            current_level = current.level;
        }
        if( current.node->left != nullptr )
        {
            bfs_queue.push( { current.level + 1 , current.node->left } );
        }
        if( current.node->right != nullptr )
        {
            bfs_queue.push( { current.level + 1 , current.node->right } );
        }
    }
    levels.push_back( values );
    return levels;
}

TreeNode *buildTree(std::vector<std::optional<int>> &values)
{
    if( values.empty() )
        return nullptr;
    TreeNode *root = new TreeNode( values[0].value() );
    std::queue<TreeNode *> build_queue;
    build_queue.push( root );
    int index = 1;
    while( index < values.size() )
    {
        TreeNode *current = build_queue.front();
        build_queue.pop();
        if( values[index].has_value() )
        {
            TreeNode *left = new TreeNode( values[index].value() );
            current->left = left;
            build_queue.push(left);
        }
        index++;
        if((index<values.size()) && ( values[index].has_value() ))
        {
            TreeNode *right = new TreeNode( values[index].value() );
            current->right = right;
            build_queue.push(right);
        }
        index++;
    }
    return root;
}



int main(int argc, char **argv)
{
    std::cout << "Leetcode #102 - Binary Tree Level Order Traversal" << std::endl;
    int test_case = 1;
    {
        TreeNode *root = nullptr;
        std::vector<std::optional<int>> values = { 3,9,20,std::nullopt,std::nullopt,15,7 };
        root = buildTree(values);
        std::vector<std::vector<int>> expected = { { 3 } , { 9,20 }, { 15,7 }};
        std::vector<std::vector<int>> result   = levelOrder( root );
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        //        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        TreeNode *root = nullptr;
        std::vector<std::optional<int>> values = { 1 };
        root = buildTree(values);
        std::vector<std::vector<int>> expected = { { 1 } };
        std::vector<std::vector<int>> result   = levelOrder( root );
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        //        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        TreeNode *root = nullptr;
        std::vector<std::optional<int>> values = { };
        root = buildTree(values);
        std::vector<std::vector<int>> expected = {  };
        std::vector<std::vector<int>> result   = levelOrder( root );
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        //        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }

    return -1;
}
