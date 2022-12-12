// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82


#include <string>


class Board {
    
public:
    Board(const int board_size);
    Board(const int board_size, const::std::string board_description);
    void dumpBoard();
    const bool coordinatesAreValid(const int row, const int column);
    const bool isNQueensSolution();
    const char getPieceAtPosition(const int row, const int column);
    
    const int countQueensNorthEast(int row, int column);
    const int countQueensNorthWest(int row, int column);
    const int countQueensSouthWest(int row, int column);
    const int countQueensSouthEast(int row, int column);
    
protected:
private:
    
    int board_size;
    std::string definition;
};
