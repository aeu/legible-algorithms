## 3294

There's a couple of ways to do this, the easiest if you are in C++ is
to uyse the deque data structure.  Push from the prev ptrs to the
front of the que and the nexts to the back and then walk through and
build the array.

Without using the dequeue you would walk back to the front and then go
forwared to get them in order.

### Output

3294-convert-doubly-linked-list-to-array-ii

1, 2, 3, 4, 5, 

Test case : 1 : Pass


