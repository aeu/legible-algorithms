#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE
#include <memory>
#include "TreeNode.h"

class BinarySearchTree {

 public:
    BinarySearchTree();

    std::shared_ptr<TreeNode> addValue(int new_value);
    static void inOrderTreeWalk(std::shared_ptr<TreeNode> origin);
    void insertNode(std::shared_ptr<TreeNode> candidate);
    std::shared_ptr<TreeNode> removeNode(std::shared_ptr<TreeNode> candidate);
    static std::shared_ptr<TreeNode> iterativeTreeSearch(std::shared_ptr<TreeNode> origin, int value);
    static std::shared_ptr<TreeNode> treeMinimum(std::shared_ptr<TreeNode> origin);
    static std::shared_ptr<TreeNode> treeMaximum(std::shared_ptr<TreeNode> origin);
    static std::shared_ptr<TreeNode> treeSearch(std::shared_ptr<TreeNode> origin, int value);
    static std::shared_ptr<TreeNode> treePredecessor(std::shared_ptr<TreeNode> current);
    static std::shared_ptr<TreeNode> treeSuccessor(std::shared_ptr<TreeNode> current);
    std::shared_ptr<TreeNode> root;

 protected:

	
 private:
    
};

#endif
