// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <iostream>
#include <optional>
#include <vector>
#include <queue>
#include <map>
#include <stack>


#if 0

#endif

void dumpBalloons(std::vector<std::vector<int>> &points)
{
    bool first_time = true;
    for(auto baloon : points )
    {
        if( ! first_time )
            std::cout << ", " ;
        std::cout << "{" << baloon[0] << ", " << baloon[1] << "}";
        first_time = false;
    }
    std::cout << std::endl;
}

bool isPopped(std::vector<int> balloon, int y_position)
{
    if(( balloon[0] <= y_position ) && ( balloon[1] >= y_position ))
        return true;
    return false;
}

int findMinArrowShots(std::vector<std::vector<int>>& points)
{
    std::sort(points.begin(),
              points.end(),
              [](std::vector<int> left, std::vector<int> right)
              {
                  return left[1] < right[1];
              });
    
    int arrow_shots = 0;
    int arrow_y = 0;
    bool first_time = true;
    for(auto current_balloon : points )
    {
        if( first_time )
        {
            arrow_y = current_balloon[1];
            arrow_shots++;
            first_time = false;
        }
        if( ! isPopped( current_balloon, arrow_y ))
        {
            arrow_y = current_balloon[1];
            arrow_shots++;
        }
    }
    return arrow_shots;
}





int main(int argc, char **argv)
{
    std::cout << "Leetcode #452 - Mininum Number of Arrows" << std::endl << std::endl;
    {
        std::cout << std::endl << "Example 1" << std::endl;
        std::vector<std::vector<int>> points =  {{10,16},{2,8},{1,6},{7,12}};
        dumpBalloons( points );
        int min_arrow_shots = findMinArrowShots(points);
        std::cout << "Min arrow shots : " << min_arrow_shots << std::endl;
    }
    {
        std::cout << std::endl << "Example 2" << std::endl;
        std::vector<std::vector<int>> points = {{1,2},{3,4},{5,6},{7,8}};
        dumpBalloons( points );
        int min_arrow_shots = findMinArrowShots(points);
        std::cout << "Min arrow shots : " << min_arrow_shots << std::endl;
    }
    {
        std::cout << std::endl << "Example 3" << std::endl;
        std::vector<std::vector<int>> points =  {{1,2},{2,3},{3,4},{4,5}};
        dumpBalloons( points );
        int min_arrow_shots = findMinArrowShots(points);
        std::cout << "Min arrow shots : " << min_arrow_shots << std::endl;
    }
    return -1;
}
