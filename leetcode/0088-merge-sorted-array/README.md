## 88. Merge Sorted Array

# Problem Statement
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

 
# Solution

The insights to this problem are that both input arrays are sorted in increasing order, and that the first array is 0 padded so that there's enough room to fit both arrays in it.

Set an insertion point to the the end of the first array.  Then set two indices to be the ends of the first and second arrays.  Iterate in the direction of the 0th element (decreasing magnitude).  At each step, compare and put the largest item at the end of the output array.

When we are done, the first array will contain all the elements of both input arrays.


