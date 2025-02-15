## Leetcode 739. Daily Temperatures

# Problem Statement
Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

# Examples 

     Example 1:
     Input: temperatures = [73,74,75,71,69,72,76,73]
     Output: [1,1,4,2,1,1,0,0]
     
     
     Example 2:
     Input: temperatures = [30,40,50,60]
     Output: [1,1,1,0]
     
     
     Example 3:
     Input: temperatures = [30,60,90]
     Output: [1,1,0]
 

# Constraints:

     1 <= temperatures.length <= 105
     30 <= temperatures[i] <= 100

# Output
     balandra:0739-daily-temperatures alfonso$ ./dtm 
     Leetcode #739 - Daily Temperatures
     
     Example 1
     Temps: [73, 74, 75, 71, 69, 72, 76, 73]
     Wait Days: [1, 1, 4, 2, 1, 1, 0, 0]
     Example 2
     Temps: [30, 40, 50, 60]
     Wait Days: [1, 1, 1, 0]
     Example 3
     Temps: [30, 60, 90]
     Wait Days: [1, 1, 0]
