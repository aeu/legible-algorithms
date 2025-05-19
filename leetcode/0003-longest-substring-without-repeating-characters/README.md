### Solution

This is a Sliding Window problem.  I used an unordered set to keep
track of characters, and when I hit a duplicate, I would advance the
trailing pointer until it caught up with the lead pointer.  Also
update the max length as we go.