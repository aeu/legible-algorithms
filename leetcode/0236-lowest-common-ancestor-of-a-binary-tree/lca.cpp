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
#include <set>

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

std::shared_ptr<TreeNode> buildTree(std::vector<std::optional<int>> &values)
{
    if( values.size() == 0 )
        return nullptr;
    int index=0;
    std::shared_ptr<TreeNode> root = std::make_shared<TreeNode>(values[index].value());
    std::queue<std::shared_ptr<TreeNode>> node_queue;
    node_queue.push(root);
    index++;
    while(index<values.size())
    {
        std::shared_ptr<TreeNode> current = node_queue.front();
        node_queue.pop();
        if( values[index].has_value())
        {
            std::shared_ptr<TreeNode> left = std::make_shared<TreeNode>(values[index].value());
            current->setLeft(left);
            node_queue.push(left);
        }
        index++;
        if((index<values.size())&&( values[index].has_value()))
        {
            std::shared_ptr<TreeNode> right = std::make_shared<TreeNode>(values[index].value());
            current->setRight(right);
            node_queue.push(right);
        }
        index++;
    }
    return root;
}

void dumpPath(std::vector<std::shared_ptr<TreeNode>> &path)
{
    bool first_time = true;
    std::cout << "[";
    for(auto current : path )
    {
        if( ! first_time )
            std::cout << ", ";
        std::cout << current->getValue();
        first_time = false;
    }
    std::cout << "]" << std::endl;
}

bool dfs(std::shared_ptr<TreeNode> root,
         std::vector<std::shared_ptr<TreeNode>> &path,
         const int target)
{
    if( root == nullptr )
        return false;
    path.push_back(root);
    if( root->getValue() == target )
    {
        return true;
    }
    if( dfs(root->getLeft(),path,target))
        return true;
    
    if(dfs(root->getRight(),path,target))
        return true;

    path.pop_back();
    return false;
}
std::shared_ptr<TreeNode> lowestCommonAncestor( std::vector<std::shared_ptr<TreeNode>> path_to_p,
                                                std::vector<std::shared_ptr<TreeNode>> path_to_q )
{
    std::set<std::shared_ptr<TreeNode>> matching_set;
    for(auto current : path_to_p )
    {
        matching_set.insert( current );
    }
    for(int index=path_to_q.size()-1;index>=0;index--)
    {
        auto current = path_to_q[index];
        auto insertion = matching_set.insert( current );
        if( insertion.second == false )
        {
            return current;
        }
    }
    return nullptr;
}


std::shared_ptr<TreeNode> lowestCommonAncestor(std::shared_ptr<TreeNode> root,
                                               const int p,
                                               const int q)
{
    std::vector<std::shared_ptr<TreeNode>> path_to_p;
    std::vector<std::shared_ptr<TreeNode>> path_to_q;
    bool p_found = dfs(root,path_to_p,p);
    bool q_found = dfs(root,path_to_q,q);
    if( p_found && q_found )
    {
        std::shared_ptr<TreeNode> lca = lowestCommonAncestor( path_to_p, path_to_q );
        if( lca != nullptr )
        {
            return lca;
        }
    }
    return nullptr;
}

int main(int argc, char **argv)
{
    std::cout << "Leetcode #0236 - Lowest Common Ancestor of a Binary Tree" << std::endl;
    {
        std::cout << "Example 1" << std::endl;
        int p = 5;
        int q = 1;
        std::vector<std::optional<int>> values =
            { 3,5,1,6,2,0,8,std::nullopt,std::nullopt,7,4};
        std::cout << "Input : ";
        dumpValues( values );
        std::cout << "p = " << p << std::endl;
        std::cout << "q = " << q << std::endl;
        std::shared_ptr<TreeNode> root = buildTree(values);
        auto lca = lowestCommonAncestor(root,p,q);
        std::cout << "LCA: " << lca->getValue() << std::endl;
    }
    {
        std::cout << std::endl << "Example 2" << std::endl;
        std::vector<std::optional<int>> values =
            {3,5,1,6,2,0,8,std::nullopt,std::nullopt,7,4};
        int p = 5;
        int q = 4;
        std::cout << "Input : ";
        dumpValues( values );
        std::cout << "p = " << p << std::endl;
        std::cout << "q = " << q << std::endl;
        std::shared_ptr<TreeNode> root = buildTree(values);
        auto lca = lowestCommonAncestor(root,p,q);
        std::cout << "LCA: " << lca->getValue() << std::endl;
    }
    {
        std::cout << std::endl << "Example 3" << std::endl;
        std::vector<std::optional<int>> values =
            {1,2};
        int p = 1;
        int q = 2;
        std::cout << "Input : ";
        dumpValues( values );
        std::cout << "p = " << p << std::endl;
        std::cout << "q = " << q << std::endl;
        std::shared_ptr<TreeNode> root = buildTree(values);
        auto lca = lowestCommonAncestor(root,p,q);
        std::cout << "LCA: " << lca->getValue() << std::endl;
    }

    return -1;
}
