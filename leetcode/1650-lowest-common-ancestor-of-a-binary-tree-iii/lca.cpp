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
    return root;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "1650-lowest-common-ancestor-of-a-binary-tree-iii" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::optional<int>> nums  = {3,5,1,6,2,0,8,std::nullopt,std::nullopt,7,4};
        int p = 5;
        int q = 1;
        int expected = 3;
        int result = doWork();
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
