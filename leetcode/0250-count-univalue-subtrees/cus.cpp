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
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


bool dfs(TreeNode *root, int &count)
{
    if( root == nullptr )
    {
        return true;
    }
    std::cout << "checking " << root->val << std::endl;

    bool left_valid = dfs(root->left,count);
    bool right_valid = dfs(root->right,count);

    if( !left_valid || !right_valid )
    {
        return false;
    }

    if( root->left != nullptr && ( root->val != root->left->val ))
        return false;
    
    if( root->right != nullptr && ( root->val != root->right->val ))
        return false;

    count++;
    return true;
}

int countUnivalSubtrees(TreeNode* root)
{
    int count = 0;
    dfs(root,count);
    return count;
}

TreeNode *buildTree(std::vector<std::optional<int>> nodes)
{
    if( nodes.size() == 0 )
        return nullptr;
    TreeNode *root = new TreeNode(nodes[0].value());
    std::queue<TreeNode *> bqueue;
    bqueue.push(root);
    int index=1;
    while(index<nodes.size())
    {
        TreeNode *curr = bqueue.front();
        bqueue.pop();
        if( nodes[index].has_value() )
        {
            TreeNode *left = new TreeNode(nodes[index].value());
            curr->left = left;
            bqueue.push(left);
        }
        index++;
        if( ( index<nodes.size() ) && ( nodes[index].has_value() ))
        {
            TreeNode *right = new TreeNode( nodes[index].value() );
            curr->right = right;
            bqueue.push(right);
        }
        index++;
    }
    return root;
}



int main(int argc, char **argv)
{
    std::cout << std::endl << "leetcode/0250-count-univalue-subtrees/" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::optional<int>> nums = {5,1,5,5,5,std::nullopt,5};
        int expected = 4;
        TreeNode *root = buildTree(nums);
        int result = countUnivalSubtrees(root);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<std::optional<int>> nums  = {};
        int expected = 0;
        TreeNode *root = buildTree(nums);
        int result = countUnivalSubtrees(root);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<std::optional<int>> nums  = {5,5,5,5,5,std::nullopt,5};
        int expected = 6;
        TreeNode *root = buildTree(nums);
        int result = countUnivalSubtrees(root);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<std::optional<int>> nums  = {5,5,5,5,1,std::nullopt,5};
        int expected = 4;
        TreeNode *root = buildTree(nums);
        int result = countUnivalSubtrees(root);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
