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

int findLongestZigZagSegment(std::vector<TreeNode *> &path, int &max_zags)
{
    if( path.size() == 0 )
        return 0;
    if( path.size() == 1 )
        return 0;
    int zag_count = 1;
    int last_direction = 0;
    int next_direction;
    
    for(int index=0;index<path.size()-1;index++)
    {
        TreeNode * previous = ( index > 1 ) ? path[index-1] : nullptr;
        TreeNode * current = path[index];
        TreeNode * next = path[index+1];
        
        if( next == current->left )
        {
            next_direction = -1;
        }
        else
        {
            next_direction = 1;
        }
            
        if( last_direction == 0 )
        {
            last_direction = next_direction;
        }
        else if( next_direction == last_direction )
        {
            max_zags = std::max(max_zags,zag_count);
            zag_count = 1;
        }
        else
        {
            zag_count++;
        }
        last_direction = next_direction;
    }
    max_zags = std::max(max_zags,zag_count);
    return max_zags;
}


int dfs(TreeNode * root,
        std::vector<TreeNode *> &path,
        int &max_zags)
{
    if( root == nullptr )
        return 0;

    path.push_back(root);
    if(( root->left == nullptr ) && ( root->right == nullptr ))
    {
        findLongestZigZagSegment(path,max_zags);
    }
    dfs(root->left,path,max_zags);
    dfs(root->right,path,max_zags);
    path.pop_back();
    return max_zags;
}

int longestZigZag(TreeNode * root )
{
    int max_zags = 0;
    std::vector<TreeNode *> path;
    dfs(root,path,max_zags);
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
