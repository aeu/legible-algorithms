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


std::string pathToString(std::vector<TreeNode *>path)
{
    std::string retval;
    bool first = true;
    for(const auto &curr : path )
    {
        if( ! first )
            retval+="->";
        first = false;
        retval += std::to_string(curr->val);
    }
    return retval;
}

void dfs(TreeNode *root,
         std::vector<TreeNode *> &path,
         std::set<std::vector<TreeNode *>> &paths)
{
    if( root == nullptr )
        return;

    path.push_back(root);
    
    dfs(root->left,path,paths);

    if(( root->left  == nullptr ) && ( root->right == nullptr  ))
    {
        paths.insert( path );
    }
    dfs(root->right,path,paths);

    path.pop_back();
}

std::vector<std::string> binaryTreePaths(TreeNode* root)
{
     std::set<std::vector<TreeNode *>> paths;
     std::vector<TreeNode *> path;
     dfs(root,path,paths);
     std::vector<std::string> retval;
     for(const auto &cpath : paths )
     {
         retval.push_back(pathToString(cpath));
     }
     return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0257-binary-tree-paths" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::optional<int>> nums  = {1,2,3,std::nullopt,5};
        TreeNode *root = buildTree(nums);
        std::vector<std::string> result = binaryTreePaths(root);
        std::vector<std::string> expected = {"1->2->5","1->3"};
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
