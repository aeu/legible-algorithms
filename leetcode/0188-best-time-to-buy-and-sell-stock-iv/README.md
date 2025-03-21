# Leetcode 188. Best Time to Buy and Sell Stock IV#

## Description ##
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

### Example 1: ###

     Input: k = 2, prices = [2,4,1]
     Output: 2
     Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.


### Example 2: ###

     Input: k = 2, prices = [3,2,6,5,0,3]
     Output: 7
     Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
     Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 

### Constraints: ###

     1 <= k <= 100
     1 <= prices.length <= 1000
     0 <= prices[i] <= 1000

## Solution ##

This problem is a decorated version of the find permutations problem.   To solve you have to build a list of all profitable trades, then build a list of all valid sequences of trades.  A sequence is valid if there's k or non-intersecting trades in it.  While building the sequence you make sure you don't hit k and that the trades don't intersect.

To make things easy I created a Trade object with some utility functions in it.

### Output ###
     alfonso@maraval 0188-best-time-to-buy-and-sell-stock-iv % ./best_time
     Leetcode 0188 - Best Time to Buy and Sell Stock IV
     Prices: [2, 4, 1]
     There are 1 profitable trades
     There are 2 possible trade sequences
     Best sequence had profit of 2
     Sequence length: 1
     	Trade: buy day 1, end day 2, profit 2
     
     Prices: [3, 2, 6, 5, 0, 3]
     There are 6 profitable trades
     There are 15 possible trade sequences
     Best sequence had profit of 7
     Sequence length: 2
     	Trade: buy day 2, end day 3, profit 4
     	Trade: buy day 5, end day 6, profit 3

