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
 

TreeNode *buildTree(std::vector<std::optional<int>> &nums)
{
    TreeNode *root = new TreeNode(nums[0].value());
    std::queue<TreeNode *> bqueue;
    bqueue.push(root);
    int index=1;
    while( index < nums.size() )
    {
        TreeNode *curr = bqueue.front();
        bqueue.pop();
        if( nums[index].has_value())
        {
            TreeNode *left = new TreeNode(nums[index].value() );
            curr->left = left;
            bqueue.push( left );
        }
        index++;
        if(( index < nums.size()) && ( nums[index].has_value()))
        {
            TreeNode *right = new TreeNode(nums[index].value());
            curr->right = right;
            bqueue.push(right);
        }
        index++;
    }
    return root;
}


struct tpos {
    int val;
    int depth;
    int pcol;
};


static bool tposcomp( const tpos &lhs, const tpos &rhs )
{
    if( lhs.depth < rhs.depth )
        return true;
    if( lhs.depth == rhs.depth )
        if( lhs.pcol < rhs.pcol )
            return true;
    return false;
}


void dfs(TreeNode *root, int depth, int pcol, int col,
         std::map<int,std::vector<tpos>> &out)
{
    if( root == nullptr )
        return;

    out[col].push_back({root->val,depth,pcol});
    
    dfs(root->left,  depth+1, col, col-1, out);
    dfs(root->right, depth+1, col, col+1, out);

    return;
}

std::vector<std::vector<int>> verticalOrder(TreeNode* root)
{
    std::map<int,std::vector<tpos>> out;
    std::vector<std::vector<int>> retval;
    dfs(root, 0, 0, 0, out );

    for(auto curr  : out )
    {
        std::sort( curr.second.begin(), curr.second.end(), tposcomp );
        std::vector<int> ilist;
        for( auto inner : curr.second )
        {
            ilist.push_back(inner.val);
        }
        retval.push_back(ilist);
    }
    
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0314-binary-tree-vertical-order-traversal" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::optional<int>> nums = {3,9,20,std::nullopt,std::nullopt,15,7};
        std::vector<std::vector<int>> expected = {{9},{3,15},{20},{7}};
        TreeNode *root = buildTree(nums);
        std::vector<std::vector<int>> result = verticalOrder(root);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<std::optional<int>> nums = {3,9,8,4,0,1,7};
        std::vector<std::vector<int>> expected = {{4},{9},{3,0,1},{8},{7}};
        TreeNode *root = buildTree(nums);
        std::vector<std::vector<int>> result = verticalOrder(root);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<std::optional<int>> nums =
            {1,2,3,4,10,9,11,std::nullopt,5,
             std::nullopt,std::nullopt,std::nullopt,std::nullopt,std::nullopt,std::nullopt,std::nullopt,6};
        std::vector<std::vector<int>> expected = {{4},{2,5},{1,10,9,6},{3},{11}};
        TreeNode *root = buildTree(nums);
        std::vector<std::vector<int>> result = verticalOrder(root);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
