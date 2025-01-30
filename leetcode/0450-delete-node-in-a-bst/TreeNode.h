// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <memory>
#include <optional>
#include <queue>
#include <iostream>

/**struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class TreeNode
{
public:
    std::shared_ptr<TreeNode> getLeft();
    std::shared_ptr<TreeNode> getRight();
    std::shared_ptr<TreeNode> setLeft(std::shared_ptr<TreeNode> new_left);
    std::shared_ptr<TreeNode> setRight(std::shared_ptr<TreeNode> new_right);
    void setValue(const int new_value);
    int getValue();
    TreeNode(const int new_value);
    TreeNode(const int new_value,
             std::shared_ptr<TreeNode> new_left,
             std::shared_ptr<TreeNode> new_right);

    static void dumpNode(std::shared_ptr<TreeNode> current_node );
    static void dumpTree(std::shared_ptr<TreeNode> current_node );
    static std::shared_ptr<TreeNode> buildTree(const std::vector<std::optional<int>> &values);
    
    TreeNode();
    
protected:
private:

    std::shared_ptr<TreeNode> left;
    std::shared_ptr<TreeNode> right;
    int value;
};
