#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include "TreeNode.h"

class BinarySearchTree {

 public:
    BinarySearchTree();
    void addValue(int new_value);
    void insertNode(TreeNode *candidate);
    static void inOrderTreeWalk(TreeNode *origin);
    static TreeNode *treeSearch(TreeNode *origin, int value);
    
    TreeNode *root;

 protected:

	
 private:
    
};

#endif
