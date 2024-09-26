// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#ifndef RedBlackTree_h
#define RedBlackTree_h


#include <stdio.h>
#include <memory>
#include "TreeNode.h"

class RedBlackTree {
    
public:

    RedBlackTree();
    
    std::shared_ptr<TreeNode> addValue(int new_value);
    std::shared_ptr<TreeNode> find(int value);
    std::shared_ptr<TreeNode> find(std::shared_ptr<TreeNode> start_node, int value);
    void inOrderTreeWalk(std::shared_ptr<TreeNode> start_node);
    std::shared_ptr<TreeNode> leftRotate(std::shared_ptr<TreeNode> start_node);
    std::shared_ptr<TreeNode> rightRotate(std::shared_ptr<TreeNode> start_node);
    
    std::shared_ptr<TreeNode> maximum(std::shared_ptr<TreeNode> start_node);
    std::shared_ptr<TreeNode> minimum(std::shared_ptr<TreeNode> start_node);
    std::shared_ptr<TreeNode> nilNode();
    std::shared_ptr<TreeNode> predecessor(std::shared_ptr<TreeNode> start_node);
    std::shared_ptr<TreeNode> remove(int value);
    std::shared_ptr<TreeNode> successor(std::shared_ptr<TreeNode> start_node);
    std::shared_ptr<TreeNode> root_node;
    
    void dumpDotLine(FILE *fp, std::shared_ptr<TreeNode> start_node);
    void toDotFile(const char *filename, std::shared_ptr<TreeNode> start_node);

protected:

    std::shared_ptr<TreeNode> insert(std::shared_ptr<TreeNode> new_node);

private:

    std::shared_ptr<TreeNode> nilnode;
    bool debug_out;
};


#endif
