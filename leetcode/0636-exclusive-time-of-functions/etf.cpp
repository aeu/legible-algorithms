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

void dumpValues(std::vector<int> values)
{
    bool first = true;
    for(const auto &curr : values )
    {
        if( ! first )
            std::cout << ", ";
        first = false;
        std::cout << std::setw(3) << curr ;
    }
    std::cout << std::endl;
}


std::vector<int> exclusiveTime(int n, std::vector<std::string>& logs)
{
    std::stack<int> execution_stack;
    int previous_time = 0;
    std::vector<int> times(n,0);
    for(const auto curlog : logs )
    {
        char *temp = strdup(curlog.c_str());
        char *tok = strtok(temp,":");
        int position = 0;
        int id;
        std::string action;
        int time;
        while( tok )
        {
            if( position == 0 )
            {
                id = atoi( tok );
                position++;
            }
            else if( position == 1 )
            {
                action += tok;
                position++;
            }
            else if( position == 2 )
            {
                time = atoi(tok);
            }
            tok = strtok(NULL,":");
        }
        free(temp);
        if( action == "start" )
        {
            if( ! execution_stack.empty() )
            {
                // there was already a function being executed (which
                // is now going to stop as theres a new function, so
                // add the time up until now to that functions
                // runtime.
                int current_function = execution_stack.top();
                times[current_function] += ( time - previous_time );
            }
            // push the new function onto the execution stack, and
            // reset the start time so it reflects the function at the
            // top of the stack
            execution_stack.push(id);
            previous_time = time;
        }
        else if( action == "end" )
        {
            // the function currently at the top of the stack is no
            // longer executing, so pop it and add its runtime to the
            // times vector
            int current_function = execution_stack.top();
            execution_stack.pop();
            times[current_function] += time - previous_time + 1;
            previous_time = time + 1;
        }
    }
    return times;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0636-exclusive-time-of-functions" << std::endl << std::endl;
    int test_case = 1;
    {
        int n = 2;
        std::vector<std::string> logs = { "0:start:0","1:start:2","1:end:5","0:end:6" };
        std::vector<int> expected  = {3,4};
        std::vector<int> result = exclusiveTime(n,logs);
        dumpValues(result);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        int n = 1;
        std::vector<std::string> logs = {"0:start:0","0:start:2","0:end:5","0:start:6","0:end:6","0:end:7"};
        std::vector<int> expected  = {8};
        std::vector<int> result = exclusiveTime(n,logs);
        dumpValues(result);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        int n = 2;
        std::vector<std::string> logs = {"0:start:0","0:start:2","0:end:5","1:start:6","1:end:6","0:end:7"};
        std::vector<int> expected  = {7,1};
        std::vector<int> result = exclusiveTime(n,logs);
        dumpValues(result);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
