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


struct FifoCompare {
    bool operator()(const std::pair<int,int> &lhs,
                    const std::pair<int,int> &rhs)
    {
        return lhs.first > rhs.first;
    }
};

class MyQueue {

protected:
    
 
    int pushed_count;
    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, FifoCompare> pqueue;
    
public :
    MyQueue()
    {
        pushed_count = 0;
    }

    void push(int x)
    {
        pqueue.push( { pushed_count, x } );
        pushed_count++;
    }

    int pop()
    {
        std::pair<int,int> top = pqueue.top();
        pqueue.pop();
        return top.second;
    }

    int peek()
    {
        std::pair<int,int> top = pqueue.top();
        return top.second;
    }

    bool empty()
    {
        return pqueue.empty();
    }
};

int main(int argc, char **argv)
{
    std::cout << std::endl << "leetcode/0232-implement-queue-using-stacks" << std::endl << std::endl;
    int test_case = 1;
    {
        MyQueue mq; //  = new MyQueue();
        mq.push(1);
        mq.push(2);
        std::cout << "peek  : " << mq.peek()   << std::endl;
        std::cout << "pop   : " << mq.pop()    << std::endl;
        std::cout << "empty : " << mq.empty()  << std::endl;
        
        std::vector<int> nums  = {1,2,3};
        int expected = 0;
        int result = 0;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
