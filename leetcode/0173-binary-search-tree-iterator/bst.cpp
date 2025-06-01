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


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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


class BSTIterator {
public:

    std::stack<TreeNode *> nodestack;

    void pushLefts(TreeNode *root)
    {
        TreeNode *node = root;
        while( node != nullptr )
        {
            nodestack.push(node);
            node = node->left;
        }
    }
    
    BSTIterator(TreeNode* root)
    {
        pushLefts(root);
    }
    
    int next()
    {
        TreeNode *curr = nodestack.top();
        nodestack.pop();
        if( curr->right != nullptr )
        {
            pushLefts( curr->right );
        }
        return curr->val;
    }
    
    bool hasNext()
    {
        return ! nodestack.empty();
    }
};



int main(int argc, char **argv)
{
    std::cout << std::endl << "0173-binary-search-tree-iterator" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::optional<int>> values = {7, 3, 15, std::nullopt, std::nullopt, 9, 20};
        TreeNode *root = buildTree(values);
        int expected;
        int result;
        bool bexpected;
        bool bresult;
        BSTIterator *bSTIterator = new BSTIterator(root);
        expected = 3;
        result = bSTIterator->next();    // return 3
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;

        expected = 7;
        result = bSTIterator->next();    // return 7
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        
        bexpected = true;
        bresult = bSTIterator->hasNext(); // return True
        std::cout << "Test case : " << test_case++ << " : " << (bexpected == bresult ? "Pass" : "Fail")  << std::endl;
        
        expected = 9;
        result = bSTIterator->next();    // return 9
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;

        bexpected = true;
        bresult = bSTIterator->hasNext(); // return True
        std::cout << "Test case : " << test_case++ << " : " << (bexpected == bresult ? "Pass" : "Fail")  << std::endl;

        expected = 15;
        result = bSTIterator->next();    // return 15
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;

        bexpected = true;
        bresult = bSTIterator->hasNext(); // return True
        std::cout << "Test case : " << test_case++ << " : " << (bexpected == bresult ? "Pass" : "Fail")  << std::endl;
        
        expected = 20;
        result = bSTIterator->next();    // return 20
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;

        bexpected = false;
        bresult = bSTIterator->hasNext(); // return False
        std::cout << "Test case : " << test_case++ << " : " << (bexpected == bresult ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
