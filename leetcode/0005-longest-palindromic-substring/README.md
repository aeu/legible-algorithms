### Solution

The key insight here is that given a string of length N, the longest
palindromic substring is going to have a start point somewhere within
N.  The fastest way to find them all is to loop through the string,
and for each position, expand outwards to see what is the longest
palindrome possible starting at that point.  We keep track of the
longest possible as we traverse the string and then return it at the
end.


LC0005 - Longest Palindromic Substring


Test case : 1 : Pass
 (expected bb, got bb)

Test case : 2 : Pass
 (expected ccc, got ccc)

Test case : 3 : Pass
 (expected bab, got bab)

Test case : 4 : Pass
 (expected bb, got bb)

Test case : 5 : Pass
 (expected a, got a)

Test case : 6 : Pass
 (expected a, got a)
