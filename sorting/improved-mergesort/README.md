## Mergesort, revisited ##

# Introduction

The first mergesort I implemented was pretty bad.  It was correct, but I allocated a ton of unnecessary structures, which is really bad when you have recursion and you have a large amount of input data.  Also looking at it now that a few years have gone by, I find that it could be more legible.

This implementation is in C++ and instead of creating data strucutures willy nilly, I modify the input array in place.  There is a temporary array being created during the merge operation, but I can't get rid of that one.  This version is way cleaner and easier to read.

# Output

      alfonso@maraval improved-mergesort % ./merge 
      2 7 13 1 8 45 5 9 12 55 
      1 2 5 7 8 9 12 13 45 55 
