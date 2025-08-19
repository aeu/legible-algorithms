
## Solution

The solution to this one is to first sort the intervals by start.  Then insert them in order to the output array.   At each step in the insert, check to see if the one we are going to insert overlaps with the one that is currently last in the output array.  If it is, update it by merging it with the candidate, and then keep going.

0056-merge-intervals


Test case : 1 : Pass

Test case : 2 : Pass
