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
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <limits.h>


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
    int x_offset;
    TreeNode *node;
};

std::vector<std::vector<int>> verticalTraversal(TreeNode *tree)
{
    std::map<int, std::map<int, std::vector<int>>> holding;
    std::vector<std::vector<int>> retval;
    if( tree == nullptr )
        return retval;

    std::queue<BfsInfo> bqueue;
    bqueue.push( { 0,0, tree });
    while( ! bqueue.empty() )
    {
        BfsInfo curr = bqueue.front();
        bqueue.pop();

        // std::cout << curr.node->val << " depth: " << curr.depth << " offset: " << curr.x_offset << std::endl;
        holding[curr.x_offset][curr.depth].push_back( curr.node->val );
        if( curr.node->left != nullptr )
        {
            bqueue.push( { curr.depth+1, curr.x_offset-1, curr.node->left });
        }
        if( curr.node->right != nullptr )
        {
            bqueue.push( { curr.depth+1, curr.x_offset+1, curr.node->right });
        }
    }

    // std::cout << "S" << retval.size() <<std::endl;
    for(const auto &outer : holding )
    {
        std::vector<int> current_column;
        for ( auto inner : outer.second )
        {
            // std::cout << "\tL: " << inner.first << std::endl;
            bool first = true;
            for( auto curr : inner.second )
            {
                // if( ! first )
                //     std::cout << ", " ;
                // first = false;
                // std::cout << curr ;
                current_column.push_back( curr );
            }
            // std::cout << std::endl;
        }
        std::sort( current_column.begin(), current_column.end());
        retval.push_back(current_column);
    }
    return retval;
}

void dumpValues(std::vector<std::vector<int>> values)
{
    std::cout << "{" ;
    for( const auto &vec : values )
    {
        std::cout << "{" ;
        bool first = true;
        for( const auto &curr : vec )
        {
            if( !first )
                std::cout << ", ";
            first = false;
            std::cout << curr;
        }
        std::cout << "}" ;
    }
    std::cout << "}" << std::endl;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0987-vertical-order-traversal-of-a-binary-tree" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::optional<int>> tree_values = { 3,9,20,std::nullopt,std::nullopt,15,7};
        std::vector<std::vector<int>> expected = {{9},{3,15},{20},{7}};
        TreeNode *tree = buildTree(tree_values);
        std::vector<std::vector<int>> result = verticalTraversal(tree);
        dumpValues( result );
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<std::optional<int>> tree_values = {1,2,3,4,5,6,7};
        std::vector<std::vector<int>> expected = {{4},{2},{1,5,6},{3},{7}};
        TreeNode *tree = buildTree(tree_values);
        std::vector<std::vector<int>> result = verticalTraversal(tree);
        dumpValues( result );
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<std::optional<int>> tree_values = {1,2,3,4,6,5,7};
        std::vector<std::vector<int>> expected = {{4},{2},{1,5,6},{3},{7}};
        TreeNode *tree = buildTree(tree_values);
        std::vector<std::vector<int>> result = verticalTraversal(tree);
        dumpValues( result );
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
