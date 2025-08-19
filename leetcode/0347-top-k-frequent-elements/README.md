We solve this using two built in data structures of C++, one being a unordered map, and the other being a priority queue.

First we count all the elements in the array, this is a single pass operation.

We then build a priority queue, into which we store the element and its frequency.  We setup the priority queue to sort by frequency such that the most frequently occurring item is at the top of the queue.

When we are done, we pick the first K elements off the top of the priority queue and that is the solution.
