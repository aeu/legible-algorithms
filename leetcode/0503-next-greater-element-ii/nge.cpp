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


// this is exactly the same as next greater element, except that the
// array is circular.  to simulate a circular array we can either
// duplicate it, or do this one weird trick to loop over it double but
// index the modulo.
std::vector<int> nextGreaterElements(std::vector<int>& nums)
{
    std::vector<int> retval( nums.size(), -1 );
    std::stack<int> mstack;
    int N = nums.size();
    
    for(int index = ( N * 2 ) -1 ; index >= 0 ; index--)
    {
        int current = nums[index%N];
        while(( ! mstack.empty() ) && ( mstack.top() <= current ))
        {
            mstack.pop();
        }
        // we are only populating half the range of index (as it was doubled)
        if( index < N )
        {
            if( ! mstack.empty() )
                retval[index] = mstack.top();
        }
        mstack.push( current );
    }
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0503-next-greater-element-ii" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {1,2,1};
        std::vector<int> expected = { 2,-1,2 };
        std::vector<int> result = nextGreaterElements(nums);
        dumpValues(result);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> nums  = {1,2,3,4,3};
        std::vector<int> expected = {2,3,4,-1,4};
        std::vector<int> result = nextGreaterElements(nums);
        dumpValues(result);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
