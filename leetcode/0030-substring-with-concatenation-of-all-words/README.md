# Leetcode No. 30.  Substring with Concatenation of All Words


You are given a string s and an array of strings words of the same length. Return all starting indices of substring(s) in s that is a concatenation of each word in words exactly once, in any order, and without any intervening characters.

You can return the answer in any order.

 

## Example 1:

Input: s = "barfoothefoobarman", words = ["foo","bar"]

Output: [0,9]

Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar" respectively.

The output order does not matter, returning [9,0] is fine too.

## Example 2:


Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]

Output: []

## Example 3:


Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]

Output: [6,9,12]


## Notes
This is two problems in one.  The first part of the problem is finding all the possible permutations, which is done recursively by the function findPermutations, which builds a vector of all the possible permutations of the input strings.  The second part, which is easier, is just making sure that you check for multiple occurrences of the permutation in the input string.


## Output

$ make &>/dev/null ; ./swcoaw
Leetcode 0030 - Substring with Concatenation of All Words
[9,0]
[]
[6,9,12]

