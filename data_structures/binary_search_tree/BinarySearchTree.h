#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include "TreeNode.h"

class BinarySearchTree {

 public:
    BinarySearchTree();

    TreeNode *addValue(int new_value);
    static void inOrderTreeWalk(TreeNode *origin);
    void insertNode(TreeNode *candidate);
    static TreeNode *iterativeTreeSearch(TreeNode *origin, int value);
    static TreeNode *treeMinimum(TreeNode *origin);
    static TreeNode *treeMaximum(TreeNode *origin);
    static TreeNode *treeSearch(TreeNode *origin, int value);
    static TreeNode *treeSuccessor(TreeNode *current);
    TreeNode *root;

 protected:

	
 private:
    
};

#endif
