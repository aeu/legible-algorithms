#include <stdio.h>
#include <vector>
#include <iostream>

void dumpValuesWithRange(std::vector<int>& prices,
                         int left,
                         int right)
{
    bool first_time = true;
    std::cout << "[" ;
    for(int index=left;index<=right;index++)
    {
        if( ! first_time )
            std::cout << ", ";
        std::cout << prices[index];
        first_time = false;
    }
    std::cout << "]" << std::endl;
}

int maxProfitInRange(std::vector<int>& prices,
                     int left,
                     int right)
{
    int max_profit = 0;
    int min_price  = prices[left];
    for(int index=left;index<=right;index++)
    {
        min_price = std::min( min_price, prices[index] );
        int profit = prices[index] - min_price;
        max_profit = std::max( max_profit, profit );
    }
    return max_profit;
}

int maxProfit(std::vector<int>& prices)
{
    std::vector<int> lhs_maxes(prices.size(),0);
    std::vector<int> rhs_maxes(prices.size(),0);
    
    int max_profit = 0;
    for(int index=0;index<prices.size()-1;index++)
    {
        int lhs_profit = maxProfitInRange(prices,0,index);
        lhs_maxes[index] = lhs_profit;
    }

    for(int index=0;index<prices.size()-1;index++)
    {
        int rhs_profit = maxProfitInRange(prices,index,prices.size()-1);
        rhs_maxes[index] = rhs_profit;
    }

    for(int index=0;index<prices.size();index++)
    {
        int profit = lhs_maxes[index] + rhs_maxes[index];
        max_profit = std::max(max_profit,profit);
    }
    return max_profit;
}

int main( int argc, char **argv)
{
    printf("Leetcode #0123 - Best Time to Buy and Sell Stock III\n");

    { // test case 1
        std::cout << "Example: 1" << std::endl;
        std::vector<int> prices = { 3,3,5,0,0,3,1,4 };
        dumpValuesWithRange(prices,0,prices.size()-1);
        int max_profit = maxProfit(prices);
        std::cout << "MP: " << max_profit << std::endl;
    }
    { // test case 1
        std::cout << "Example: 2" << std::endl;
        std::vector<int> prices = { 1,2,3,4,5 };
        dumpValuesWithRange(prices,0,prices.size()-1);
        int max_profit = maxProfit(prices);
        std::cout << "MP: " << max_profit << std::endl;
    }
    { // test case 1
        std::cout << "Example: 3" << std::endl;
        std::vector<int> prices = { 7,6,4,3,1 };
        dumpValuesWithRange(prices,0,prices.size()-1);
        int max_profit = maxProfit(prices);
        std::cout << "MP: " << max_profit << std::endl;
    }
    { // test case 1
        std::cout << "Example: 4" << std::endl;
        std::vector<int> prices = { 1,2};
        dumpValuesWithRange(prices,0,prices.size()-1);
        int max_profit = maxProfit(prices);
        std::cout << "MP: " << max_profit << std::endl;
    }
    return 0;
}
