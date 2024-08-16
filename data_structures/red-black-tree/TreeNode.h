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

 protected:
 private:

    NodeColour colour;
    int value;
    std::shared_ptr<TreeNode> left;
    std::shared_ptr<TreeNode> right;
    std::shared_ptr<TreeNode> parent;
    
};

#endif
