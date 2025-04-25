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


struct CloserToOrigin {
    bool operator()(const std::pair<int,int> &lhs, const std::pair<int,int> &rhs )
    {
        return ((( lhs.first * lhs.first ) + ( lhs.second * lhs.second ))
                > (( rhs.first * rhs.first ) + ( rhs.second * rhs.second )));
    }
};

std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k)
{
    std::priority_queue<std::pair<int,int>,
                        std::vector<std::pair<int,int>>,
                    CloserToOrigin> candidates;
    std::vector<std::vector<int>> retval;

    for(const auto &curr : points )
    {
        candidates.push( { curr[0],curr[1] });
    }
    while( ! candidates.empty() )
    {
        auto top = candidates.top();
        candidates.pop();
        retval.push_back( { top.first, top.second });
        k--;
        if( k == 0 )
            break;
    }
    return retval;
}

int doWork(){ return 1; }

int main(int argc, char **argv)
{
    std::cout << std::endl << "0973-k-closest-points-to-origin" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::vector<int>> points = {{1,3},{-2,2}};
        int k = 1;
        std::vector<std::vector<int>> expected = {{-2,2}};
        std::vector<std::vector<int>> result = kClosest(points,k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<std::vector<int>> points = {{3,3},{5,-1},{-2,4}};
        int k = 2;
        std::vector<std::vector<int>> expected = {{3,3},{-2,4}};
        std::vector<std::vector<int>> result = kClosest(points,k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
