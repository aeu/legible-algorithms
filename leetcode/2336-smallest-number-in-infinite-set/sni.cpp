// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82
//
#include <stdio.h>
#include <limits.h>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>


class SmallestInfiniteSet {
protected:
    std::unordered_set<int> counters;
    std::priority_queue<int,std::vector<int>,std::greater<int>> infinite_mheap;
public:
    SmallestInfiniteSet() {
        for(int i=1;i<1001;i++)
        {
            infinite_mheap.push(i);
            counters.insert(i);
        }
    }
    
    int popSmallest() {
        int smallest = infinite_mheap.top();
        infinite_mheap.pop();
        counters.erase(smallest);
        return smallest;
    }
    
    void addBack(int num) {
        if( counters.find(num) == counters.end() )
        {
            infinite_mheap.push(num);
            counters.insert(num);
        }
    }
};


int main(int argc, char **argv)
{
    int test_case = 1;
    {
    }
    return test_case;
}
