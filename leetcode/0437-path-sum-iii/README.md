## 437. Path Sum III

# Problem Statement
Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).


# Examples


     Example 1:
     Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
     Output: 3
     Explanation: The paths that sum to 8 are shown.
     
     
     Example 2:
     Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
     Output: 3
 

# Constraints:

     The number of nodes in the tree is in the range [0, 1000].
     -109 <= Node.val <= 109
     -1000 <= targetSum <= 1000

# Output

     balandra:0437-path-sum-iii alfonso$ ./pst 
     Leetcode #437 - Path Sum III
     Example 1
     Input : [10, 5, -3, 3, 2, null, 11, 3, -2, null, 1]
     Looking for a sum of : 8
     valid paths count : 3
     These are: 
     [3, 5]
     [11, -3]
     [1, 2, 5]
     Example 2
     Input : [5, 4, 8, 11, null, 13, 4, 7, 2, null, null, 5, 1]
     Looking for a sum of : 22
     valid paths count : 3
     These are: 
     [7, 11, 4]
     [2, 11, 4, 5]
     [5, 4, 8, 5]
