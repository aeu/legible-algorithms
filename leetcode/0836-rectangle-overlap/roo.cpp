// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <iostream>
#include <iomanip>
#include <optional>
#include <vector>
#include <queue>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <limits.h>



void dumpValues(std::vector<int> values)
{
    bool first = true;
    for(const auto &curr : values )
    {
        if( ! first )
            std::cout << ", ";
        first = false;
        std::cout << std::setw(3) << curr ;
    }
    std::cout << std::endl;
}


bool inside(int x, int y, std::vector<int> &rect)
{
    dumpValues(rect);
    std::cout << "x: " << x << " y: " << y ; 
    
    if(( x > rect[0] ) && ( x < rect[2] ))
    {
        if( ( y > rect[1] ) && ( y < rect[3] ))
        {
            std::cout << " true" << std::endl;
            return true;
        }
    }
    std::cout << " false" << std::endl;
    return false;
}

// rect is x1,y1, x2, y2
//         0  1   2   3

bool isRectangleOverlap(std::vector<int>& rec1, std::vector<int>& rec2)
{

    if(     ( rec1[0] < rec2[2] )
         && ( rec1[2] > rec2[0] )
         && ( rec1[1] < rec2[3] )
         && ( rec1[3] > rec2[1] ))
    {
        return true;
    }
    return false;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0836-rectangle-overlap" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> rec1  = {7,8,13,15};
        std::vector<int> rec2  = {10,8,12,20};
        bool expected = true;
        bool result = isRectangleOverlap(rec1, rec2);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> rec1  = {0,0,2,2};
        std::vector<int> rec2  = {1,1,3,3};
        bool expected = true;
        bool result = isRectangleOverlap(rec1, rec2);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> rec1  = {0,0,1,1};
        std::vector<int> rec2  = {1,0,2,1};
        bool expected = false;
        bool result = isRectangleOverlap(rec1, rec2);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
