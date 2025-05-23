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

std::vector<std::vector<int>> findRLEArray(std::vector<std::vector<int>>& encoded1,
                                           std::vector<std::vector<int>>& encoded2)
{
    std::vector<std::vector<int>> retval;

    bool done = false;

    int e1_index = 0;
    int e1_count = 0;
    int e1_current = 0;

    int e2_index = 0;
    int e2_count = 0;
    int e2_current = 0;

    int prod;
    int prev;
    bool first = true;
    int push_count = 1;
    
    while( ! done )
    {
        if( e1_count == 0 )
        {
            if( e1_index < encoded1.size() )
            {
                const auto &current_pair = encoded1[e1_index];
                e1_current = current_pair[0];
                e1_count   = current_pair[1];
                e1_index++;
            }
        }
        if( e2_count == 0 )
        {
            if( e2_index < encoded2.size() )
            {
                const auto &current_pair = encoded2[e2_index];
                e2_current = current_pair[0];
                e2_count   = current_pair[1];
                e2_index++;
            }
        }

        if(( e1_count != 0 ) && ( e2_count != 0 ))
        {
            prod = e1_current * e2_current;
            if( first == true )
            {
                first = false;
            }
            else if( ( prev == prod ))
            {
                push_count++;
            }
            else
            {
                retval.push_back({ prev,push_count});
                push_count = 1;
            }
            prev = prod;
            e1_count--;
            e2_count--;
        }
        else
        {
            done = true;
        }
    }
    retval.push_back({prod,push_count});
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "1868-product-of-two-run-length-encoded-arrays" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::vector<int>> encoded1 = {{1,3},{2,3}};
        std::vector<std::vector<int>> encoded2 = {{6,3},{3,3}};
        std::vector<std::vector<int>> expected = {{6,6}};
        std::vector<std::vector<int>> result = findRLEArray(encoded1,encoded2);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<std::vector<int>> encoded1 = {{1,3},{2,1},{3,2}};
        std::vector<std::vector<int>> encoded2 = {{2,3},{3,3}};
        std::vector<std::vector<int>> expected = {{2,3},{6,1},{9,2}};
        std::vector<std::vector<int>> result = findRLEArray(encoded1,encoded2);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
