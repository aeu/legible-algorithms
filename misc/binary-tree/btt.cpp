// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <iostream>
#include <optional>
#include <vector>
#include "TreeNode.h"

void dumpValues(const std::vector<std::optional<int>> &values)
{
    bool first_time = true;
    std::cout << "[" ;
    for( auto current : values )
    {
        if( ! first_time )
            std::cout << ", " ;
        if( current.has_value() )
            std::cout << current.value();
        else
            std::cout << "null";
        first_time = false;
    }
    std::cout << "]" << std::endl;
}


int main(int argc, char **argv)
{
    {
        std::vector<std::optional<int>> values = { 3,9,20,std::nullopt,std::nullopt,15,7 };
        dumpValues( values );
        std::shared_ptr<TreeNode> root = TreeNode::buildTree(values);
        TreeNode::dumpTree( root );
    }
    return -1;
}
