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

std::string longestCommonPrefix(std::vector<std::string>& strs)
{
    std::string retval = "";
    if( strs.size() == 0 )
        return retval;
    
    bool keep_going = true;
    int curr_index = 0;
    while( keep_going )
    {
        if( curr_index > strs[0].length() )
            break;
        char cchar = strs[0][curr_index];
        for(const auto &cstring : strs )
        {
            if(( curr_index < cstring.length() ) && ( cstring[curr_index] == cchar ))
            {
            }
            else
            {
                keep_going = false;
                break;
            }
        }
        if( keep_going )
        {
            retval.push_back(cchar);
            curr_index++;
        }
    }
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0014-longest-common-prefix" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::string> strings  = {"flower","flow","flight"};
        std::string expected = "fl";
        std::string result = longestCommonPrefix(strings);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::string> strings  = {"dog","racecar","car"};
        std::string expected = "";
        std::string result = longestCommonPrefix(strings);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
