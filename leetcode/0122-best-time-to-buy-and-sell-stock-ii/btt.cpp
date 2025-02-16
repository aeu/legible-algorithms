// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82


#include <iostream>
#include <vector>


void dumpValues(std::vector<int>& values)
{
    bool first_time = true;
    std::cout << "[" ;
    for(auto current : values )
    {
        if( ! first_time )
            std::cout << ", ";
        std::cout << current;
        first_time = false;
    }
    std::cout << "]" << std::endl;
}


int maxProfit(std::vector<int>& prices)
{
    int running_profit = 0;
    for(int index=1;index<prices.size();index++)
    {
        if( prices[index] > prices[index-1] )
        {
            running_profit += ( prices[index] - prices[index-1] );
        }
    }
    return running_profit;
}

int main(int argc, char **argv)
{
    std::cout << "Leetcode 0122 - Best time to Buy and Sell Stock II" << std::endl;
    {
        std::cout << "Example : 1" << std::endl;
        std::vector<int> prices = { 7,1,5,3,6,4 };
        int max_profit = maxProfit( prices );
        dumpValues( prices );
        std::cout << "MP: " << max_profit << std::endl;
    }
    {
        std::cout << "Example : 2" << std::endl;
        std::vector<int> prices = { 1,2,3,4,5 };
        int max_profit = maxProfit( prices );
        dumpValues( prices );
        std::cout << "MP: " << max_profit << std::endl;
    }
    {
        std::cout << "Example : 3" << std::endl;
        std::vector<int> prices = { 7,6,4,3,1 };
        int max_profit = maxProfit( prices );
        dumpValues( prices );
        std::cout << "MP: " << max_profit << std::endl;
    }
}
