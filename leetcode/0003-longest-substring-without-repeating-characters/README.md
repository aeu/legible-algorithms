### Solution

This is a Sliding Window problem.  I used an unordered set to keep
track of characters, and when I hit a duplicate, I would advance the
trailing pointer until it caught up with the lead pointer - the reason
we go forward until we hit the lead pointer is because the lead
pointer is the one that caused the duplicate in the first place.  Also
update the max length as we go.