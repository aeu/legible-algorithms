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


void dumpValues(const std::vector<int> &values)
{
    bool first_time = true;
    std::cout << "[";
    for(auto current : values )
    {
        if( first_time == false )
            std::cout << ", " ;

        std::cout << current;
        first_time = false;
    }
    std::cout << "]" << std::endl;
}


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *buildTree(std::vector<std::optional<int>> values)
{
    if( values.empty() )
        return nullptr;
    
    TreeNode *root = new TreeNode(values[0].value());
    int index=1;
    std::queue<TreeNode *> nodes;
    nodes.push(root);
    while( index < values.size() )
    {
        TreeNode *curr = nodes.front();
        nodes.pop();
        if( values[index].has_value() )
        {
            TreeNode *new_left = new TreeNode(values[index].value());
            curr->left = new_left;
            nodes.push(new_left);
        }
        index++;
        if(( index < values.size()) && ( values[index].has_value() ))
        {
            TreeNode *new_right = new TreeNode(values[index].value());
            curr->right = new_right;
            nodes.push(new_right);
        }
        index++;
    }
    return root;
}


long sumValues(const std::vector<int> &values)
{
    long base = 1;
    long total = 0;
    for(int index=values.size()-1;index>=0;index--)
    {
        auto current = values[index];
        total += current * base;
        base *=10;
    }
    return total;
}


void dfs(TreeNode *node,
         std::vector<int> &path,
         std::vector<int> &sums)
{
    if( node == nullptr )
        return;
    path.push_back ( node->val );
    if(( node->left == nullptr ) && ( node->right == nullptr ))
    {
        int sum = sumValues(path);
        sums.push_back(sum);
    }
    dfs(node->left, path, sums );
    dfs(node->right, path, sums );
    path.pop_back();
}


long sumNumbers(TreeNode* root)
{
    std::vector<int> path;
    std::vector<int> sums;
    dfs(root,path,sums);
    long total = 0;
    for(auto current : sums )
    {
        total += current;
    }
    return total;
}


// Yes, I know this solution leaks memory, its because it's meant to
// be submitted to Leetcode, whose validator can't handle smart
// pointers.


int main(int argc, char **argv)
{
    std::cout << "Leetcode #129 - Sum Root To Leaf Nodes" << std::endl;
    {
        std::vector<std::optional<int>> p = {2,1,std::nullopt,4,std::nullopt,7,std::nullopt,4,
                                             std::nullopt,8,std::nullopt,3,std::nullopt,6,
                                             std::nullopt,4,std::nullopt,7};
        TreeNode *p_tree = buildTree(p);
        long sum = sumNumbers(p_tree);
        std::cout << "sum is : " << sum << std::endl;
    }
    return -1;
    {
        std::vector<std::optional<int>> p = {1,2,3};
        TreeNode *p_tree = buildTree(p);
        long sum = sumNumbers(p_tree);
        std::cout << "sum is : " << sum << std::endl;
    }
    {
        std::vector<std::optional<int>> p = {4,9,0,5,1};
        TreeNode *p_tree = buildTree(p);
        long sum = sumNumbers(p_tree);
        std::cout << "sum is : " << sum << std::endl;
    }
    return -1;
}


