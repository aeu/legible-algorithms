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
// Write any include statements here

struct CombinationStage
{
    int step;
    int left_lock;
    int right_lock;

    bool operator<(const CombinationStage &rhs) const
    {
        if (step != rhs.step)
            return step < rhs.step;
        if (left_lock != rhs.left_lock)
            return left_lock < rhs.left_lock;
        return right_lock < rhs.right_lock;
    }

    bool operator==(const CombinationStage &rhs) const
    {
        return (( step == rhs.step ) && ( left_lock == rhs.left_lock ) && ( right_lock == rhs.right_lock ));
    }

    
};

struct CombinationStageHash
{
    size_t operator()(const CombinationStage &s) const
    {
        return std::hash<int>()(s.step) ^ (std::hash<int>()(s.left_lock) << 1 ) ^ (std::hash<int>()(s.right_lock) << 2);
    }
};

std::unordered_map<CombinationStage,long long, CombinationStageHash> dpmemo;

long distanceTo(int current, int destination, int N)
{
    if( current == destination )
        return 0;

    int going_right;
    int going_left;
        
    if( current < destination )
    {
        going_right = destination - current;
        going_left = current + N - destination;
    }
    else if( current > destination )
    {
        going_right = N - current + destination;
        going_left = current - destination;
    }
    return std::min( going_right, going_left );
}


long long dpSearch(int step, int left_lock, int right_lock, vector<int> &C, int N)
{
    if( step == C.size() )
        return 0;
    
    CombinationStage current;
    current.step = step;
    current.left_lock = left_lock;
    current.right_lock = right_lock;
    
    if( dpmemo.find( current ) != dpmemo.end() )
        return dpmemo[current];

    int target = C[step];
    // distance to get the left lock to target, plus the distance after the lft lock is at target.
    long long left_distance = distanceTo( left_lock, target, N ) + dpSearch( step+1, target, right_lock, C, N );

    // distance to get the right lock to target, plus the distance after the right lock is at target.
    long long right_distance = distanceTo( right_lock, target, N ) + dpSearch( step+1, left_lock, target, C, N );

    return dpmemo[current] = std::min( left_distance, right_distance );
}

long long getMinCodeEntryTime(int N, int M, vector<int> &C)
{
    dpmemo.clear();
    return dpSearch(0,1,1,C,N);
}

int main(int argc, char **argv)
{
    {
        int n = 3;
        int m = 3;
        std::vector<int> combination = { 1,2,3};
        int mincode = getMinCodeEntryTime( n, m, combination );
        int expected = 2;
        if( mincode == expected )
            std::cout << "pass" << std::endl;
        else 
            std::cout << "fail got " << mincode << " should be " << expected << std::endl;
           
    }
    {
        int n = 10;
        int m = 4;
        std::vector<int> combination = { 9,4,4,8};
        int mincode = getMinCodeEntryTime( n, m, combination );
        int expected = 6;
        if( mincode == expected )
            std::cout << "pass" << std::endl;
        else 
            std::cout << "fail got " << mincode << " should be " << expected << std::endl;
           
    }
    return 0;
}
