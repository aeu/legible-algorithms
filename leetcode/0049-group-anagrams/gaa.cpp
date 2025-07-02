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
#include <unordered_map>
#include <unordered_set>


// anagrams will all sort to the same, so create a vector in a map
// using the sorted as the key

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs)
{
    std::unordered_map<std::string,std::vector<std::string>> gas;
    for(auto current : strs )
    {
        std::string scurrent = current;
        std::sort(scurrent.begin(),scurrent.end());
        gas[scurrent].push_back(current);
    }
    std::vector<std::vector<std::string>> retval;
    for( auto it : gas )
    {
        retval.push_back(it.second);
    }
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << "Leetcode #49 - Group Anagrams" << std::endl;
    int test_case = 1;
    {
    }
    {
    }
    return -1;
}
