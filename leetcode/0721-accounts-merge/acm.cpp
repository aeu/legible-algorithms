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


std::vector<std::vector<std::string>> accountsMerge(std::vector<std::vector<std::string>> &accounts)
{
    for(auto const &curr : accounts )
    {
        std::cout << "Name: " << curr[0] << std::endl;
        for(int index=1;index<curr.size();index++)
        {
            std::cout << "Email : " << curr[index] << std::endl;
        }
    }
    std::vector<std::vector<std::string>> retval;
    return retval;
}



    
int main(int argc, char **argv)
{
    std::cout << std::endl << "0721-accounts-merge" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::vector<std::string>> accounts =
            {{"John", "johnsmith@mail.com", "john_newyork@mail.com"},
             {"John", "johnsmith@mail.com", "john00@mail.com"},
             {"Mary", "mary@mail.com"},
             {"John", "johnnybravo@gmail.com"}};

        
        std::vector<std::vector<std::string>> expected =
                {{"John","johnsmith@mail.com", "john_newyork@mail.com","johnsmith@mail.com", "john00@mail.com"},
                 {"Mary", "mary@mail.com"},
                 {"John", "johnnybravo@gmail.com"}};
                 
        std::vector<std::vector<std::string>> result = accountsMerge( accounts );
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
