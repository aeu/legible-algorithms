// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82
//
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <optional>
#include <queue>

void dumpValues(const std::vector<std::optional<int>> &values)
{
    bool first_time = true;
    std::cout << "[";
    for(auto current : values )
    {
        if( first_time == false )
            std::cout << ", " ;

        if( current.has_value() )
            std::cout << current.value();
        else
            std::cout << "null";
        first_time = false;
    }
    std::cout << "]" << std::endl;
}

struct TreeNode {
    int val;
    TreeNode  *left;
    TreeNode  *right;
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




int nodeSearch(TreeNode * current,
               const int base_value)
{
    if( current == nullptr )
        return 0;
    int max_value = base_value;
    int good = 0;
    if( current->val >= max_value )
        good = 1;

    max_value = std::max( max_value, current->val);

    good += nodeSearch( current->left, max_value );
    good += nodeSearch( current->right, max_value );

    return good;
}



int goodNodes(TreeNode * current)
{
    int good_nodes = nodeSearch(current, current->val);
    return good_nodes;
}
                  

int main(int argc, char **argv)
{
    std::cout << "Leetcode #1448 - Count Good Nodes in Binary Tree" << std::endl;
    int test_case = 1;
    {
        std::vector<std::optional<int>> values = {3,1,4,3,std::nullopt,1,5};
        TreeNode * root = buildTree(values);
        int result = goodNodes(root);
        int expected = 4;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::optional<int>> values = {3,3,std::nullopt,4,2};
        TreeNode * root = buildTree(values);
        int result = goodNodes(root);
        int expected = 3;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::optional<int>> values = {1};
        TreeNode * root = buildTree(values);
        int result = goodNodes(root);
        int expected = 1;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return -1;
}
