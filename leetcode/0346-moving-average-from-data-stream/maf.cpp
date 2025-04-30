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
#include <deque>


class MovingAverage
{
public:

    int window_size;
    int rolling_sum;
    std::deque<int> mqueue;

    MovingAverage(int size)
    {
        window_size = size;
        rolling_sum = 0;
    }
    double next(int val)
    {
        rolling_sum += val;
        mqueue.push_back(val);
        if( mqueue.size() > window_size )
        {
            rolling_sum -= mqueue.front();
            mqueue.pop_front();
        }
        return (double) rolling_sum / (double) mqueue.size();
    }
};


int main(int argc, char **argv)
{
    std::cout << std::endl << "0346-moving-average-from-data-stream" << std::endl << std::endl;
    int test_case = 1;
    {
        MovingAverage movingAverage(3);
        double result = movingAverage.next(1);
        double expected = 1.0;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";

        result = movingAverage.next(10);
        expected = 5.5;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";

        result = movingAverage.next(3);
        expected = 4.66667;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";

        result = movingAverage.next(5);
        expected = 6.0;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
