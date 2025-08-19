## Solution

Iterate through the array and add each element as we go to a priority queue that sorts by size.  At each step, if the size of the queue goes over k, then pop until the size is k.  

By doing this inside the loop we are more efficient as we don't sort the full array every time so the priority queue can do it's thing faster.


0215-kth-largest-element-in-an-array


Test case : 1 : Pass (expected 5, got 5)

Test case : 2 : Pass (expected 4, got 4)
