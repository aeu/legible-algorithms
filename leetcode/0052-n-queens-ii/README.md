# Leetcode No. 52.  N-Queens II


The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return the number of distinct solutions to the n-queens puzzle.
all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

## Example 1:

![queens](https://user-images.githubusercontent.com/2225377/207093423-63d914d2-4453-40e9-8deb-3e0ed8811d0a.jpeg)

Input: n = 4
Output: 2
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above


## Example 2:

Input: n = 1
Output: 1


## Notes

This was pretty much the same as Leetcode 0051, except in this one we dump the count of boards, not the actual boards themselves.  The text below is from the readme for N-Queens problem (as it's almost exactly the same code);

This puzzle was fairly straightforward, fundamentally it's a permutations problem.  We know that we can only have one queen per row and one queen per column, so every possible board is going to be an arrangement of rows with incrementing queens.  For example if it's a 3x3 board, the possible rows are going to be "Q--", "-Q-" and "--Q".   The first setup is to build the rows, then build all possible boards that can be created by permutations of those rows.  

Once those are created, then we can check to see if they are solutions by walking through the board, and for each queen found, checking to see if there are any other queens in any of the diagonals (NE, NW, SE, SW).  If there's no more queens, then it's a solution.

C++11 features used were range based for loops, the auto keyword, delegating constructors and most importantly lambda functions.  Commit <a target="_blank" href="https://github.com/aeu/legible-algorithms/commit/0ac49bcc4529d33812913ee8d45f98bd0a08ca7f">0ac49bcc</a> shows how lambda functions allows removal of huge chunks of duplicated code by allowing us to pass in only the part of the function that actually changes.

## Output

% ./solver 
Leetcode 0052 - N-Queens II

