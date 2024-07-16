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
    auto max_area = 0;
    printf("in do work, got data with %lu rows of %lu columns\n", num_rows, num_columns);
    std::vector<char> current_row;
    for(row_index=0; row_index< num_rows; row_index++)
    {
        current_row = data[row_index];
        for(col_index = 0; col_index < num_columns; col_index++ )
        {
            char current_cell = current_row[col_index];
            if( current_cell == '1' )
            {
                auto rectangle_col_index = col_index;
                auto rectangle_width = 1;
                auto rectangle_area = 0;
                auto rectangle_height = getHeightFromPosition( data, row_index, rectangle_col_index);
                printf("rect found at (%d,%d) \n", row_index,rectangle_col_index);
                rectangle_col_index++;
                if( rectangle_col_index < num_columns )
                {
                    char next_over = current_row[rectangle_col_index];
                    while(next_over == '1' )
                    {
                        rectangle_width++;
                        auto next_height = getHeightFromPosition( data, row_index, rectangle_col_index);
                        if( next_height < rectangle_height )
                            rectangle_height = next_height;
                        rectangle_col_index++;
                        if( rectangle_col_index < num_columns )
                            next_over = current_row[rectangle_col_index];
                        else
                            next_over = '0';
                    }
                }
                rectangle_area = rectangle_width * rectangle_height;
                if( rectangle_area > max_area )
                    max_area = rectangle_area;
                printf("\twidth: %d, height: %d, area: %d\n",
                       rectangle_width,
                       rectangle_height,
                       rectangle_area);
            }
        }
        printf("\n");
    }
    printf("largest area was %d\n", max_area );
}

void dumpMatrix(std::vector<std::vector<char> > &data)
{
    auto num_rows = data.size();
    auto num_columns = data[0].size();
    auto row_index = 0;
    auto col_index = 0;
    
    std::vector<char> current_row;
    for(row_index=0; row_index< num_rows; row_index++)
    {
        current_row = data[row_index];
        for(col_index = 0; col_index < num_columns; col_index++ )
        {
            printf("%c ", current_row[col_index]);
        }
        printf("\n");
    }

}


int main(int argc, char **argv)
{
    printf("starting\n");
    {
        std::vector<std::vector<char> > data =
            {{'1','0','1','0','0'},
             {'1','0','1','1','1'},
             {'1','1','1','1','1'},
             {'1','0','0','1','0'}};
        dumpMatrix( data );
        doWork( data );
    }
    {
        std::vector<std::vector<char> > data =
            {{'1','0','1','0','0'},
             {'1','0','1','1','1'},
             {'1','1','1','1','1'},
             {'1','1','1','1','1'},
             {'1','0','0','1','0'}};
        dumpMatrix( data );
        doWork( data );
    }
}
