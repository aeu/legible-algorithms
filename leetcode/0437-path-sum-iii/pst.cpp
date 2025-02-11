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

#include "TreeNode.h"


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

void dumpPath(const std::vector<std::shared_ptr<TreeNode>> &values )
{
    bool first_time = true;
    std::cout << "[";
    for( auto current : values )
    {
        if( ! first_time )
            std::cout << ", ";
        std::cout << current->getValue();
        first_time = false;
    }
    std::cout << "]" << std::endl;
}

std::shared_ptr<TreeNode> buildTree(std::vector<std::optional<int>> &values)
{
    int index = 0;
    std::shared_ptr<TreeNode> root = std::make_shared<TreeNode>(values[index].value());
    std::queue<std::shared_ptr<TreeNode>> node_queue;
    node_queue.push( root);
    index++;
    while(index<values.size())
    {
        std::shared_ptr<TreeNode> current = node_queue.front();
        node_queue.pop();
        if( values[index].has_value() )
        {
            std::shared_ptr<TreeNode> left = std::make_shared<TreeNode>(values[index].value());
            node_queue.push( left );
            current->setLeft(left);
        }
        index++;
        if( ( index < values.size() ) && ( values[index].has_value() ))
        {
            std::shared_ptr<TreeNode> right = std::make_shared<TreeNode>(values[index].value());
            node_queue.push(right);
            current->setRight(right);
        }
        index++;
    }
    return root;
}

int markPath(const std::vector<std::shared_ptr<TreeNode>> &path,
              int endpoint,
             int target_sum,
             std::map< std::vector<std::shared_ptr<TreeNode>>,int> &valid_paths)
{
    std::vector<std::shared_ptr<TreeNode>> marked_path;
    int running_sum = 0;
    for(int index=endpoint;index>=0;index--)
    {
        auto current = path[index];
        marked_path.push_back(current);
        running_sum += current->getValue();
        if( running_sum == target_sum )
            break;
    }
    valid_paths[marked_path] = 1;
    return 0;
}

int sumFunction(const std::vector<std::shared_ptr<TreeNode>> &path,
                int target_sum,
                std::map< std::vector<std::shared_ptr<TreeNode>>,int> &valid_paths)
{
    std::map<int,int> prefix_sums;
    std::map<int,int>::iterator psiter;
    prefix_sums[0]++;
    int sum_count = 0;
    int running_sum = 0;
    for(int index=0;index<path.size();index++)
    {
        auto current = path[index];
        running_sum+=current->getValue();
        int prefix_sum = running_sum - target_sum;
        psiter = prefix_sums.find(prefix_sum);
        if( psiter != prefix_sums.end() )
        {
            sum_count += psiter->second;
            markPath(path,index,target_sum,valid_paths);
        }
        prefix_sums[running_sum]++;
    }
    return sum_count;
}

void dfs(std::shared_ptr<TreeNode> root,
         std::vector<std::shared_ptr<TreeNode>> &path,
         int target_sum,
         std::map< std::vector<std::shared_ptr<TreeNode>>,int> &valid_paths)
{
    if( root == nullptr )
        return;

    path.push_back(root);
    if(( root->getLeft() == nullptr ) && ( root->getRight() == nullptr ))
    {
        sumFunction( path, target_sum, valid_paths );
    }
    else
    {
        dfs( root->getLeft(), path,target_sum,valid_paths );
        dfs( root->getRight(), path,target_sum,valid_paths );
    }
    path.pop_back();
}

int walkToLeaves(std::shared_ptr<TreeNode> root,
                 int target_sum)
{
    std::vector<std::shared_ptr<TreeNode>> path;
    std::map< std::vector<std::shared_ptr<TreeNode>>,int> valid_paths;
    dfs(root,path,target_sum,valid_paths);
    std::cout << "valid paths count : " << valid_paths.size() << std::endl;
    std::cout << "These are: " << std::endl;
    for(auto current : valid_paths )
    {
        dumpPath( current.first );
    }
    return 0;
}


int main(int argc, char **argv)
{
    std::cout << "Leetcode #437 - Path Sum III" << std::endl;
    {
        std::cout << "Example 1" << std::endl;
        int target_sum = 8;
        std::vector<std::optional<int>> values = { 10,5,-3,3,2,std::nullopt,11,3,-2,std::nullopt,1 };
        std::cout << "Input : ";
        dumpValues( values );
        std::cout << "Looking for a sum of : " << target_sum << std::endl;
        std::shared_ptr<TreeNode> root = buildTree(values);
        walkToLeaves(root,target_sum);
    }
    {
        std::cout << "Example 2" << std::endl;
        int target_sum = 22;
        std::vector<std::optional<int>> values = { 5,4,8,11,std::nullopt,13,4,7,2,std::nullopt,std::nullopt,5,1 };
        std::cout << "Input : ";
        dumpValues( values );
        std::cout << "Looking for a sum of : " << target_sum << std::endl;
        std::shared_ptr<TreeNode> root = buildTree(values);
        walkToLeaves(root,target_sum);
    }

    return -1;
}
