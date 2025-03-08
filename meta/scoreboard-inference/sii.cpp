// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <vector>
#include <iostream>
#include <unordered_map>
#include <map>
#include <queue>
#include <set>

using namespace std;

int getMinProblemCount(int N, vector<int> &S)
{
    int min_problem_count = 0;
    int running_score = 0;
    std::sort(S.begin(),S.end());
    for(auto current : S )
    {
        if( current == running_score )
            continue;

        int gap = current - running_score;
        if( gap > 2 )
        {
            int num_twos = gap / 2;
            running_score += num_twos * 2;
            min_problem_count += num_twos;
        }       
        if((( running_score + 2 ) == current )
           || ( running_score + 1 ) == current )
        {
            min_problem_count++;
            running_score = current;
            continue;
        }
    }
    return min_problem_count;
}

int main(int argc, char **argv)
{
    {
        int N = 6;
        int expected = 4;
        std::vector<int> S = { 1,2,3,4,5,6 };
        int answer = getMinProblemCount(N,S);

        if( answer == expected )
            std::cout << "pass" << std::endl;
        else
            std::cout << "fail, retval should be " << expected << " you returned : " << answer << std::endl;
    }
    {
        int N = 4;
        int expected = 3;
            std::vector<int> S = { 4,3,3,4};
        int answer = getMinProblemCount(N,S);

        if( answer == expected )
            std::cout << "pass" << std::endl;
        else
            std::cout << "fail, retval should be " << expected << " you returned : " << answer << std::endl;
    }
    {
        int N = 4;
        int expected = 4;
        std::vector<int> S = { 2,4,6,8};
        int answer = getMinProblemCount(N,S);

        if( answer == expected )
            std::cout << "pass" << std::endl;
        else
            std::cout << "fail, retval should be " << expected << " you returned : " << answer << std::endl;
    }
}
