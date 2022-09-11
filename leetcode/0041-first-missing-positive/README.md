# Leetcode No. 41.  First Missing Positive


Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses constant extra space.


## Example 1:

Input: nums = [1,2,0]

Output: 3

Explanation: The numbers in the range [1,2] are all in the array.

## Example 2:

Input: nums = [3,4,-1,1]

Output: 2

Explanation: 1 is in the array but 2 is missing.


## Example 3:

Input: nums = [7,8,9,11,12]

Output: 1

Explanation: The smallest positive integer 1 is missing.
 

## Constraints:

1 <= nums.length <= 105

-231 <= nums[i] <= 231 - 1

## Solution

The requirement that this needs to be solved in 0(n) time and uses constant extra space pretty much gives away the solution, which is that you must track your data in a pre-allocated chunk of memory.  Anything else would break those requirements.

So, allocate an array, initialize it, and then start storing values.


## Output

%  make &>/dev/null ; ./fmp

Leetcode 0041 - First Missing Positive

[1,2,0]

First missing 3

[3,4,-1,1]

First missing 2

[7,8,9,11,12]

First missing 1


