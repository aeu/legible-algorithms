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



struct BfsInfo
{
    TreeNode *node;
    int level;
};

bool isCompleteTree(TreeNode *root)
{
    if( root == nullptr )
        return false;

    std::queue<BfsInfo> bqueue;
    bqueue.push({root,0});
    BfsInfo prev({nullptr,0});
    while( ! bqueue.empty() )
    {
        BfsInfo curr = bqueue.front();
        bqueue.pop();

        // curr's left was null and right wasn't, returning false"
        if(( curr.node->left == nullptr ) && (curr.node->right != nullptr ))
        {
            return false;
        }

        // The previous node had a level below us, so we are the first
        // node on a new row.  So make sure that node has a left node
        // set.
        if((prev.node != nullptr ) && ( prev.level == curr.level - 1 ))
        {
            // curr is first of a new row, it has a left, but the last
            // on the previous row didn't have a right
            if( ( curr.node->left != nullptr ) && ( prev.node->right == nullptr ))
            {
                return false;
            }
            // curr is first of a new row, but the last of the
            // previous row had nulls for both left and right
            if(( prev.node->left == nullptr ) && ( prev.node->right != nullptr))
            {
                return false;
            }
        }

        // if the previous node existed, and was the same level as the
        // current node, and had a gap on the right, then this tree is
        // not complete
        
        if((prev.node != nullptr ) && ( prev.level == curr.level ))
        {
            // the right node of the previous node at our level was null but our left isn't" << std::endl;
            if(( prev.node->right == nullptr ) && ( prev.node->left != nullptr) && (curr.node->left != nullptr))
            {
                return false;
            }
            // curr has a left, but the previous node at our level has either a left or a right of null
            if( ( curr.node->left != nullptr )
                && (( prev.node->right == nullptr ) || ( prev.node->left == nullptr)))
            {
                return false;
            }
        }

        
        if( curr.node->left != nullptr )
            bqueue.push({ curr.node->left, curr.level+1 });
        if( curr.node->right != nullptr )
            bqueue.push({ curr.node->right, curr.level+1 });
        prev = curr;
    }
    return true;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "0958-check-completeness-of-a-binary-tree" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::optional<int>> values = {1,2,3,4,5,6,7,8,9,10,11,12,13,std::nullopt,std::nullopt,15};
        TreeNode *root = buildTree(values);
        bool expected = false;
        bool result = isCompleteTree(root);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::optional<int>> values = {1,2,3,4,5,6};
        TreeNode *root = buildTree(values);
        bool expected = true;
        bool result = isCompleteTree(root);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::optional<int>> values = {1,2,3,4,std::nullopt,7};
        TreeNode *root = buildTree(values);
        bool expected = false;
        bool result = isCompleteTree(root);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        
        std::vector<std::optional<int>> values = {1,2,3,std::nullopt,std::nullopt,7,8};
        TreeNode *root = buildTree(values);
        bool expected = false;
        bool result = isCompleteTree(root);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        
        std::vector<std::optional<int>> values = {1,2,3,4,5,6,7,8,9,10,11,12,13,std::nullopt,std::nullopt,15};
        TreeNode *root = buildTree(values);
        bool expected = false;
        bool result = isCompleteTree(root);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
