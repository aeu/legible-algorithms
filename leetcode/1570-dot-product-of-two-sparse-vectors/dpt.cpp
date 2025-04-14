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


class SparseVector {
public:

    std::unordered_map<int,int> values;
    
    SparseVector(std::vector<int> &nums)
    {
        for(int index = 0;index<nums.size();index++)
        {
            values[index] = nums[index];
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec)
    {
        int retval = 0;
        for(auto mine : values )
        {
            auto thine = vec.values.find( mine.first );
            if( thine != vec.values.end() )
            {
                retval += ( mine.second * thine->second );
            }
        }
        return retval;
    }
};


int doWork()
{
    return 0;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "1570-dot-product-of-two-sparse-vectors" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {1,2,3};
        int expected = 0;
        int result = doWork();
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
