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


TreeNode *buildTree(std::vector<std::optional<int>> tree_values)
{
    if( tree_values.size() == 0 )
        return nullptr;
    
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

TreeNode* deleteNode(TreeNode* root, int key);

TreeNode *getSuccessor(TreeNode *root)
{
    TreeNode *retval = root->right;
    while(( retval != nullptr ) && ( retval->left != nullptr ))
        retval = retval->left;
    return retval;
}


TreeNode *dfs(TreeNode *root,
              int key,
              std::vector<TreeNode *> &path)
{
    if( root == nullptr )
        return nullptr;
    
    if( root->val == key )
    {
        if( path.size() == 0 )
            return nullptr;
        TreeNode *parent = path.back();
        //        std::cout << "deleting : " << root->val << " and parent is " << parent->val << std::endl;
        // node has no kids, so just set it to null in parent
        if(( root->left == nullptr ) && ( root->right == nullptr ))
        {
            if( parent->left == root )
                parent->left = nullptr;
            if( parent->right == root )
                parent->right = nullptr;
            return nullptr;
        }
        // node has only one child, we just put the child in our place
        else if( root->left == nullptr )
        {
            if( parent->left == root )
                parent->left = root->right;
            if( parent->right == root )
                parent->right = root->right;
            return nullptr;
        }
        else if( root->right == nullptr )
        {
            if( parent->left == root )
                parent->left = root->left;
            if( parent->right == root )
                parent->right = root->left;
            return nullptr;
        }
        // node has two children
        else
        {
            // find inorder successor
            TreeNode *successor = getSuccessor(root);
            root->val = successor->val ;
            root->right = deleteNode( root->right, successor->val );
        }
    }
    
    path.push_back(root);

    
    if( root->val > key )
        dfs( root->left,key,path );
    else
        dfs( root->right,key,path);

    return root;
}

TreeNode* deleteNode(TreeNode* root, int key)
{
    if( root == nullptr )
        return nullptr;

    // handle the special case where we're trying to delete the root
    if( root->val == key )
    {
        if( ( root->left == nullptr ) && ( root->right == nullptr ))
        {
            return nullptr;
        }
        if( root->left == nullptr )
            return root->right;
        if( root->right == nullptr )
            return root->left;

        TreeNode *successor = getSuccessor(root);
        root->val = successor->val;
        root->right = deleteNode(root->right, successor->val );
        return root;
    }
    
    std::vector<TreeNode *> path;
    return dfs(root,key,path);
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0450-delete-node-in-a-bst" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::optional<int>> values = {5,3,6,2,4,std::nullopt,7};
        TreeNode *root = buildTree(values);
        int key = 7;
        deleteNode(root,key);
        bool expected = true;
        bool result = true;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<std::optional<int>> values = {5,3,6,2,4,std::nullopt,7};
        TreeNode *root = buildTree(values);
        int key = 3;
        deleteNode(root,key);
        bool expected = true;
        bool result = true;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<std::optional<int>> values = {5,3,6,2,4,std::nullopt,7};
        TreeNode *root = buildTree(values);
        int key = 4;
        deleteNode(root,key);
        bool expected = true;
        bool result = true;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<std::optional<int>> values = {};
        TreeNode *root = buildTree(values);
        int key = 0;
        deleteNode(root,key);
        bool expected = true;
        bool result = true;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
