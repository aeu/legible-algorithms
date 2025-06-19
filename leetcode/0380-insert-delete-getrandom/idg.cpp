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

class RandomizedSet {
public:
    std::unordered_map<int,int> metadata;
    std::vector<int> data;
    
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        bool retval = false;
        if( metadata.find(val) == metadata.end() )
        {
            data.push_back(val);
            metadata[val] = data.size()-1;
            retval = true;
        }
        return retval;
    }

    bool remove(int val)
    {
        bool retval = false;
        auto mit = metadata.find( val );
        if( mit != metadata.end() )
        {
            int vals_current_location = mit->second;
            int current_last_element = data.back();
            metadata.erase(mit);
            data[vals_current_location] = current_last_element;
            metadata[current_last_element] = vals_current_location;
            data.pop_back();
            retval = true;
        }
        return retval;
    }
    
    int getRandom()
    {
        return data[ rand() % data.size() ];
    }
};


int main(int argc, char **argv)
{
    std::cout << std::endl << "0380-insert-delete-getrandom" << std::endl << std::endl;
    int test_case = 1;
    {
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
