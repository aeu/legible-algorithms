# Leetcode No. 149.  Max Points on a Line

Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.

## Example 1:

![example1](https://user-images.githubusercontent.com/2225377/213257494-c2610aa4-4a09-4e55-9b00-a03ee623cd81.jpg)

Input: points = [[1,1],[2,2],[3,3]]. 
Output: 3. 


## Example 2

![example2](https://user-images.githubusercontent.com/2225377/213257529-708f21f0-6654-4275-bf6b-c90bc7d90995.jpg)

Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]. 
Output: 4. 


## Notes

We are trying to find the line with the most lines on it.  Which means that the lowest possible point count on a line is 2.  So we start off by finding every possible line that can be drawn from two points in the list.  For a given sequence of N points, there are N * N-1 possible lines connecting them.  To get these lines we have a nested loop that gets every possible line.

Now for each line, we need to find out how many points in the set fall on that line.  Here we need a little geometry to figure out the equation of the line (remember that every straight line can be described as y = Mx + C, where m is the gradient and C is a constant.  We first figure out what M and C are for that line, then walk through all the points and see if they are on that line.  We keep track of the number of hits and return the point count of the line that has the most points on it.

This solution has a nested loop so it will be 0N^2.  The line calculation is linear time so it simplifies out.


## Output
% ./solver   
[[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]  
max points on line 4  
[[1,1],[2,2],[3,3]]  
max points on line 3  
