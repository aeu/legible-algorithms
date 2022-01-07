# Heapsort
An implementation of mergesort, as described in Intruduction to Algorithms.  Cormen, Leiserson, Rivest and Stein, MIT Press.

# Notes
Objective-C.
If I was cool I would be using a regular C array, but but NSMutableArray is fine.  Also I used inline functions instead of preprocessor defines for the index calculators.

The building of the heap is based on an index that starts with 1, but of course C arrays start at zero.  This is ok, as reserving the 0 element allows us to use it to store the heap size without needing to create a data structure for it.