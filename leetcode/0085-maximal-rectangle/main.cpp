// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <stdio.h>
#include <vector>

int getHeightFromPosition(std::vector<std::vector<char> > &data, int row, int col)
{
    int height_at_position = 0;
    unsigned int num_rows = data.size();
    std::vector<char> current_row;
    for(unsigned int row_index = row; row_index < num_rows; row_index++ )
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
    unsigned int num_rows = data.size();
    unsigned int num_columns = data[0].size();
    unsigned int row_index = 0;
    unsigned int col_index = 0;
    unsigned int max_area = 0;
    std::vector<char> current_row;
    
    for(row_index=0; row_index< num_rows; row_index++)
    {
        current_row = data[row_index];
        for(col_index = 0; col_index < num_columns; col_index++ )
        {
            char current_cell = current_row[col_index];
            if( current_cell == '1' )
            {
                unsigned int rectangle_col_index = col_index;
                unsigned int rectangle_width = 1;
                unsigned int rectangle_area = 0;
                unsigned int rectangle_height = getHeightFromPosition( data, row_index, rectangle_col_index);
                rectangle_col_index++;
                if( rectangle_col_index < num_columns )
                {
                    char next_over = current_row[rectangle_col_index];
                    while(next_over == '1' )
                    {
                        rectangle_width++;
                        unsigned int next_height = getHeightFromPosition( data, row_index, rectangle_col_index);
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
            }
        }
    }
    printf("\nLargest area was %d\n\n\n", max_area );
}

void dumpMatrix(std::vector<std::vector<char> > &data)
{
    unsigned int num_rows = data.size();
    unsigned int num_columns = data[0].size();
    unsigned int row_index = 0;
    unsigned int col_index = 0;
    
    std::vector<char> current_row;
    for(row_index=0; row_index< num_rows; row_index++)
    {
        current_row = data[row_index];
        for(col_index = 0; col_index < num_columns; col_index++ )
        {
            printf("%c", current_row[col_index]);
        }
        printf("\n");
    }

}


int main(int argc, char **argv)
{
    printf("Legible Algorithms - Leetcode 0085 Maximal Rectangle\n");
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
