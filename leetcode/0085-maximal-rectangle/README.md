# Leetcode No. 0085 Maximal Rectangle

Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

## Example 1:
```
Input: matrix = [["1","0","1","0","0"],  
                 ["1","0","1","1","1"],  
                 ["1","1","1","1","1"],  
                 ["1","0","0","1","0"]]  
```                  
Output: 6  



Explanation: The maximal rectangle is shown in the above picture.

## Example 2:

```
Input: matrix = [["0"]]
```
Output: 0

## Example 3:

```
Input: matrix = [["1"]]
```
Output: 1

## Constraints:

rows == matrix.length  
cols == matrix[i].length  
1 <= row, cols <= 200   
matrix[i][j] is '0' or '1'.  


## Output
```
alfonso@maraval 0085-maximal-rectangle % ./mxr
Legible Algorithms - Leetcode 0085 Maximal Rectangle
10100
10111
11111
10010

Largest area was 6


10100
10111
11111
11111
10010

Largest area was 10
```
