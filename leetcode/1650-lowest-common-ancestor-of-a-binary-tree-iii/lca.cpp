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

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};

Node *pnode;
Node *qnode;

int doWork()
{
    return 1;
}


Node *buildTree(std::vector<std::optional<int>> &nums,
                int p,
                int q)
{
    Node *root = new Node();
    root->val = nums[0].value();
    if( root->val == p )
        pnode = root;
    else if( root->val == q )
        qnode = root;
    int index=1;
    std::queue<Node *> bqueue;
    bqueue.push(root);
    while( index<nums.size())
    {
        Node *curr = bqueue.front();
        bqueue.pop();
        if( nums[index].has_value())
        {
            Node *left = new Node();
            left->val = nums[index].value();
            curr->left = left;
            left->parent = curr;
            bqueue.push(left);
            if( left->val == p )
                pnode = left;
            else if( left->val == q )
                qnode = left;
        }
        index++;
        
        if((index<nums.size()) && ( nums[index].has_value()))
        {
            Node *right = new Node();
            right->val = nums[index].value();
            curr->right = right;
            right->parent = curr;
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


Node* lowestCommonAncestor(Node* p, Node * q)
{
    Node *root;
    std::unordered_set<Node *> pset;
    if( p->parent == nullptr )
        root = p;
    if( q->parent == nullptr )
        root = q;
    
    Node *curr = p;
    while( curr != nullptr )
    {
        pset.insert( curr );
        curr = curr->parent;
    }
    curr = q;
    while( curr != nullptr )
    {
        if( pset.count( curr ))
            return curr;
        curr = curr->parent;
    }
    return root;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "1650-lowest-common-ancestor-of-a-binary-tree-iii" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::optional<int>> nums = {3,5,1,6,2,0,8,std::nullopt,std::nullopt,7,4};
        int p = 5;
        int q = 4;
        Node *root = buildTree(nums,p,q);
        int expected = 5;
        Node* lca = lowestCommonAncestor(pnode, qnode);
        int result = lca->val;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::optional<int>> nums  = {3,5,1,6,2,0,8,std::nullopt,std::nullopt,7,4};
        int p = 5;
        int q = 1;
        Node *root = buildTree(nums,p,q);
        int expected = 3;
        Node* lca = lowestCommonAncestor(pnode, qnode);
        int result = lca->val;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::optional<int>> nums  = {3,5,1,6,2,0,8,std::nullopt,std::nullopt,7,4};
        int p = 5;
        int q = 4;
        Node *root = buildTree(nums,p,q);
        int expected = 5;
        Node* lca = lowestCommonAncestor(pnode, qnode);
        int result = lca->val;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::optional<int>> nums  = {1,2};
        int p = 1;
        int q = 2;
        Node *root = buildTree(nums,p,q);
        int expected = 1;
        Node* lca = lowestCommonAncestor(pnode, qnode);
        int result = lca->val;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
