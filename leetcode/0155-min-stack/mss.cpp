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
#include <stack>
#include <memory>

class MinStack
{

private:

    std::stack<int> value_stack;
    std::stack<int> min_stack;
    
public:
    MinStack()
    {
    }

    void push(int val)
    {
        value_stack.push(val);
        if( min_stack.size() == 0 )
            min_stack.push(val);
        else
        {
            if( val < min_stack.top () )
            {
                min_stack.push(val);
            }
        }
    }

    void pop()
    {
        int popped = value_stack.top();
        value_stack.pop();
        if( popped == min_stack.top() )
            min_stack.pop();
    }

    int top()
    {
        return value_stack.top();
    }

    int getMin()
    {
        return min_stack.top();
    }
};


int main(int argc, char **argv)
{
    MinStack minStack; // = new MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    int val = minStack.getMin();
    std::cout << "getMin returned : " << val << std::endl;
    minStack.pop();
    val = minStack.top();
    std::cout << "top returned : " << val << std::endl;
    val = minStack.getMin();
    std::cout << "getMin returned : " << val << std::endl;
    
    int test_case = 1;
    return test_case;
}
