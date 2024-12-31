# Leetcode 239. Sliding Window Maximum

## Description ##
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

 

# Example 1: #

      Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
      Output: [3,3,5,5,6,7]
      Explanation: 
      Window position                Max
      ---------------               -----
      [1  3  -1] -3  5  3  6  7       3
       1 [3  -1  -3] 5  3  6  7       3
       1  3 [-1  -3  5] 3  6  7       5
       1  3  -1 [-3  5  3] 6  7       5
       1  3  -1  -3 [5  3  6] 7       6
       1  3  -1  -3  5 [3  6  7]      7


# Example 2: #

      Input: nums = [1], k = 1
      Output: [1]
 

# Constraints: #

      1 <= nums.length <= 105
      -104 <= nums[i] <= 104
      1 <= k <= nums.length


# Output #
      alfonso@maraval 0239-sliding-window-maximum % ./swm
      
      Leetcode #0239 - Sliding Window Maximum
      
      Input Array   : [1,3,-1,-3,5,3,6,7]
      Window size   : 3
      Output Array  : [3,3,5,5,6,7]
      
      Input Array  : [1]
      Window size  : 1
      Output Array : [1]

# Discussion #
To be completely honest, I am not sure why this is classified as hard, as I thought it was pretty straightforward.  There were a couple of loops and that was about it.
