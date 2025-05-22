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
        // since this is a single transaction, we can just walk
        // through the price array and update as we go the following:
        // min price and max profit.  If we find a price lower than
        // our previous min, we just switch to it going forward.  It
        // doesn't matter that we switched, because we are still
        // keeping track of best possible profit using the previous
        // min price, so we can just return that at the end.

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
