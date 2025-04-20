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
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <limits.h>


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
void dumpPath(std::vector<TreeNode *> &path)
{
    for( auto curr : path )
    {
        std::cout << curr->val << " -> ";
    }
    std::cout << std::endl;
}


void dumpPathSum(std::vector<int> &cps)
{
    bool first_time = true;
    for(auto curr : cps )
    {
        if( ! first_time )
            std::cout << ", ";
        std::cout << curr ;
        first_time = false;
    }
    std::cout << std::endl;
}

void processPath(int targetSum,
                 std::vector<TreeNode *> &path,
                 std::set<std::vector<int>> &found)
{
    int running_sum = 0;
    std::unordered_map<int,std::vector<int>> prefix_sums;
    for(int index=0;index<path.size();index++)
    {
        TreeNode *curr = path[index];
        running_sum += curr->val;
        prefix_sums[running_sum].push_back(index);
        int prefix_needed = running_sum - targetSum;
        auto piter = prefix_sums.find( prefix_needed );
        if( piter != prefix_sums.end() )
        {
            // at this point we have a path whose sum is target sum in
            // the path, and it starts at the position(s) in the prefix sum map
            for( const auto &curr : piter->second )
            {
                int running = targetSum;
                std::vector<int> current_path_sum;
                for(int index=curr+1;index<path.size();index++)
                {
                    if( running == 0 )
                    {
                        break;
                    }
                    current_path_sum.push_back( path[index]->val );
                    running -= path[index]->val;
                }
                if( found.count ( current_path_sum ) == 0 ) 
                {
                    found.insert( current_path_sum );
                }
            }
        }
    }
}

TreeNode *dfs(TreeNode *root,
              int targetSum,
              std::vector<TreeNode *> &path,
              std::set<std::vector<int>> &found
              )
         
{
    if( root == nullptr )
        return root;

    path.push_back(root);
    if(( root->left == nullptr ) && ( root->right == nullptr ))
    {
        // end node, do prefix sum stuff here so its done only once
    }

    processPath(targetSum,path,found);
    if( root->left != nullptr )
    {
        dfs( root->left, targetSum, path, found );
    }

    if( root->right != nullptr )
    {
        dfs( root->right, targetSum, path, found );
    }
    path.pop_back();
    return root;
}


int pathSum(TreeNode* root, int targetSum)
{
    std::vector<TreeNode *> path;
    std::set<std::vector<int>> found;
    dfs(root,targetSum,path,found);
    for(auto curr: found )
    {
        dumpPathSum(curr);
    }
    return found.size();
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::optional<int>> values = { 10,5,-3,3,2,std::nullopt,11,3,-2,std::nullopt,1 };
        TreeNode *root  = buildTree(values);
        int expected = 3;
        int targetSum = 8;
        int result = pathSum(root,targetSum);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::optional<int>> values = { 5,4,8,11,std::nullopt,13,4,7,2,std::nullopt,std::nullopt,5,1 };
        TreeNode *root  = buildTree(values);
        int expected = 3;
        int targetSum = 22;
        int result = pathSum(root,targetSum);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
