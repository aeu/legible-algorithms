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
This one is very similar to Leetcode 42, Trapping Rain water.  The brute force solution is to walk through the array of heights.  At each step count the number of heights to the left which are as high or higher than the current height, and count the number of heights to the right which are as high or higher than the current height.  With that, we can calculate the area of the rectangle bounded by those columns.   Keep track of the biggest one and we are done.

## Output

% ./solver   
Leetcode 0084 - Largest Rectangle in Histogram  
[2,1,5,6,2,3]  
largest_rectangle: 10  
[2,4]  
largest_rectangle: 4  


## Optimized solution

The optimized solution I am embarassed to say I was not able to figure out.   I found a really nice implementation on geeksforgeeks that I put into the code.  I put in the original solution of theirs, as well as my version, which is pretty much the same except I improved the variable names and made it a little more verbose and easier to read.   It's a bit confusing, so I put below a step through of the function so it can be followed.



getMaxArea


      0 1 2 3 4 5
      2 1 5 6 2 3
      
        -----Iteration--------
        Max area = 0
        Index = 0
        Stack =
              Stack is empty logic skipped
              index (0) pushed on to stack
              
        -----Iteration--------
        Max area = 0
        Index = 1
        Stack = 0
              Stack is not empty
              The height of the stack top (2) is greater than the index height (1)
                  Setting tp to 0
                  popping stack
                  height = 2
                  width = 0 (because stack is empty now)
                  current area is 2.
                  setting max area to 2
              
              Pushing index (1) on to stack
              
        ----- Iteration --------
        Max area = 2
        Index = 2
        Stack = 1
              Stack is not empty
              Height of tp (1) is less than height of index (5)

              pushing index (2) onto stack
        
      
        ----- Iteration --------
        Max area = 2
        Index = 3
        Stack = 1 2
              Stack is not empty
	      height of tp (5) is less than height of index (6)

	      pushing index (3) on to stack
        

        ----- Iteration --------
        Max area = 2
        Index = 4
        Stack = 1 2 3
              start of while
              Stack is not empty
              height of tp (6) is greather than height of index (2)
                  tp = 3
                  popping stack, it's now 1,2
                  height = 6
                  width  = 4 - 2 - 1 = 1
                  current area = 6
                  max_area = 6
      
        Max area = 6
        Index = 4
        Stack = 1 2
	
              Start of while
              Stack is not empty
              height of tp (5) is greather than height of index 4 (2)
                  tp = 2
                  popping stack, it's now 1
                  height = 5
                  width  = 4 - 1 - 1 = 2
                  current area = 10
                  max_area = 10
      
        Max area = 10
        Index = 4
        Stack = 1
        
              Start of while
              Stack is not empty
              Height of tp 1 (1 ) is less than height of index 4 (2)

              pushing index (4) on to stack, stack is now [1 4]
      
        ----- Iteration --------
        Max area = 10
        Index = 5
        Stack = 1 4
      
            Start of while
            Stack is not empty
            Height of tp 4 (2) is less than than height of index 5 (3)
	    
            Pushing index onto stack, stack is now [1 4 5]
      
      
        Iterations done, now on final while loop where it goes through the stack
        
        Max area = 10
        Stack = 1 4 5
      
            Start of while
            Stack is not empty
                tp = 5
                popping stack, it's now [1 4]
                width = 6 - 4 - 1 = 3
                current_area = 3 * 3 = 9
      
        Max area 10
        Stack 1 4
      
            Repeating while
            Stack is not empty
                 tp = 4
                 popping stack, it's now [1]
                 width = 6 - 1 - 1 = 4
                 height 4 (2)
                 area = 2 * 4 = 8
         
        Max area 10
        Stack 1
      
             Repeating while
             Stack is not empty
                 tp = 1
                 popping stack, it's now empty
                 width = 6
                 height = 1
                 current_area = 6
               
      

      Done 
      Max area was 10.
