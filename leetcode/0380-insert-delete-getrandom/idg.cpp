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
            if( data.size() > 1 )
            {
                int vals_current_location = mit->second;
                int current_last_element = data.back();
                data[vals_current_location] = current_last_element;
                metadata[current_last_element] = vals_current_location;
            }
            metadata.erase(mit);
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
        RandomizedSet rset;
        std::cout << rset.remove(0) << std::endl;
        std::cout << rset.remove(0) << std::endl;
        std::cout << rset.insert(0) << std::endl;
        std::cout << rset.getRandom() << std::endl;
        std::cout << rset.remove(0) << std::endl;
        std::cout << rset.insert(0) << std::endl;
        
    }
    return 0;
}
