#ifndef TREE_NODE
#define TREE_NODE

#include <memory>
class TreeNode {
 public:
    TreeNode();
    int value;
    std::shared_ptr<TreeNode> left;
    std::shared_ptr<TreeNode> right;
    std::shared_ptr<TreeNode> parent;
 protected:
 private:
};

#endif
