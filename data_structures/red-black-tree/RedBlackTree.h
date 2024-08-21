#ifndef RedBlackTree_h
#define RedBlackTree_h


#include <stdio.h>
#include <memory>
#include "TreeNode.h"

class RedBlackTree {
    
 public:

    RedBlackTree();
    
    std::shared_ptr<TreeNode> addValue(int new_value);
    std::shared_ptr<TreeNode> maximum(std::shared_ptr<TreeNode> start_node);
    std::shared_ptr<TreeNode> minimum(std::shared_ptr<TreeNode> start_node);
    std::shared_ptr<TreeNode> successor(std::shared_ptr<TreeNode> start_node);
    std::shared_ptr<TreeNode> predecessor(std::shared_ptr<TreeNode> start_node);
    
 protected:

    std::shared_ptr<TreeNode> insert(std::shared_ptr<TreeNode> new_node);

private:

    std::shared_ptr<TreeNode> nilnode;
    std::shared_ptr<TreeNode> root_node;
};


#endif
