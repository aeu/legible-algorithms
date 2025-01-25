# legible-algorithms

When I get stuck on something, I like to solve puzzles and implement algorithms as a form of focused distraction.  This is a collection of my implementations of various things that I wrote to pass the time.  They are in C++ and Obj-C because I enjoy working on those languages. Maybe I'll add some Rust soon.

## Data Structures
The data structures we take for granted.  These were a lot more typing than I expected.  The Red-Black tree especially.

<a href="https://github.com/aeu/legible-algorithms/tree/master/data_structures/binary_search_tree">Binary Search Tree &mdash; Intruduction to Algorithms. Cormen, Leiserson, Rivest and Stein, MIT Press. (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/data_structures/red-black-tree">Red Black Tree &mdash; Intruduction to Algorithms. Cormen, Leiserson, Rivest and Stein, MIT Press. (C++)</a>  

## Sorting & Searching

<a href="https://github.com/aeu/legible-algorithms/tree/master/sorting/heapsort">Heapsort &mdash; Intruduction to Algorithms. Cormen, Leiserson, Rivest and Stein, MIT Press. (Obj-C)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/sorting/mergesort">Mergesort &mdash; Intruduction to Algorithms. Cormen, Leiserson, Rivest and Stein, MIT Press. (Obj-C)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/sorting/quicksort">Quicksort &mdash; Intruduction to Algorithms. Cormen, Leiserson, Rivest and Stein, MIT Press. (Obj-C)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/sorting/improved-mergesort">Improved Mergesort (C++)</a>  


## Misc Snippets / Drop Ins
Code snippets that can be dropped in to other projects so you don't have to re-type the wheel every time.

<a href="https://github.com/aeu/legible-algorithms/tree/master/misc/heaps-algorithm">Heap's Algorithm for generating permutations (C++)</a>    
<a href="https://github.com/aeu/legible-algorithms/tree/master/misc/fibonacci">Fibonacci number generator (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/misc/linked-list">Drop in, int holding, memory safe linked list (C++)</a>  

Binary tree is sort of optimized for leetcode, which uses an array in the style of [1,2,null,4,6,7,null,8...] to represent the tree. I can't use a vector of ints because of the nulls, and I don't want to use a sentinel value which may occur in real data.  This implementation uses std::optional, so you can put in std::nullopt in the data array.

<a href="https://github.com/aeu/legible-algorithms/tree/master/misc/binary-tree">Drop in, int holding, memory safe binary tree (C++)</a>  

## Puzzles & Problems

### Facebook
<a href="https://github.com/aeu/legible-algorithms/tree/master/facebook/balanced-brackets">Balance Brackets (C)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/facebook/balanced-split">Balanced Split (Obj-C)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/facebook/number-of-visible-nodes">Number of Visible Nodes (C)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/facebook/reverse-operations">Reverse Operations (Obj-C)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/facebook/reverse-operations-c">Reverse Operations C (C)</a>

### Leetcode

Leetcode has a funny subculture.  If you look at the solutions, you
will see very often things like "solution in 4 lines of C" or
"solution in two lines of python" and so on, which reminds me of the 
"Obfuscated C Code" contests from back in the day.

I get that this is fun to do (and I'm also envious as this is a skill
that I don't have).  My implementations are a little more verbose and
sometimes inconsistent, as my style has evolved over the years.

I've been going through the problems and solving them.  My solutions
are in a mix of Objective-C and C++ depending on what I was doing at
the time.

Recently I've started re-visiting my old solutions to see how they
held up to the test of time and improving their implementations as
I've learned more.  Some of my earlier implementations were really
bad, and I see this is a positive.  If I didn't think my old code was
bad, then that means I haven't been improving over time.


#### Hard


<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0004-median-of-two-sorted-arrays">Leetcode &numero; 4 (Hard) &mdash; Median of Two Sorted Arrays (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0023-merge-k-sorted-lists">Leetcode &numero; 23 (Hard) &mdash; Merge K Sorted Lists (Obj-C)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0025-reverse-nodes-in-k-group">Leetcode &numero; 25 (Hard) &mdash; Reverse Nodes in k-Group (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0030-substring-with-concatenation-of-all-words">Leetcode &numero; 30 (Hard) &mdash; Substring with concatenation of all words (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0041-first-missing-positive">Leetcode &numero; 41 (Hard) &mdash; First Missing Positive (C++)</a>.   
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0042-trapping-rain-water">Leetcode &numero; 42 (Hard) &mdash; Trapping Rain Water (C++)</a>.  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0051-n-queens">Leetcode &numero; 51 (Hard) &mdash; N-Queens (C++11)</a>.  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0052-n-queens-ii">Leetcode &numero; 52 (Hard) &mdash; N-Queens II (C++11)</a>.  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0060-permutation-sequence">Leetcode &numero; 60 (Hard) &mdash; Permutation Sequence (C++11,C++17)</a>.  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0068-text-justification">Leetcode &numero; 68 (Hard) &mdash; Text Justification (C++11,C++17)</a>.  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0076-minimum-window-substring">Leetcode &numero; 76 (Hard) &mdash; Minimum Window Substring(C++11,C++17)</a>.  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0084-largest-rectangle-in-histogram">Leetcode &numero; 84 (Hard) &mdash; Largest Rectangle in Histogram (C++11)   
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0085-maximal-rectangle">Leetcode &numero; 85 (Hard) &mdash; Maximal Rectangle (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0123-best-time-to-buy-and-sell-stock-iii">Leetcode &numero; 123 (Hard) &mdash; Best time to Buy and Sell Stock III (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0135-candy">Leetcode &numero; 135 (Hard) &mdash; Candy (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0149_max_points_on_a_line">Leetcode &numero; 149 (Hard) &mdash; Max Points on a Line (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0174-dungeon-game">Leetcode &numero; 174 (Hard) &mdash; Dungeon Game (C++)</a>   
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0188-best-time-to-buy-and-sell-stock-iv">Leetcode &numero; 188 (Hard) &mdash; Best time to Buy and Sell Stock IV(C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0218-the-skyline-problem">Leetcode &numero; 218 (Hard) &mdash; The Skyline Problem (Obj-C)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0233-number-of-digit-one">Leetcode &numero; 233 (Hard) &mdash; Number of Digit One (C++/Hard)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0239-sliding-window-maximum">Leetcode &numero; 239 (Hard) &mdash; Sliding Window Maximum(C++/Hard)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/1923-longest-common-subpath">Leetcode &numero; 1923 (Hard) &mdash; Longest Common Subpath (Obj-C)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/2106-maximum-fruits-harvested-after-at-most-k-steps">Leetcode &numero; 2106 (Hard) &mdash; Maximum Fruits Harvested After at Most K Steps (Obj-C)</a>  

#### Medium
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0002-add-two-numbers">Leetcode &numero; 2 (Medium) &mdash; Add two Numbers(C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0007-reverse-integer">Leetcode &numero; 7 (Medium) &mdash; Reverse Integer (C)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0008-string-to-integer-atoi">Leetcode &numero; 8 (Medium) &mdash; String to Integer (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0011-container-with-most-water">Leetcode &numero; 11 (Medium) &mdash; Container with Most Water (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0080-remove-duplicates-from-sorted-array-ii">Leetcode &numero; 80 (Medium) &mdash; Remove duplicates from Sorted Array II (C)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0151-reverse-words-in-a-string">Leetcode &numero; 151 (Medium) &mdash; Reverse Words in a String (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0238-product-of-array-except-self">Leetcode &numero; 238 (Medium) &mdash; Product of Array except Self (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0328-odd-even-linked-list">Leetcode &numero; 328 (Medium) &mdash; Odd Even Linked List (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0394-decode-string">Leetcode &numero; 394 (Medium) &mdash; Decode String (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0695-max-area-of-island">Leetcode &numero; 695 (Medium) &mdash; Max Area of Island (Obj-C)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0735-asteroid-collision">Leetcode &numero; 735 (Medium) &mdash; Asteroid Collision (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/1004-max-consecutive-ones-iii">Leetcode &numero; 1004 (Medium) &mdash; Max Consecutive Ones III (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/1456-maximum-number-of-vowels-in-a-subtring-of-given-length">Leetcode &numero; 1456 (Medium) &mdash; Maximum Number of Vowels in a Substring of Given Length (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/1493-longest-subarray-of-1s-after-deleting-one-element">Leetcode &numero; 1493 (Medium) &mdash; Longest Subarray of 1's after Deleting One Element (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/1679-max-number-of-k-sum-pairs">Leetcode &numero; 1679 (Medium) &mdash; Max Numbef of K-Sum Pairs(C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/2095-delete-the-middle-node-of-a-linked-list">Leetcode &numero; 2095 (Medium) &mdash; Delete the Middle Node of a Linked List (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/2104-sum-of-subarray-ranges">Leetcode &numero; 2104 (Medium) &mdash; Sum of Subarray Ranges (Obj-C)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/2130-maximum-twin-sum-of-a-linked-list">Leetcode &numero; 2130 (Medium) &mdash; Maximum Twin Sum of a Linked List (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/2352-equal-row-and-column-pairs">Leetcode &numero; 2352 (Medium) &mdash; Equal Row and Column Pairs (C++)</a>  


#### Easy

<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0104-maximum-depth-of-binary-tree">Leetcode &numero; 104 (Easy) &mdash; Maximum Depth of Binary Tree (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0206-reverse-linked-list">Leetcode &numero; 206 (Easy) &mdash; Reverse Linked List (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0283-move-zeroes">Leetcode &numero; 283 (Easy) &mdash; Move Zeroes (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0345-reverse-vowels-of-a-string">Leetcode &numero; 345 (Easy) &mdash; Reverse Vowels of a String (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0605-can-place-flowers">Leetcode &numero; 605 (Easy) &mdash; Can Place Flowers(C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0724-find-pivot-index/">Leetcode &numero; 724 (Easy) &mdash; Find Pivot Index (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/1071-greatest-common-divisor-of-strings/">Leetcode &numero; 1071 (Easy) &mdash; Greatest Common Divisor of Strings (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/1207-unique-number-of-occurrences/">Leetcode &numero; 1207 (Easy) &mdash; Unique Number of Occurrences (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/1732-find-the-highest-altitude/">Leetcode &numero; 1732 (Easy) &mdash; Find The Highest Altitude(C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/2215-find-the-difference-of-two-arrays/">Leetcode &numero; 2215 (Easy) &mdash; Find the Difference of Two Arrays (C++)</a>  

