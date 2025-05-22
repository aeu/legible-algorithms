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
    std::vector<int> candies(ratings.size(),1);
    int total_candies = 0;
    for(int index=1;index<ratings.size();index++)
    {
        if( ratings[index] > ratings[index-1] )
            candies[index] = candies[index-1] + 1 ;
    }

    for(int index=ratings.size()-2;index>=0;index--)
    {
        if( ratings[index] > ratings[index+1] )
        {
            candies[index] = std::max( candies[index], candies[index+1] + 1 );
        }
    }
    for(auto const &curr : candies )
    {
        total_candies += curr;
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
