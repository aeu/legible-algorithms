# Binary Search Tree

This is an implementation of Binary Search Tree as described in Introduction to Algorithms.  Cormen, Leiserson, Rivest and Stein, MIT Press in C++.  It's a lot easier to read than the one in the book and also I put in std::shared_ptr for memory management.  I also modified the the deletion function, as the impementation in the text returns a deleted node for garbage collection which of course isn't necessary if you're using shared_ptrs as they delete themselves.

