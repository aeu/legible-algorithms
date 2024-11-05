## 233. Number of Digit One

Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

 
# Example 1:

Input: n = 13
Output: 6

# Example 2:

Input: n = 0
Output: 0
 
# Constraints:

0 <= n <= 109

# Solution
Iterate over the input number, dividing by 10 each time, while it's > 0.  At each iteration, do a modulo with 10 
(to extract the digit in the ones column) and test to see if it's one, and if it is, increment the count.

# Output
```
alfonso@maraval 0233-number-of-digit-one % ./nodo 
Leetcode #0233 - Number of Digit One
value: 13, num ones: 1
value: 0, num ones: 0
value: 121451, num ones: 3
