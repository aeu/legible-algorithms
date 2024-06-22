## Leetcode No. 0076.  Minimum Window Substring (hard)

Given two strings s and t of lengths m and n respectively, return the
minimum window substring of s such that every character in t
(including duplicates) is included in the window. If there is no such
substring, return the empty string "".

The testcases will be generated such that the answer is unique.

 
## Output

   	Searching for ABC in ADOBECODEBANC
   	     ABC was found in BANC

   	Searching for a in a
	  a was found in a

   	Searching for aa in a
	  Candidate aa is too long to fit in a


## Solution

This is a sliding window problem with a couple of extras added on to make it harder.  The first is the includeing duplicates requirement.  The second is to find the minimum window substring, so we have to start from the shortest substrings and go up so that we don't waste time iterating over longer strings.
