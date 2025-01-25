// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <iostream>

int main(int argc, char **argv)
{
  {
    std::vector<std::optional<int>> values = { 3,9,20,std::nullopt,std::nullopt,15,7 };
    dumpValues( values );
    std::shared_ptr<TreeNode> root = buildTree(values);
    dumpTree( root );
  }
  return -1;
}
