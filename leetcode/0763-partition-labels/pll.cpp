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

std::vector<int> partitionLabels(std::string s)
{
    std::vector<int> retval;
    std::unordered_map<char,int> last_occurrence;
    for(int index=0;index<s.size();index++)
    {
        char current = s[index];
        last_occurrence[current] = index;
    }
    int furthest_char = 0;
    for(int index=0;index<s.size();index++)
    {
        char current = s[index];
        furthest_char = std::max( furthest_char, last_occurrence[current] );
        std::cout << "last occurrence of " << current << ", at index " << index << " is " << last_occurrence[current] << std::endl;
        std::cout << "The furthest distance of any char seen to date is " << furthest_char << std::endl;
        if( index == furthest_char )
        {
            std::cout << "\t index == furthest_char == " << index << std::endl;
        }
    }
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string s = "ababcbacadefegdehijhklij";
        std::vector<int> expected  = {9,7,8};
        std::vector<int> result = partitionLabels(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::string s = "eccbbbbdec";
        std::vector<int> expected  = {10};
        std::vector<int> result = partitionLabels(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
