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

class Node {
public:
    int val;
    Node* left;
    Node* right;
    
    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};


void dumpNodeList(std::vector<Node *> values)
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


Node *buildTree(std::vector<std::optional<int>> tree_values)
{
    Node *root = new Node(tree_values[0].value());
    std::queue<Node *>bqueue;
    int index=1;
    bqueue.push(root);
    while( index < tree_values.size() )
    {
        Node *curr = bqueue.front();
        bqueue.pop();
        if( tree_values[index].has_value() )
        {
            Node *left = new Node( tree_values[index].value() );
            curr->left = left;
            bqueue.push(left);
        }
        index++;
        if( ( index < tree_values.size() ) && ( tree_values[index].has_value() ))
        {
            Node *right = new Node( tree_values[index].value() );
            curr->right = right;
            bqueue.push(right);
        }
        index++;
    }
    return root;
}



void dfs(Node *root,
         Node * &prev,
         Node * &head)
{
    if( root == nullptr )
        return;

    if( root->left != nullptr )
        dfs(root->left,prev,head);

    if( prev )
    {
        // we are thinking of the node as right -> next and left ->
        // previous.  "prev" is currently set to the node that made
        // this dfs call, so we are setting it's right to ourself, and
        // then setting our left to prev
        prev->right = root;
        root->left = prev;
    }
    else
    {
        // prev is null, so this is the first node in in-order
        // traversal, so we set the head to the current node, which
        // must be the root node.
        head = root;
    }
    // set prev to the node we just got called in with, think of this
    // as pushing the last element onto the path (if we were using a path based
    // approach
    prev = root;

    if( root->right != nullptr )
        dfs(root->right,prev,head);

}

Node *treeToDoublyList(Node *root)
{
    if( root == nullptr )
        return nullptr;
    Node *prev = nullptr;
    Node *head = nullptr;
    dfs(root,prev,head);
    head->left = prev;
    prev->right = head;
    return head;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "0426-convert-binary-search-tree-to-sorted-doubly-linked-list" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::optional<int>> nums  = {4,2,5,1,3};
        Node *root = buildTree(nums);
        treeToDoublyList(root);
        int expected = 0;
        int result = 0;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
