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

std::vector<int> getKey(std::string &candidate)
{
    std::vector<int> key;
    if( candidate.length() == 1 )
        key.push_back(26);
    
    for(int index=1;index<candidate.length();index++)
    {
        int delta =  (candidate[index] - candidate[index-1] + 26 ) % 26;
        key.push_back( delta );
    }
    return key;
}


std::vector<std::vector<std::string>> groupStrings(std::vector<std::string>& strings)
{
    std::map<std::vector<int>,std::vector<std::string>> maps;
    for(auto &curr : strings )
    {
        maps[getKey(curr)].push_back(curr);
    }
    std::vector<std::vector<std::string>> retval;
    for( auto [key,strings] : maps )
    {
        retval.push_back(strings);
    }
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0249-group-shifted-strings" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::string> strings = { "abc", "bcd", "acef", "xyz", "az", "ba", "a", "z" };
        std::vector<std::vector<std::string>> expected = {{"acef"},{"a","z"},
                                                          {"abc","bcd","xyz"},{"az","ba"}};

        std::vector<std::vector<std::string>> result = groupStrings(strings);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<std::string> strings = { "a" };
        std::vector<std::vector<std::string>> expected = {{"a"}};
        std::vector<std::vector<std::string>> result = groupStrings(strings);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
