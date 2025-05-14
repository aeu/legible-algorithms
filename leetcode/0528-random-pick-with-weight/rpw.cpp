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

class Solution {
public:

    std::vector<int> prefix;
    
    Solution(std::vector<int>& w)
    {
        int running_sum = 0;
        for(auto const &curr: w )
        {
            running_sum += curr;
            prefix.push_back(running_sum);
        }
    }
    
    int pickIndex()
    {
        int random = rand() % prefix.back() + 1 ;
        int index = std::lower_bound(prefix.begin(), prefix.end(), random ) - prefix.begin();
        return index;
    }
};

int main(int argc, char **argv)
{
    srand(time(NULL));
    std::cout << std::endl << "" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums = {1,3};
        Solution *solution = new Solution(nums);
        std::cout << solution->pickIndex() << std::endl; // return 1. It is returning the second element (index = 1) that has a probability of 3/4.
        std::cout << solution->pickIndex() << std::endl; // return 1
        std::cout << solution->pickIndex() << std::endl; // return 1
        std::cout << solution->pickIndex() << std::endl; // return 1
        std::cout << solution->pickIndex() << std::endl; // return 0. It is returning the first element (index = 0) that has a probability of 1/4.
    }
    return 0;
}
