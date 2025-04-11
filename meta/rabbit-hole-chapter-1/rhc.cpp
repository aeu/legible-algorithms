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


int dfs(int start_point,
        std::vector<int> &L,
        std::vector<int> &seen,
        std::unordered_map<int,int> &memo)
{
    if( memo.find( start_point) != memo.end() )
        return memo[start_point];

    int next_page = L[start_point-1];
    if( seen[next_page] )
        return 1;
    
    seen[next_page] = 1;
    int count = 1 + dfs(next_page,L,seen,memo);

    memo[start_point] = count;
    return count;
}

int getMaxVisitableWebpages(int N, std::vector<int> L)
{
    int max_visitable = INT_MIN;
    for(int index=1;index<L.size()+1;index++)
    {
        std::unordered_map<int,int> memo;
        std::vector<int> seen(L.size()+1,0);
        seen[index] = 1;
        int current_max = dfs(index,L,seen,memo);
        max_visitable = std::max(max_visitable, current_max );
    }
    return max_visitable;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "Meta Puzzles - Rabbit Hole (Chapter 1)" << std::endl << std::endl;
    int test_case = 1;
    {
        int N = 4;
        std::vector<int> L = {4,1,2,1};
        int expected = 4;
        int result = getMaxVisitableWebpages(N, L);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        int N = 5;
        std::vector<int> L = {4,3,5,1,2};
        int expected = 3;
        int result = getMaxVisitableWebpages(N, L);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        int N = 5;
        std::vector<int> L = {2,4,2,2,3};
        int expected = 4;
        int result = getMaxVisitableWebpages(N, L);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
