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

struct Bucket {
    bool used;
    int bucket_min;
    int bucket_max;
};

int maximumGap(std::vector<int>& nums)
{
    int N = nums.size();
    if( N < 2 )
        return 0;
    
    int min_element = INT_MAX;
    int max_element = INT_MIN;
    for( auto curr : nums )
    {
        min_element = std::min( min_element, curr );
        max_element = std::max( max_element, curr );
    }
    int bucket_size = std::max(1, ( max_element - min_element ) / ( N - 1 ));
    int bucket_count = (( max_element - min_element ) / bucket_size ) + 1;
    
    std::vector<Bucket> buckets( bucket_count, { false,INT_MAX,INT_MIN });

    for( auto curr: nums )
    {
        int bucket_index = ( curr - min_element ) / bucket_size;
        buckets[bucket_index].used = true;
        buckets[bucket_index].bucket_min = std::min( buckets[bucket_index].bucket_min, curr );
        buckets[bucket_index].bucket_max = std::max( buckets[bucket_index].bucket_max, curr );
    }

    int max_gap = 0;
    int prev_max = min_element;
    
    for( const auto &current_bucket : buckets )
    {
        if( current_bucket.used == false )
            continue;
        max_gap = std::max( max_gap, current_bucket.bucket_min - prev_max );
        prev_max = current_bucket.bucket_max;
    }
    return max_gap;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "leetcode/0164-maximum-gap/" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {3,6,9,1};
        int expected = 3;
        int result = maximumGap(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> nums  = {10};
        int expected = 0;
        int result = maximumGap(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> nums  = {0,10,25,12};
        int expected = 13;
        int result = maximumGap(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
