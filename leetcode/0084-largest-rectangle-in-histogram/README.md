# Leetcode No. 84.  Largest Rectangle in Histogram


Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

## Example 1

![histogram](https://user-images.githubusercontent.com/2225377/211133369-62346d6d-7425-46f0-9498-429d0c02b373.jpeg)

Input: heights = [2,1,5,6,2,3]  
Output: 10  
Explanation: The above is a histogram where width of each bar is 1.  
The largest rectangle is shown in the red area, which has an area = 10 units.  


## Example 2
![histogram-1](https://user-images.githubusercontent.com/2225377/211133376-50a08aa5-a51a-4c66-a2b6-1c5780a66a9b.jpeg)

Input: heights = [2,4]  
Output: 4


## Notes
This one is very similar to Leetcode 42, Trapping Rain water.  The solution is to walk through the array of heights.  At each step count the number of heights to the left which are as high or higher than the current height, and count the number of heights to the right which are as high or higher than the current height.  With that, we can calculate the area of the rectangle bounded by those columns.   Keep track of the biggest one and we are done.  

## Output

% ./solver   
Leetcode 0084 - Largest Rectangle in Histogram  
[2,1,5,6,2,3]  
largest_rectangle: 10  
[2,4]  
largest_rectangle: 4  

