// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82


#include <iostream>
#include <vector>

int maxProfit(std::vector<int>& prices)
{
    int max_profit = 0;
    int min_price = prices[0];
    for(int index=1;index<prices.size();index++)
    {
        min_price = std::min( min_price, prices[index] );
        int profit = prices[index] - min_price;
        max_profit = std::max( max_profit, profit);
    }
    return max_profit;
}

int main(int argc, char **argv)
{
    {
        std::vector<int> prices = { 7,1,5,3,6,4 };
        int max_profit = maxProfit( prices );
        std::cout << "MP: " << max_profit << std::endl;
    }
    {
        std::vector<int> prices = { 7,6,4,3,1 };
        int max_profit = maxProfit( prices );
        std::cout << "MP: " << max_profit << std::endl;
    }
}
