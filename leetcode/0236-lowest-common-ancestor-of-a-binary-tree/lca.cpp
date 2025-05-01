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


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
TreeNode *pnode;
TreeNode *qnode;



TreeNode *buildTree(std::vector<std::optional<int>> values, int p, int q)
{
    TreeNode *root = new TreeNode(values[0].value());
    if( root->val == p )
        pnode = root;
    if( root->val == q )
        qnode = root;
    
    int index = 1;
    std::queue<TreeNode *> bqueue;
    bqueue.push(root);
    while( index < values.size() )
    {
        TreeNode *curr = bqueue.front();
        bqueue.pop();

        if( values[index].has_value() )
        {
            TreeNode *left = new TreeNode( values[index].value());
            curr->left = left;
            bqueue.push(left);
            if( left->val == p )
                pnode = left;
            else if( left->val == q )
                qnode = left;
        }
        index++;
        if((index<values.size())&&(values[index].has_value()))
        {
            TreeNode *right = new TreeNode(values[index].value());
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

TreeNode *dfs(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if( root == nullptr )
        return root;

    // I am one of the nodes being searched for, so return myself.
    if( root == p )
        return root;

    // I am one of the nodes being searched for, so return myself.
    if( root == q )
        return root;

    TreeNode *left = dfs(root->left,p,q);
    TreeNode *right = dfs(root->right,p,q);
    
    // if both the left and right dfs have non-null returns, then that
    // means that I am an ancester of both
    if( ( left != nullptr ) && ( right != nullptr ))
    {
        return root;
    }

    // only one subtree is non-null, then that subtree has both p and
    // q, so its the LCA
    if( left != nullptr )
        return left;
    return right;
}


TreeNode *lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    TreeNode *lca = dfs(root,p,q);
    return lca;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0236-lowest-common-ancestor-of-a-binary-tree" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::optional<int>> values = {3,5,1,6,2,0,8,std::nullopt,std::nullopt,7,4};
        int p = 5;
        int q = 1;
        int expected = 3;
        TreeNode *root = buildTree(values,p,q);
        TreeNode *res = lowestCommonAncestor(root, pnode, qnode);
        int result = -1;
        if( res != nullptr )
            result = res->val;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::optional<int>> values = {1,2};
        int p = 1;
        int q = 2;
        int expected = 1;
        TreeNode *root = buildTree(values,p,q);
        TreeNode *res = lowestCommonAncestor(root, pnode, qnode);
        int result = -1;
        if( res != nullptr )
            result = res->val;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
