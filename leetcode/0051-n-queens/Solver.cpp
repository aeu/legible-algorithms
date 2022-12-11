// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <stdio.h>
#include "Board.hpp"

int main(int argc, char **argv)
{
  auto fred = new Board(5);
  fred->dumpBoard();
}
