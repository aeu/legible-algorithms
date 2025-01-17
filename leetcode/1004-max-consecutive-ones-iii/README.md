## 1004. Max Consecutive Ones III

# Problem Statement
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

# Examples 

      Example 1:
      Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
      Output: 6
      Explanation: [1,1,1,0,0,1,1,1,1,1,1]
      Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.


      Example 2:
      Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
      Output: 10
      Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
      Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 

## Constraints:

      1 <= nums.length <= 105
      nums[i] is either 0 or 1.
      0 <= k <= nums.length

## Output

      balandra:1004-max-consecutive-ones-iii alfonso$ ./mco 
      Leetcode 1004 - Max Consecutive Ones III
      1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0
      Counting with k: 2
      Max consecutive ones : 6
      0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1
      Counting with k: 3
      Max consecutive ones : 10

