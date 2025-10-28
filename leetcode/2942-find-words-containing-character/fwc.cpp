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


std::vector<int> findWordsContaining(std::vector<std::string>& words, char x)
{
    std::vector<int> retval;
    for(int index=0;index<words.size();index++)
    {
        if( words[index].find(x) != std::string::npos )
            retval.push_back(index);
    }
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "2942-find-words-containing-character" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {1,2,3};
        int expected = 0;
        int result = 0;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
