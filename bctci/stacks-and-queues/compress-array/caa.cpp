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
#include <deque>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <limits.h>

void dumpValues(std::vector<int> values)
{
    for(auto current : values )
        std::cout << current << ", ";
    std::cout << std::endl;
}

std::vector<int> doWork(std::vector<int> &arr)
{
    bool did_compress = false;
    std::vector<int> retval(arr);
    std::deque<int> compression_queue;
    while(true)
    {
        did_compress = false;
        for(auto current : retval )
        {
            if( compression_queue.empty() )
            {
                compression_queue.push_front(current );
                continue;
            }
            int top = compression_queue.front() ;
            if( top == current )
            {
                compression_queue.pop_front();
                compression_queue.push_front( current * 2 );
                did_compress = true;
            }
            else
            {
                compression_queue.push_front( current );
            }
        }
        retval.clear();
        for (auto it = compression_queue.rbegin(); it != compression_queue.rend(); ++it)
        {
            retval.push_back(*it);
        }
        compression_queue.clear();
        if( did_compress == false )
            break;
    }
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "32.1 Compress Array" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> arr      = {8,4,2,2,2,4};
        std::vector<int> expected = {16,2,4};
        std::vector<int> result   = doWork(arr);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        //        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> arr      = {4,4,4,4};
        std::vector<int> expected = {16};
        std::vector<int> result   = doWork(arr);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        //        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> arr      = {1,2,3,4};
        std::vector<int> expected = {1,2,3,4};
        std::vector<int> result   = doWork(arr);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        //        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
