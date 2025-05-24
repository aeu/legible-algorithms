### Implementation

The basic functionality of a LRU is that we want to get rid of the
Least Recently Used items, they came up with this in the 90s.

So you are actually tracking two things.  One is the actual values
themselves, the second is when they were last used.  That way when we
need to store something and need to make room for it, we can remove
the thing that was least recently used.

This implementation uses a unordered_map to store the data, and a
linked list to keep track of which was most recently used.  The key
functionality is moveToHead() and removeOldest().

The class keeps track of the head and tail of the linked list.  When
an items is used (like for example in a get()), it's moved to the head
of the linked list.

When you add a new item, if the number of items you are storing
exceeds your cache size you find the element at the tail end of the
linked list (which is ordered most -> least recently used) and remove
it, first from the lookup map, and then from the linked list itself.

