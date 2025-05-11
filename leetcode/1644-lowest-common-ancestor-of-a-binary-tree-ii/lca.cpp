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
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* pnode;
TreeNode* qnode;
        
void dumpNodeList(std::vector<TreeNode *> values)
{
    bool first = true;
    for(const auto &curr : values )
    {
        if( ! first )
            std::cout << "->" ;
        first = false;
        std::cout << curr->val;
    }
    std::cout << std::endl;
}


TreeNode *buildTree(std::vector<std::optional<int>> &nums,
                int p,
                int q)
{
    TreeNode *root = new TreeNode(nums[0].value());
    if( root->val == p )
        pnode = root;
    else if( root->val == q )
        qnode = root;
    int index=1;
    std::queue<TreeNode *> bqueue;
    bqueue.push(root);
    while( index<nums.size())
    {
        TreeNode *curr = bqueue.front();
        bqueue.pop();
        if( nums[index].has_value())
        {
            TreeNode *left = new TreeNode(nums[index].value());
            curr->left = left;
            bqueue.push(left);
            if( left->val == p )
                pnode = left;
            else if( left->val == q )
                qnode = left;
        }
        index++;
        
        if((index<nums.size()) && ( nums[index].has_value()))
        {
            TreeNode *right = new TreeNode(nums[index].value());
            curr->right = right;
            bqueue.push(right);
            if( right->val == p )
                pnode = right;
            else if( right->val == q )
                qnode = right;
        }
        index++;
    }
    return root;
}

bool dfs(TreeNode *root,
         TreeNode *target,
         std::vector<TreeNode *> &path)
{
    if( root == nullptr )
        return false;

    path.push_back(root);
    if( root == target )
    {
        return true;
    }

    if( dfs( root->left, target, path ) || dfs( root->right, target, path ))
        return true;

    path.pop_back();
    return false;
}


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    std::vector<TreeNode *> ppath;
    std::vector<TreeNode *> qpath;
    dfs( root, p, ppath );

    std::unordered_set<TreeNode *> pathset;
    for(const auto &curr : ppath )
    {
        pathset.insert( curr );
    }
    
    dfs( root, q, qpath );

    for(int index=qpath.size()-1;index>=0;index--)
    {
        const auto &curr = qpath[index];
        if( pathset.count( curr ) != 0 )
            return curr;
    }
    
    return nullptr;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "1644-lowest-common-ancestor-of-a-binary-tree-ii" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::optional<int>> nums  = {3,5,1,6,2,0,8,std::nullopt,std::nullopt,7,4};
        int p = 5;
        int q = 1;
        int expected = 3;
        TreeNode *root = buildTree(nums,p,q);
        TreeNode* lca = lowestCommonAncestor(root, pnode, qnode); 
        int result   = 0;
        if( lca != nullptr )
            result = lca->val;

        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::optional<int>> nums  = {3,5,1,6,2,0,8,std::nullopt,std::nullopt,7,4};
        int p = 5;
        int q = 4;
        int expected = 5;
        TreeNode *root = buildTree(nums,p,q);
        TreeNode* lca = lowestCommonAncestor(root, pnode, qnode); 
        int result   = 0;
        if( lca != nullptr )
            result = lca->val;

        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::optional<int>> nums  = {3,5,1,6,2,0,8,std::nullopt,std::nullopt,7,4};
        int p = 5;
        int q = 10;
        int expected = 0;
        TreeNode *root = buildTree(nums,p,q);
        TreeNode* lca = lowestCommonAncestor(root, pnode, qnode); 
        int result   = 0;
        if( lca != nullptr )
            result = lca->val;

        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
