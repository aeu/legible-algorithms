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

int max_zags = 0;

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

std::shared_ptr<TreeNode> buildTree(const std::vector<std::optional<int>> &values)
{
    std::queue<std::shared_ptr<TreeNode>> node_list;
    int index=0;
    std::shared_ptr<TreeNode> root = std::make_shared<TreeNode>(values[index].value());
    node_list.push(root);
    index++;
    while(index<values.size())
    {
        std::shared_ptr<TreeNode> current = node_list.front();
        node_list.pop();
        if( values[index].has_value())
        {
            std::shared_ptr<TreeNode> left = std::make_shared<TreeNode>(values[index].value());
            current->setLeft(left);
            node_list.push(left);
        }
        index++;
        if((index<values.size())&&( values[index].has_value()))
        {
            std::shared_ptr<TreeNode> right = std::make_shared<TreeNode>(values[index].value());
            current->setRight(right);
            node_list.push(right);
        }
        index++;
    }
    return root;
}


struct PathEntry {
    bool left;
    std::shared_ptr<TreeNode> node;
};

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

int findLongestZigZagSegment(std::vector<std::shared_ptr<TreeNode>> &path)
{
    if( path.size() == 0 )
        return 0;
    if( path.size() == 1 )
        return 0;
    int zag_count = 1;
    int max_zags = 0;
    int last_direction = 0;
    int next_direction;
    
    for(int index=0;index<path.size()-1;index++)
    {
        std::shared_ptr<TreeNode> previous = ( index > 1 ) ? path[index-1] : nullptr;
        std::shared_ptr<TreeNode> current = path[index];
        std::shared_ptr<TreeNode> next = path[index+1];
        
        if( next == current->getLeft() )
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


int dfs(std::shared_ptr<TreeNode> root,
        std::vector<std::shared_ptr<TreeNode>> &path)
{
    int lzz = 0;
    int zags = 0;
    if( root == nullptr )
        return 0;

    path.push_back(root);
    if(( root->getLeft() == nullptr ) && ( root->getRight() == nullptr ))
    {
        zags = findLongestZigZagSegment(path);
        lzz = std::max(lzz,zags);
    }
    dfs(root->getLeft(),path);
    dfs(root->getRight(),path);
    path.pop_back();
    max_zags = std::max(max_zags,lzz);
    return lzz;
}

int zigZag(std::shared_ptr<TreeNode> root )
{
    std::vector<std::shared_ptr<TreeNode>> path;
    int lzz = dfs(root,path);
    return lzz;
}

int main(int argc, char **argv)
{
    std::cout << "Leetcode #1372 - Longest ZigZag Path in a Binary Tree" << std::endl;
    {
        max_zags = 0;
        std::cout << "Example 1" << std::endl;
        std::vector<std::optional<int>> values =
            { 1, std::nullopt,1,1,1,std::nullopt,std::nullopt,1,1,std::nullopt,1,std::nullopt,std::nullopt,std::nullopt,1 };
        std::cout << "Input : ";
        dumpValues( values );
        std::shared_ptr<TreeNode> root = buildTree(values);
        zigZag(root);
        std::cout << "Max zzp : " << max_zags << std::endl;
    }
    {
        max_zags = 0;
        std::cout << "Example 2" << std::endl;
        std::vector<std::optional<int>> values =
            { 1,1,1,std::nullopt,1,std::nullopt,std::nullopt,1,1,std::nullopt,1};
        std::cout << "Input : ";
        dumpValues( values );
        std::shared_ptr<TreeNode> root = buildTree(values);
        zigZag(root);
        std::cout << "Max zzp : " << max_zags << std::endl;
    }
    {
        max_zags = 0;
        std::cout << "Example 3" << std::endl;
        std::vector<std::optional<int>> values = { 1 };
        std::cout << "Input : ";
        dumpValues( values );
        std::shared_ptr<TreeNode> root = buildTree(values);
        zigZag(root);
        std::cout << "Max zzp : " << max_zags << std::endl;
    }

    return -1;
}
