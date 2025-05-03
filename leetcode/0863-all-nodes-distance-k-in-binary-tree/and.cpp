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


TreeNode *target_node;

TreeNode *buildTree(std::vector<std::optional<int>> tree_values, int target)
{
    TreeNode *root = new TreeNode(tree_values[0].value());
    if( root->val == target )
        target_node = root;
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
            if( left->val == target )
                target_node = left;
            curr->left = left;
            bqueue.push(left);
        }
        index++;
        if( ( index < tree_values.size() ) && ( tree_values[index].has_value() ))
        {
            TreeNode *right = new TreeNode( tree_values[index].value() );
            if( right->val == target )
                target_node = right;
            curr->right = right;
            bqueue.push(right);
        }
        index++;
    }
    return root;
}

struct BfsInfo
{
    int distance;
    TreeNode *node;
};


std::vector<int> distanceK(TreeNode* root, TreeNode* target, int k)
{
    std::unordered_map<TreeNode *, TreeNode *> parents;
    std::unordered_set<int> seen;
    std::vector<int> retval;
    std::queue<TreeNode *> pqueue;
    pqueue.push(root);
    while( !pqueue.empty() )
    {
        TreeNode *curr = pqueue.front();
        pqueue.pop();
        if( curr->left )
        {
            parents[curr->left] = curr;
            pqueue.push(curr->left);
        }
        if( curr->right )
        {
            parents[curr->right] = curr;
            pqueue.push(curr->right);
        }
    }
    std::queue<BfsInfo> bqueue;
    bqueue.push( { 0, target } );
    seen.insert( target->val );
    while( ! bqueue.empty() )
    {
        BfsInfo curr = bqueue.front();
        bqueue.pop();
        if( curr.distance == k )
            retval.push_back( curr.node->val );
        TreeNode *left = curr.node->left;
        if( left != nullptr )
        {
            if( seen.count(left->val) == 0 )
            {
                seen.insert( left->val );
                bqueue.push({ curr.distance+1, left });
            }
        }
        TreeNode *right = curr.node->right;
        if( right != nullptr )
        {
            if( seen.count( right->val ) == 0 )
            {
                seen.insert( right->val );
                bqueue.push({ curr.distance+1, right });
            }
        }
        auto piter = parents.find( curr.node );
        if( piter != parents.end() )
        {
            TreeNode *parent = piter->second;
            if( seen.count( parent->val ) == 0 )
            {
                seen.insert( parent->val );
                bqueue.push({curr.distance+1,parent});
            }
        }
    }
    return retval;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "0863-all-nodes-distance-k-in-binary-tree" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::optional<int>> nums  = {3,5,1,6,2,0,8,std::nullopt,std::nullopt,7,4};
        int target = 5;
        int k = 2;
        TreeNode *root = buildTree(nums,target);
        std::vector<int> result = distanceK(root,target_node,k);
        std::vector<int> expected = { 7,4,1};
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<std::optional<int>> nums  = {1};
        int target = 1;
        int k = 3;
        TreeNode *root = buildTree(nums,target);
        std::vector<int> result = distanceK(root,target_node,k);
        std::vector<int> expected = {};
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
