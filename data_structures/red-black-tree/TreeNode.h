// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#ifndef TreeNode_h
#define TreeNode_h


#include <memory>

class TreeNode
{
public:

    typedef enum {
                  RED,
                  BLACK,
    } NodeColour;
    
    TreeNode(int new_value);
    NodeColour getColour();
    NodeColour setColour(NodeColour new_colour);
    int getValue();
    std::shared_ptr<TreeNode> getLeft();
    std::shared_ptr<TreeNode> getRight();
    std::shared_ptr<TreeNode> getParent();
    std::shared_ptr<TreeNode> setLeft(std::shared_ptr<TreeNode> new_left);
    std::shared_ptr<TreeNode> setRight(std::shared_ptr<TreeNode> new_right);
    std::shared_ptr<TreeNode> setParent(std::shared_ptr<TreeNode> new_parent);
    int setValue(int new_value);

protected:
private:

    NodeColour colour;
    int value;
    std::shared_ptr<TreeNode> left;
    std::shared_ptr<TreeNode> right;
    std::shared_ptr<TreeNode> parent;
    
};

#endif
