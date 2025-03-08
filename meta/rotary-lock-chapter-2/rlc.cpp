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


struct PairLLHash {
    size_t operator()(const std::pair<long long, long long>& p) const {
        size_t h1 = std::hash<long long>()(p.first);
        size_t h2 = std::hash<long long>()(p.second);
        // Combine the two hash values using bitwise operations.
        return h1 ^ (h2 + 0x9e3779b97f4a7c15ULL + (h1 << 6) + (h1 >> 2));
    }
};

std::unordered_map<std::pair<long long,long long>, long long, PairLLHash> dpmemo;

int distanceTo(int current, int destination, int N)
{
    return std::min(abs(destination - current), N - abs(destination - current));
}

std::pair<long long, long long> encode(int step, int left_lock, int right_lock )
{
    long long first = ((long long) left_lock << 30 ) | ((long long ) right_lock );
    long long second = ( long long ) step;
    return std::make_pair( first, second );
}

long long dpSearch(int step, int left_lock, int right_lock, vector<int> &C, int N)
{
    if( step == C.size() )
        return 0;

    auto key = encode( step, left_lock, right_lock );
    
    if( dpmemo.find( key ) != dpmemo.end() )
        return dpmemo[key];

    int target = C[step];
    // distance to get the left lock to target, plus the distance after the lft lock is at target.
    long long left_distance = distanceTo( left_lock, target, N ) + dpSearch( step+1, target, right_lock, C, N );

    // distance to get the right lock to target, plus the distance after the right lock is at target.
    long long right_distance = distanceTo( right_lock, target, N ) + dpSearch( step+1, left_lock, target, C, N );

    return dpmemo[key] = std::min( left_distance, right_distance );
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
