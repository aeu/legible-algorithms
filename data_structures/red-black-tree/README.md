## Red Black Tree

## Introduction

Red Black trees are the data structure that we all kind of take for granted.  Conceptually we know what they are (a type of binary search tree), what they are good for (where it is important to optimize a tree to maintain consistent operation execution times) and where they are use (std::map is typically implemented as a RBT.

We (or maybe it's just me) see "Red Black Tree" in texts and go to ourselves "I know what those are" and keep going.  But it's not until you actually type it up that you actually understand how it works and what it is doing

## Implementation

In addition to being a lot more typing than I anticipated, impementing an actual working tree also required complete understanding of what was going on.  Most of the documentation and implementations I have seen online are all seem to be based on Introduction to Algorithms (CLRS) which is actually an imcomplete implementation, as they leave half of it as an exercise to the reader.  So what happened is that half the blogs and code sites that I've seen this implemented are the exact same way, with only half of it done.

My implementation is complete, and it works.  I even put in some code to dump graphviz output so you can see your tree.  I do notice that sometimes the colours are not quite right, I am working on figurout out what edge case causes that.
t