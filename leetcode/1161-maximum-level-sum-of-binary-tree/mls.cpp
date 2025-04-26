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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
TreeNode *buildTree(std::vector<std::optional<int>> values)
{
    int index=0;
    TreeNode *root;
    std::queue<TreeNode *> tqueue;
    root = new TreeNode(values[0].value());
    tqueue.push( root );
    index++;
    while( index < values.size() )
    {
        TreeNode *current = tqueue.front();
        tqueue.pop();
        if( values[index].has_value() )
        {
            TreeNode *left = new TreeNode( values[index].value() );
            current->left = left;
            tqueue.push(left);
        }
        index++;
        if(( index < values.size()) && ( values[index].has_value() ))
        {
            TreeNode *right = new TreeNode( values[index].value() );
            current->right = right;
            tqueue.push(right);
        }
        index++;
    }
    return root;
}


struct BfsInfo {
    int level;
    TreeNode *node;
};

int maxLevelSum(TreeNode* root)
{
    std::queue<BfsInfo> bqueue;
    std::unordered_map<int,int> sums;
    bqueue.push( { 0, root } );
    while( ! bqueue.empty() )
    {
        BfsInfo curr = bqueue.front();
        bqueue.pop();
        sums[curr.level] += curr.node->val;
        if( curr.node->left != nullptr )
            bqueue.push( { curr.level+1, curr.node->left });
        if( curr.node->right != nullptr )
            bqueue.push( { curr.level+1, curr.node->right });
    }
    int max_sum = INT_MIN;
    int level = 0;
    for(auto curr : sums )
    {
        if( curr.second > max_sum )
        {
            max_sum = curr.second;
            level = curr.first;
        }
        else if( curr.second == max_sum )
        {
            if( curr.first < level )
                level = curr.first;
        }
    }
    return level + 1;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "1161-maximum-level-sum-of-binary-tree" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::optional<int>> values = { 1,1,0,7,-8,-7,9};
        int expected = 1;
        TreeNode *root = buildTree(values);
        int result = maxLevelSum(root);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::optional<int>> values = { 1,7,0,7,-8,std::nullopt,std::nullopt };
        int expected = 2;
        TreeNode *root = buildTree(values);
        int result = maxLevelSum(root);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::optional<int>> values = { 989,std::nullopt,10250,98693,-89388,std::nullopt,std::nullopt,std::nullopt,-32127};
        int expected = 2;
        TreeNode *root = buildTree(values);
        int result = maxLevelSum(root);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::optional<int>> values = { -100,-200,-300,-20,-5,-10,std::nullopt};
        int expected = 3;
        TreeNode *root = buildTree(values);
        int result = maxLevelSum(root);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
