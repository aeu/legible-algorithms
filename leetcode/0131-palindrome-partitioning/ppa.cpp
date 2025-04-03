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
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <limits.h>

int doWork()
{
    return 1;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "LC 131 - Palindrome Partitioning" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string s = "aab";
        std::vector<std::string> expected = {{"a","a","b"},{"aa","b"}};
        std::vector<std::string> result = partition(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
