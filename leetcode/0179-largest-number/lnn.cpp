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

struct scomp
{
    bool operator()(const std::string &lhs, const std::string &rhs)
    {
        return lhs + rhs < rhs + lhs;
    }
};


std::string largestNumber(std::vector<int> &nums)
{
    std::string retval = "";
    std::priority_queue<std::string, std::vector<std::string>, scomp> numbers;
    for(const auto curr : nums )
    {
        std::string curr_as_string = std::to_string(curr);
        numbers.push(curr_as_string);
    }
    while( ! numbers.empty() )
    {
        std::string top = numbers.top();
        numbers.pop();
        retval += top;
    }
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0179-largest-number" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {10,2};
        std::string expected = "210";
        std::string result = largestNumber(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> nums  = {3,30,34,5,9};
        std::string expected = "9534330";
        std::string result = largestNumber(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
