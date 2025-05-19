

### Problem

What this problem is asking you to do is find two numbers that add up
to a specific target.  The trivial solution would be to just go
through add up every possible combination of numbers until you find
the pair that hit that target.  The problem is that would require a
nested loop which would make the problem N2 in complexity.

### Solution

We know that any solution is goign to be of the form

     Nx + Ny = T.

So what that means is that for every possible Nx, we can calculte what
the Ny would be to solve the equation.  So we walk through the nums
array, and for each number we calculate what it's complementary number
would need to be.  If that completely number exists, that is the
solution.

The other neat trick we can do is solve the problem in one pass.
Calculate the complement and see if it's already in there.  If it's
there, return it (and the current number).  If not, add the complement
that we just calculated, as we will (if it exists) eventually come
across the complement to it.