// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <stdio.h>
#include <vector>
#include "extra.h"

int getHeightFromPosition(std::vector<std::vector<char> > &data, int row, int col)
{
    int height_at_position = 0;
    auto num_rows = data.size();
    std::vector<char> current_row;
    for(auto row_index = row; row_index < num_rows; row_index++ )
    {
        current_row = data[row_index];
        if( current_row[ col ] == '1' )
            height_at_position++;
        else
            break;
    }
    return height_at_position;
}

void doWork(std::vector<std::vector<char> > &data)
{
    auto num_rows = data.size();
    auto num_columns = data[0].size();
    auto row_index = 0;
    auto col_index = 0;
    
    printf("in do work, got data with %lu rows of %lu columns\n", num_rows, num_columns);
    std::vector<char> current_row;
    for(row_index=0; row_index< num_rows; row_index++)
    {
        current_row = data[row_index];
        for(col_index = 0; col_index < num_columns; col_index++ )
        {
            int height_at_position = getHeightFromPosition( data, row_index, col_index);
            printf("(%d,%d) = %c, height: %d\n", row_index,col_index,current_row[col_index], height_at_position);
        }
        printf("\n");
    }
}

int main(int argc, char **argv)
{
    printf("starting\n");
    std::vector<std::vector<char> > data =
        {{'1','0','1','0','0'},
         {'1','0','1','1','1'},
         {'1','1','1','1','1'},
         {'1','0','0','1','0'}};
    doWork( data );
}
