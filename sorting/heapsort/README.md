# Heapsort
An implementation of heapsort, as described in Intruduction to Algorithms.  Cormen, Leiserson, Rivest and Stein, MIT Press.

# Notes
Objective-C.
The building of the heap is based on an index that starts with 1, but of course C arrays start at zero.   Reserving the 0the element of the array allowed me to use it to store the heap size, so I was able to represent the heap in an array without creating a dedicated class/structure for it.
