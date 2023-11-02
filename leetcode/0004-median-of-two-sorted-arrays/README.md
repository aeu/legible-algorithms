# Leetcode No. 4.  Median of Two Sorted Arrays

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

 

# Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.


## Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

Constraints:

nums1.length == m

nums2.length == n

0 <= m <= 1000

0 <= n <= 1000

1 <= m + n <= 2000

-106 <= nums1[i], nums2[i] <= 106

## Notes
This is basically the second half of mergesort.  The other thing to remember is that you don't have to completely merge the arrays.  You don't even have to merge them at all actually, you just have to keep track of the last two numbers, and go far enough so that you go one past the middle.  

If the count of numbers is odd the answer is the previous number you stored.  If it's even, average the last two.  I think this solution is actually quicker than the goal, because they ask for it to be O(log (m+n)) and this is O((m+n)/2) (I think!).
