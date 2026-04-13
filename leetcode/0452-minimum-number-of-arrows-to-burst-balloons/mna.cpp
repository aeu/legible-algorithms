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
    // sort all the baloons, using the end of their span as the
    // differentiator.
    std::sort(points.begin(),
              points.end(),
              [](std::vector<int> left, std::vector<int> right)
              {
                  return left[1] < right[1];
              });
    
    int shot_count = 0;
    int arrow_position = 0;
    bool first_time = true;
    // loop through all the balloons
    for(auto current_balloon : points )
    {
        // for the first balloon, shoot at its tail end (this is the
        // last possible point on the baloon and the most optimal choice to
        // intersect with the subsequent balloon).  Note that we store
        // the arrow shot to see if it hits the next balloon 
        if( first_time )
        {
            arrow_position = current_balloon[1];
            shot_count++;
            first_time = false;
        }
        if( ! isPopped( current_balloon, arrow_position ))
        {
            // the current balloon wasn't popped by the last arrow, so
            // we have to shoot another one.
            arrow_position = current_balloon[1];
            shot_count++;
        }
    }
    return shot_count;
}





int main(int argc, char **argv)
{
    std::cout << "Leetcode #452 - Mininum Number of Arrows" << std::endl << std::endl;
    {
        std::cout << std::endl << "Example 1" << std::endl;
        std::vector<std::vector<int>> points =  {{10,16},{2,8},{1,6},{7,12}};
        dumpBalloons( points );
        int min_shot_count = findMinArrowShots(points);
        std::cout << "Min arrow shots : " << min_shot_count << std::endl;
    }
    {
        std::cout << std::endl << "Example 2" << std::endl;
        std::vector<std::vector<int>> points = {{1,2},{3,4},{5,6},{7,8}};
        dumpBalloons( points );
        int min_shot_count = findMinArrowShots(points);
        std::cout << "Min arrow shots : " << min_shot_count << std::endl;
    }
    {
        std::cout << std::endl << "Example 3" << std::endl;
        std::vector<std::vector<int>> points =  {{1,2},{2,3},{3,4},{4,5}};
        dumpBalloons( points );
        int min_shot_count = findMinArrowShots(points);
        std::cout << "Min arrow shots : " << min_shot_count << std::endl;
    }
    return -1;
}
