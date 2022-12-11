// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82


#include <stdio.h>
#include "Board.hpp"

Board::Board (int board_size)
{
  this->board_size = board_size;
}

void Board::dumpBoard()
{
  printf("%d\n", board_size );
}

