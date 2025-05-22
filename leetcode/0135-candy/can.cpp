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

int candy(std::vector<int> ratings)
{
    int total_candies = ratings.size();

    for(size_t index=0;index<ratings.size();index++)
    {
        if( index == 0 )
        {
            if( ratings[index] > ratings[index+1] )
                total_candies++;
        }
        if( index == ratings.size() -1 )
        {
            if( ratings[index] > ratings[index-1] )
                total_candies++;
        }
        else if( ( ratings[index] > ratings[index-1] ) || ( ratings[index] > ratings[index+1] ))
            total_candies++;
    }
    return total_candies;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0135-candy" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> ratings = { 1, 0, 2 };
        int expected = 5;
        int result = candy(ratings);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> ratings = { 1, 2, 2 };
        int expected = 4;
        int result = candy(ratings);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> ratings = { 1, 2, 87, 87, 87, 2, 1 };
        int expected = 13;
        int result = candy(ratings);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
