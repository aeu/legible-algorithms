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


class TimeMap {
public:

    static bool valueCompare(const int lhs, const std::pair<int, std::string> &rhs)
    {
         return lhs < rhs.first ;
    };
    

    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> store;
    
    TimeMap()
    {
        
    }
    
    void set(std::string key, std::string value, int timestamp)
    {
        store[key].push_back({timestamp,value});
    }
    
    std::string get(std::string key, int timestamp)
    {
        auto sit = store.find(key);
        if( sit == store.end() )
            return "";
        const std::vector<std::pair<int,std::string>> &values = sit->second;
        auto vit = std::upper_bound(values.begin(),
                                    values.end(),
                                    timestamp,
                                    valueCompare);
        if( vit == values.begin() )
            return "";
        --vit;
        return vit->second;
    }
};




int main(int argc, char **argv)
{
    std::cout << std::endl << "0981-time-based-key-value-store" << std::endl << std::endl;
    int test_case = 1;
    {
        TimeMap *timeMap = new TimeMap();
        timeMap->set("foo", "bar", 1);  // store the key "foo" and value "bar" along with timestamp = 1.
        std::cout << timeMap->get("foo", 1) << std::endl;         // return "bar"
        std::cout << timeMap->get("foo", 3) << std::endl;         // return "bar", since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 is "bar".
        timeMap->set("foo", "bar2", 4); // store the key "foo" and value "bar2" along with timestamp = 4.
        std::cout << timeMap->get("foo", 4) << std::endl;         // return "bar2"
        std::cout << timeMap->get("foo", 5) << std::endl;         // return "bar2"
        
        // std::vector<int> nums  = {1,2,3};
        int expected = 0;
        int result = 0;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        // std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
