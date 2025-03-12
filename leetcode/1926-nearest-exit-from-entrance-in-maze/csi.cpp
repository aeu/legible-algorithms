// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82
//
#include <stdio.h>
#include <limits.h>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>

std::pair<int,int> getNorth(std::pair<int,int> current, std::vector<std::vector<char>> &maze)
{
    
}
std::pair<int,int> getSouth(std::pair<int,int> current, std::vector<std::vector<char>> &maze)
{
    
}
std::pair<int,int> getNorth(std::pair<int,int> current, std::vector<std::vector<char>> &maze)
{
    
}
std::pair<int,int> getNorth(std::pair<int,int> current, std::vector<std::vector<char>> &maze)
{
    
}


int nearestExit(std::vector<std::vector<char>> &maze,
                std::vector<int> &entrance)
{
    int nearest_exit  = 0;
    return nearest_exit;
    std::unordered_set<std::pair<int,int>> visited;

}


int main(int argc, char **argv)
{
    int test_case = 1;
    {
        std::vector<std::vector<char>> maze = 
        {{'+','+','.','+'},
         {'.','.','.','+'},
         {'+','+','+','.'}};
        std::vector<int> entrance = {1,2};
        int expected = 1;
        int result = nearestExit(maze,entrance);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail") 
                  << " (expected " << expected << ", got " << result << ")\n";
    }
}
