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
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <limits.h>


void dumpValues(const std::vector<int> values)
{
    bool first = true;
    for(const auto &curr : values )
    {
        if( ! first )
            std::cout << ", ";
        std::cout << curr;
        first = false;
    }
    std::cout << std::endl;
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


struct BfsInfo {
    int depth;
    TreeNode *node;
};
                

std::vector<int> rightSideView(TreeNode *tree)
{
    std::vector<int> retval;
    if( tree == nullptr )
        return retval;
    
    std::queue<BfsInfo> bqueue;
    std::map<int,int> view;
    bqueue.push( { 0, tree } );
    // int last_at_depth = tree->value();
    // int current_depth = 0;
    while( ! bqueue.empty() )
    {
        BfsInfo curr = bqueue.front();
        bqueue.pop();
        view[ curr.depth ] = curr.node->val ;
        if( curr.node->left != nullptr )
        {
            bqueue.push( { curr.depth + 1 , curr.node->left });
        }
        if( curr.node->right != nullptr )
        {
            bqueue.push( { curr.depth + 1 , curr.node->right });
        }
    }
    for( const auto curr : view )
    {
        retval.push_back( curr.second );
    }
    return retval;
}



int main(int argc, char **argv)
{
    std::cout << std::endl << "0199-binary-tree-right-side-view" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::optional<int>> tree_values = { 1,2,3,std::nullopt,5,std::nullopt,4};
        std::vector<int> expected = {1,3,4};
        TreeNode *tree = buildTree(tree_values);
        std::vector<int> result = rightSideView(tree);
        dumpValues(result);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<std::optional<int>> tree_values = { 1,2,3,4,std::nullopt,std::nullopt,std::nullopt,5};
        std::vector<int> expected = {1,3,4,5};
        TreeNode *tree = buildTree(tree_values);
        std::vector<int> result = rightSideView(tree);
        dumpValues(result);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
