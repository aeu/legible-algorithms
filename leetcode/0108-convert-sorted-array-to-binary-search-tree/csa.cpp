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

void dumpNodesWithRange(std::vector<int> nums, int start, int end)
{
    bool first = true;
    for(int index=start;index<end;index++)
    {
        if( ! first )
            std::cout << " ";
        first = false;
        std::cout << nums[index];
    }
    std::cout << std::endl;
}


TreeNode *buildNode(std::vector<int> &nums, int start_index, int end_index)
{
    int middle = start_index + ( ( end_index - start_index) / 2);
    TreeNode *center = new TreeNode( nums[middle]);
    if(( middle - start_index ) >= 1 )
        center->left = buildNode( nums, start_index, middle-1 );
    if(( end_index - middle ) >= 1 )
        center->right = buildNode( nums, middle+1, end_index  );
    return center;
}


// since the array is sorted, we know that the middle number of the array 
// would be the root of the tree.  So we solve this by recursivly finding the 
// middle of the nums array and then calling the helper function with the left
// and right sides of the array

TreeNode* sortedArrayToBST(std::vector<int>& nums) 
{
    TreeNode *root = buildNode(nums,0,nums.size()-1);
    return root;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "0108-convert-sorted-array-to-binary-search-tree" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {-10,-3,0,5,9};
        int expected = 0;
        int result = 0;
        TreeNode *root = sortedArrayToBST(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
