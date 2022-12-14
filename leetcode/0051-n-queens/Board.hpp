// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82


#include <string>

typedef struct BoardPosition {
    int row;
    int column;
} BoardPosition;

class Board {
    
public:
    Board(const int board_size);
    Board(const int board_size, const::std::string board_description);
    void dumpBoard();
    const bool coordinatesAreValid(const int row, const int column);
    const bool isNQueensSolution();
    const char getPieceAtPosition(const int row, const int column);
    
    const int countQueensWithDirection(int row, int column, std::function<BoardPosition(int, int)> direction);
    
protected:
private:
    
    int board_size;
    std::string definition;
};
