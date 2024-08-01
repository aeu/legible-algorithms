# Leetcode No. 135.  Candy

## Problem

There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

- Each child must have at least one candy.
- Children with a higher rating get more candies than their neighbors.
- Return the minimum number of candies you need to have to distribute the candies to the children.

 

## Example 1:

Input: ratings = [1,0,2]  
Output: 5  
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.


## Example 2:

Input: ratings = [1,2,2]  
Output: 4  
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.
 

## Constraints:

n == ratings.length  
1 <= n <= 2 * 104  
0 <= ratings[i] <= 2 * 104

## Solution
I'm not sure if I misunderstood this one, but it's pretty straightfoward.  For all children in the array, confirm that at least one neighbour is lower, and if so, increment the candy count.

## Output
 
  
    alfonso@maraval 0135-candy % make  
    g++ -g -Wall -std=c++17  -o candy main.cpp  
    alfonso@maraval 0135-candy % ./candy  
    Leetcode #0135 - Candy  
   
    ratings: [1 0 2 ]  
    candies needed: 5  
  
    ratings: [1 2 2 ]  
    candies needed: 4  
