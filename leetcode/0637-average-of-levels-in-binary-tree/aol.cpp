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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x ) : val(x), left(nullptr), right(nullptr) {}
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

void dumpDoubles(const std::vector<double> &values )
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

struct bfs_data
{
    int level;
    TreeNode *node;
};

std::vector<double> averageOfLevels(TreeNode *root)
{
    int current_level = 0;
    int num_at_level = 0;
    double running_sum = 0;
    std::vector<double> averages;
    std::queue<bfs_data> bfs_queue;

    bfs_queue.push( { 0, root } );
    while( ! bfs_queue.empty() )
    {
        bfs_data current = bfs_queue.front();
        bfs_queue.pop();
        if( current.level == current_level )
        {
            running_sum += current.node->val;
            num_at_level++;
        }
        else
        {
            double average = running_sum / num_at_level;
            averages.push_back( average );
            running_sum = 0;
            num_at_level = 0;
            current_level = current.level;

            num_at_level++;
            running_sum += current.node->val;
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
    double average = running_sum / num_at_level;
    averages.push_back( average );
    return averages;
}

TreeNode *buildTree(std::vector<std::optional<int>> values)
{
    int index=0;
    TreeNode *root;
    std::queue<TreeNode *> tqueue;
    root = new TreeNode(values[0].value());
    tqueue.push( root );
    index++;
    while( index < values.size() )
    {
        TreeNode *current = tqueue.front();
        tqueue.pop();
        if( values[index].has_value() )
        {
            TreeNode *left = new TreeNode( values[index].value() );
            current->left = left;
            tqueue.push(left);
        }
        index++;
        if(( index < values.size()) && ( values[index].has_value() ))
        {
            TreeNode *right = new TreeNode( values[index].value() );
            current->right = right;
            tqueue.push(right);
        }
        index++;
    }
    return root;
}

int main(int argc, char **argv)
{
    std::cout << "Leetcode #637 - Average of Levels in Binary Tree" << std::endl;
    int test_case = 1;
    {
        TreeNode *root = nullptr;
        std::vector<std::optional<int>> values = { 3,9,20,std::nullopt,std::nullopt,15,7 };
        root = buildTree(values);
        std::vector<double> expected = { 3.0, 14.5, 11.0 };
        std::vector<double> result   = averageOfLevels( root );
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        //        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        TreeNode *root = nullptr;
        std::vector<std::optional<int>> values = { 3,9,20,15,7 };
        root = buildTree(values);
        std::vector<double> expected = { 3.0, 14.5, 11.0 };
        std::vector<double> result   = averageOfLevels( root );
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        //        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }

    return -1;
}
