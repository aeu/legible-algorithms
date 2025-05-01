# Legible Algorithms

When I get stuck on something, I like to solve puzzles and implement
algorithms as a form of focused distraction.  This is a collection of
my implementations of various things that I wrote to pass the time.
They are in C++ and Obj-C because I enjoy working on those
languages.

## Data Structures
The data structures we take for granted.  These were a lot more typing
than I expected.  The Red-Black tree especially was a lot of typing.
You see typically see it represented in books as about 20-30 lines of
pseudocode, but the reality is that it's way more than that,
especially if you are making it robust.


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

Binary tree is sort of optimized for leetcode, which uses an array in
the style of [1,2,null,4,6,7,null,8...] to represent the tree. I can't
use a vector of ints because of the nulls, and I don't want to use a
sentinel value which may occur in real data.  This implementation uses
std::optional, so you can put in std::nullopt in the data array.

<a href="https://github.com/aeu/legible-algorithms/tree/master/misc/binary-tree">Drop in, int holding, memory safe binary tree (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/misc/depth-first-search">Depth first search (C++)</a>  

An implementation of trie.  Never did one of these before, and it's
been a hole in my knowledge for some time now.  This was really fun to
learn how it worked.  Note that I still don't have delete working.

<a href="https://github.com/aeu/legible-algorithms/tree/master/misc/trie">Trie (C++)</a>


## Puzzles & Problems

### Meta

Puzzles and problems from the meta careers interview preparation portal.

#### Warmup

#### Level 1

<a href="https://github.com/aeu/legible-algorithms/tree/master/meta/cafeteria">Cafeteria (C++)</a>   
<a href="https://github.com/aeu/legible-algorithms/tree/master/meta/director-of-photography">Director of Photography (C++)</a>   
<a href="https://github.com/aeu/legible-algorithms/tree/master/meta/kaitenzushi">Kaitenzushi (C++)</a>   
<a href="https://github.com/aeu/legible-algorithms/tree/master/meta/rotary-lock">Rotary Lock (C++)</a>   
<a href="https://github.com/aeu/legible-algorithms/tree/master/meta/scoreboard-inference">Scoreboard Inference (C++)</a>   
<a href="https://github.com/aeu/legible-algorithms/tree/master/meta/stack-stabilization">Stack Stabilization (C++)</a>   
<a href="https://github.com/aeu/legible-algorithms/tree/master/meta/uniform-integers">Uniform Integers (C++)</a>   

#### Level 2

<a href="https://github.com/aeu/legible-algorithms/tree/master/meta/director-of-photography-chap-2">Director of Photography, Chapter 2 (C++)</a>   
<a href="https://github.com/aeu/legible-algorithms/tree/master/meta/portals">Portals (C++)</a>   
<a href="https://github.com/aeu/legible-algorithms/tree/master/meta/rotary-lock-chapter-2">Rotary Lock Chapter 2 (C++)</a>   

#### Preparation Hub

<a href="https://github.com/aeu/legible-algorithms/tree/master/meta/balance-brackets">Balance Brackets (C++)</a>   
<a href="https://github.com/aeu/legible-algorithms/tree/master/meta/balanced-split">Balanced Split (C++)</a>   
<a href="https://github.com/aeu/legible-algorithms/tree/master/meta/change-in-a-foreign-currency">Change in a Foreign Currency (C++)</a>   
<a href="https://github.com/aeu/legible-algorithms/tree/master/meta/contiguous-subarrays">Contiguous Subarrays (C++)</a>   
<a href="https://github.com/aeu/legible-algorithms/tree/master/meta/counting-triangles">Counting Triangles (C++)</a>   
<a href="https://github.com/aeu/legible-algorithms/tree/master/meta/encrypted-words">Encrypted Words (C++)</a>   
<a href="https://github.com/aeu/legible-algorithms/tree/master/meta/matching-pairs">Matching Pairs (C++)</a>    
<a href="https://github.com/aeu/legible-algorithms/tree/master/meta/minimum-length-substrings">Minimum Length Substrings (C++)</a>   
<a href="https://github.com/aeu/legible-algorithms/tree/master/meta/number-of-visible-nodes">Number of Visible Nodes (C++)</a>   
<a href="https://github.com/aeu/legible-algorithms/tree/master/meta/one-billion-users">One Billion Users (C++)</a>   
<a href="https://github.com/aeu/legible-algorithms/tree/master/meta/pair-sums">Pair Sums (C++)</a>   
<a href="https://github.com/aeu/legible-algorithms/tree/master/meta/revenue-milestones">Revenue Milestones (C++)</a>   
<a href="https://github.com/aeu/legible-algorithms/tree/master/meta/reverse-to-make-equal">Reverse To Make Equal (C++)</a>   
<a href="https://github.com/aeu/legible-algorithms/tree/master/meta/rotational-cipher">Rotational Cipher (C++)</a>   
<a href="https://github.com/aeu/legible-algorithms/tree/master/meta/slow-sums">slow-sums (C++)</a>   


### Leetcode

Solutions are in a mix of Objective-C and C++ depending on what I was
doing at the time.  These days it's mostly C++.

Recently I've started re-visiting my old solutions to see how they
held up to the test of time and improving their implementations as
I've learned more.

Some of my earlier implementations were really bad.  Like really,
really, really bad.

As I go over these I have to keep reminding myself that this is a good
thing.  If I didn't look back at my code years later and see that it
was bad, then that means that I haven't improved since I wrote it.


#### Easy


<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0001-two-sum">Leetcode &numero; 1 (Easy) &mdash; Two Sum (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0020-valid-parentheses">Leetcode &numero; 20 (Easy) &mdash; Valid Parentheses (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0021-merge-two-sorted-lists">Leetcode &numero; 21 (Easy) &mdash; Merge Two Sorted Lists (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0026-remove-duplicates-from-sorted-array">Leetcode &numero; 26 (Easy) &mdash; Remove Duplicates from Sorted Array (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0027-remove-element">Leetcode &numero; 27 (Easy) &mdash; Remove Element (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0035-search-insert-position">Leetcode &numero; 35 (Easy) &mdash; Search Insert Position (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0088-merge-sorted-array">Leetcode &numero; 88 (Easy) &mdash; Merge Sorted Array (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0100-same-tree">Leetcode &numero; 100 (Easy) &mdash; Same Tree (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0101-symmetric-tree">Leetcode &numero; 101 (Easy) &mdash; Symmetric Tree (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0104-maximum-depth-of-binary-tree">Leetcode &numero; 104 (Easy) &mdash; Maximum Depth of Binary Tree (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0112-path-sum">Leetcode &numero; 112 (Easy) &mdash; Path Sum (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0118-pascals-triangle">Leetcode &numero; 118 (Easy) &mdash; Pascal's Triangle (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0121-best-time-to-buy-and-sell-stock">Leetcode &numero; 121 (Easy) &mdash; Best Time to Buy and Sell Stock (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0125-valid-palindrome">Leetcode &numero; 125 (Easy) &mdash; Valid Palindrome (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0136-single-number">Leetcode &numero; 136 (Easy) &mdash; Single Number (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0141-linked-list-cycle">Leetcode &numero; 141 (Easy) &mdash; Linked List Cycle (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0169-majority-element">Leetcode &numero; 169 (Easy) &mdash; Majority Element (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0202-happy-number">Leetcode &numero; 202 (Easy) &mdash; Happy Number (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0205-isomorphic-strings">Leetcode &numero; 205 (Easy) &mdash; Isomorphic Strings (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0206-reverse-linked-list">Leetcode &numero; 206 (Easy) &mdash; Reverse Linked List (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0219-contains-duplicate-ii">Leetcode &numero; 219 (Easy) &mdash; Contains Duplicate (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0222-count-complete-tree-nodes">Leetcode &numero; 222 (Easy) &mdash; Count Complete Tree Nodes (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0226-invert-binary-tree">Leetcode &numero; 226 (Easy) &mdash; Invert Binary Tree (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0242-valid-anagram">Leetcode &numero; 242 (Easy) &mdash; Valid Anagram (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0283-move-zeroes">Leetcode &numero; 283 (Easy) &mdash; Move Zeroes (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0290-word-pattern">Leetcode &numero; 290 (Easy) &mdash; Word Pattern (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0303-range-sum-query-immutable">Leetcode &numero; 303 (Easy) &mdash; Range Sum Query Immutable (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0338-counting-bits">Leetcode &numero; 338 (Easy) &mdash; Counting Bits (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0345-reverse-vowels-of-a-string">Leetcode &numero; 345 (Easy) &mdash; Reverse Vowels of a String (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0346-moving-average-from-data-stream">Leetcode &numero; 346 (Easy) &mdash; Moving Average From Data Stream (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0349-intersection-of-two-arrays">Leetcode &numero; 349 (Easy) &mdash; Intersection of Two Arrays (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0374-guess-number-higher-or-lower">Leetcode &numero; 374 (Easy) &mdash; Guess Number Higher or Lower (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0383-ransom-note">Leetcode &numero; 383 (Easy) &mdash; Ransom Note (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0392-is-subsequence">Leetcode &numero; 392 (Easy) &mdash; Is Subsequence (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0408-valid-word-abbreviation">Leetcode &numero; 408 (Easy) &mdash; Valid Word Abbreviation (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0415-add-strings">Leetcode &numero; 415 (Easy) &mdash; Add Strings (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0496-next-greater-element-i">Leetcode &numero; 496 (Easy) &mdash; Next Greater Element I (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0543-diameter-of-binary-tree">Leetcode &numero; 543 (Easy) &mdash; Diameter of Binary Tree (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0605-can-place-flowers">Leetcode &numero; 605 (Easy) &mdash; Can Place Flowers(C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0637-average-of-levels-in-binary-tree">Leetcode &numero; 637 (Easy) &mdash; Average of Levels in Binary Tree (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0643-maximum-average-subarray-i">Leetcode &numero; 643 (Easy) &mdash; Maximum Average Subarray I (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0680-valid-palindrome-ii">Leetcode &numero; 680 (Easy) &mdash; Valid Palindrome (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0700-search-in-a-binary-search-tree/">Leetcode &numero; 700 (Easy) &mdash; Sarch in a Binary Search Tree (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0724-find-pivot-index/">Leetcode &numero; 724 (Easy) &mdash; Find Pivot Index (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0872-leaf-similar-trees/">Leetcode &numero; 872 (Easy) &mdash; Leav Similar Trees (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0933-number-of-recent-calls">Leetcode &numero; 933 (Easy) &mdash; Number of Recent Calls (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0938-range-sum-of-bst">Leetcode &numero; 938 (Easy) &mdash; Range Sum of BST (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0977-squares-of-a-sorted-array">Leetcode &numero; 977 (Easy) &mdash; Squares of a Sorted Array (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/1071-greatest-common-divisor-of-strings/">Leetcode &numero; 1071 (Easy) &mdash; Greatest Common Divisor of Strings (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/1207-unique-number-of-occurrences/">Leetcode &numero; 1207 (Easy) &mdash; Unique Number of Occurrences (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/1480-running-sum-of-1d-array">Leetcode &numero; 1480 (Easy) &mdash; Running Sum of 1D Array (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/1539-kth-missing-positive-number">Leetcode &numero; 1539 (Easy) &mdash; Kth Missing Positive Number (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/1732-find-the-highest-altitude/">Leetcode &numero; 1732 (Easy) &mdash; Find The Highest Altitude(C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/2215-find-the-difference-of-two-arrays/">Leetcode &numero; 2215 (Easy) &mdash; Find the Difference of Two Arrays (C++)</a>  


#### Medium


<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0002-add-two-numbers">Leetcode &numero; 2 (Medium) &mdash; Add two Numbers (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0003-longest-substring-without-repeating-characters">Leetcode &numero; 3 (Medium) &mdash; Longest Substring Without Repeating Characters (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0005-longest-palindromic-substring">Leetcode &numero; 5 (Medium) &mdash; Longest Palindromic Substring (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0007-reverse-integer">Leetcode &numero; 7 (Medium) &mdash; Reverse Integer (C)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0008-string-to-integer-atoi">Leetcode &numero; 8 (Medium) &mdash; String to Integer (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0011-container-with-most-water">Leetcode &numero; 11 (Medium) &mdash; Container with Most Water (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0015-3sum">Leetcode &numero; 15 (Medium) &mdash; 3Sum (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0017-letter-combinations-of-a-phone-number">Leetcode &numero; 17 (Medium) &mdash; Letter Combinations of a Phone Number (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0019-remove-nth-node-from-end-of-list">Leetcode &numero; 19 (Medium) &mdash; Remove Nth Node From End of List (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0022-generate-parentheses">Leetcode &numero; 22 (Medium) &mdash; Generate Prentheses (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0024-swap-nodes-in-pairs">Leetcode &numero; 24 (Medium) &mdash; Swap Nodes in Pairs (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0033-search-in-rotated-sorted-array">Leetcode &numero; 33 (Medium) &mdash; Search in Rotated Sorted Array (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0034-find-first-and-last-position-of-element-in-sorted-array">Leetcode &numero; 34 (Medium) &mdash; Find First an Last Position of Element in Sorted Array (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0036-valid-sudoku">Leetcode &numero; 36 (Medium) &mdash; Valid Sudoku (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0039-combination-sum">Leetcode &numero; 39 (Medium) &mdash; Combination Sum (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0040-combination-sum-ii">Leetcode &numero; 40 (Medium) &mdash; Combination Sum II (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0047-permutations-ii">Leetcode &numero; 47 (Medium) &mdash; Permutations II (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0048-rotate-image">Leetcode &numero; 48 (Medium) &mdash; Rotate Image (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0049-group-anagrams">Leetcode &numero; 49 (Medium) &mdash; Group Anagrams (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0050-pow">Leetcode &numero; 50 (Medium) &mdash; Pow (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0053-maximum-subarray">Leetcode &numero; 53 (Medium) &mdash; Maximum Subarray (C++)</a>
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0054-spiral-matrix">Leetcode &numero; 54 (Medium) &mdash; Spiral Matrix (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0055-jump-game">Leetcode &numero; 55 (Medium) &mdash; Jump Game (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0056-merge-intervals">Leetcode &numero; 56 (Medium) &mdash; Merge Intervals (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0061-rotate-list">Leetcode &numero; 61 (Medium) &mdash; Rotate List (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0071-simplify-path">Leetcode &numero; 71 (Medium) &mdash; Simplify Path (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0073-set-matrix-zeroes">Leetcode &numero; 73 (Medium) &mdash; Set Matrix Zeroes (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0074-search-a-2d-matrix">Leetcode &numero; 74 (Medium) &mdash; Search a 2D Matrix (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0075-sort-colors">Leetcode &numero; 75 (Medium) &mdash; Sort Colors (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0077-combinations">Leetcode &numero; 77 (Medium) &mdash; Combinations (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0078-subsets">Leetcode &numero; 78 (Medium) &mdash; Subsets (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0079-word-search">Leetcode &numero; 79 (Medium) &mdash; Word Search (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0080-remove-duplicates-from-sorted-array-ii">Leetcode &numero; 80 (Medium) &mdash; Remove duplicates from Sorted Array II (C)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0082-remove-duplicates-from-sorted-list-ii">Leetcode &numero; 82 (Medium) &mdash; Remove Duplicates from Sorted List II II (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0090-subsets-ii">Leetcode &numero; 90 (Medium) &mdash; Subsets II (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0092-reverse-linked-list-ii">Leetcode &numero; 92 (Medium) &mdash; Reverse Linked List II (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0093-restore-ip-addresses">Leetcode &numero; 93 (Medium) &mdash; Restore IP Addresses (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0098-validate-binary-search-tree">Leetcode &numero; 98 (Medium) &mdash; Validate Binary Search Tree (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0102-binary-tree-level-order-traversal">Leetcode &numero; 102 (Medium) &mdash; Binary Tree Level Order Traversal (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0103-binary-tree-zigzag-level-order-traversal">Leetcode &numero; 103 (Medium) &mdash; Binary Tree ZigZag Level Order Traversal (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0105-construct-binary-tree-from-preorder-and-inorder-traversal">Leetcode &numero; 105 (Medium) &mdash; Construct Binary Tree from Preorder and Inorder traversal (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0116-populating-next-right-pointers-in-each-node">Leetcode &numero; 116 (Medium) &mdash; Populating Next Right Pointers in Each Node (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0117-populating-next-right-pointers-in-each-node-ii">Leetcode &numero; 117 (Medium) &mdash; Populating Next Right Pointers in Each Node II (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0122-best-time-to-buy-and-sell-stock-ii">Leetcode &numero; 122 (Medium) &mdash; Best Time to Buy and Sell Stock II (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0128-longest-consequtive-sequence">Leetcode &numero; 128 (Medium) &mdash; Longest Consecutive Sequence (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0129-sum-root-to-leaf-numbers">Leetcode &numero; 129 (Medium) &mdash; Sum Root to Leaf Numbers (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0130-surrounded-regions">Leetcode &numero; 130 (Medium) &mdash; Surrounded Regions (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0131-palindrome-partitioning">Leetcode &numero; 131 (Medium) &mdash; Palindrome Partitioning (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0133-clone-graph">Leetcode &numero; 0133 (Medium) &mdash; Clone Graph (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0134-gas-station">Leetcode &numero; 134 (Medium) &mdash; Gas Station (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0138-copy-list-with-random-pointer">Leetcode &numero; 138 (Medium) &mdash; Copy List with Random Pointer (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0139-word-break">Leetcode &numero; 139 (Medium) &mdash; Word Break (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0146-lru-cache">Leetcode &numero; 146 (Medium) &mdash; LRU Cache (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0150-evaluate-reverse-polish-notation">Leetcode &numero; 150 (Medium) &mdash; Evaluate Reverse Polish Notation (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0151-reverse-words-in-a-string">Leetcode &numero; 151 (Medium) &mdash; Reverse Words in a String (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0155-min-stack">Leetcode &numero; 155 (Medium) &mdash; Min Stack (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0162-find-peak-element">Leetcode &numero; 162 (Medium) &mdash; Find Peak Element (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0167-two-sum-ii">Leetcode &numero; 167 (Medium) &mdash; Two Sum II - Input Array is Sorted (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0189-rotate-array">Leetcode &numero; 189 (Medium) &mdash; Rotate Array (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0198-house-robber">Leetcode &numero; 198 (Medium) &mdash; House Robber (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0199-binary-tree-right-side-view">Leetcode &numero; 199 (Medium) &mdash; Binary Tree Right Side View (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0200-number-of-islands">Leetcode &numero; 200 (Medium) &mdash; Number of Islands (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0207-course-schedule">Leetcode &numero; 207 (Medium) &mdash; Course Schedule (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0209-minimum-size-subarray-sum">Leetcode &numero; 209 (Medium) &mdash; Minimum Size Subarray Sum (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0210-course-schedule-ii">Leetcode &numero; 210 (Medium) &mdash; Course Schedule II (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0215-kth-largest-element-in-an-array">Leetcode &numero; 215 (Medium) &mdash; Kth Largest Element in an Array (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0236-lowest-common-ancestor-of-a-binary-tree">Leetcode &numero; 236 (Medium) &mdash; Lowest Commong Ancestor of a Binary Tree (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0238-product-of-array-except-self">Leetcode &numero; 238 (Medium) &mdash; Product of Array except Self (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0274-h-index">Leetcode &numero; 274 (Medium) &mdash; H-Index (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0289-game-of-life">Leetcode &numero; 289 (Medium) &mdash; Game of Life (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0314-binary-tree-vertical-order-traversal">Leetcode &numero; 314 (Medium) &mdash; Binary Tree Vertical Order Traversal (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0325-maxium-size-subarray-sum-equals-k">Leetcode &numero; 325 (Medium) &mdash; Maximum Size Subarray Sum Equals K (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0328-odd-even-linked-list">Leetcode &numero; 328 (Medium) &mdash; Odd Even Linked List (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0328-odd-even-linked-list">Leetcode &numero; 328 (Medium) &mdash; Odd Even Linked List (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0334-increasing-triplet-subsequence">Leetcode &numero; 334 (Medium) &mdash; Increasing Triplet Subsequence (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0347-top-k-frequent-elements">Leetcode &numero; 347 (Medium) &mdash; Top K Frequent Elements (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0394-decode-string">Leetcode &numero; 394 (Medium) &mdash; Decode String (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0399-evaluate-division">Leetcode &numero; 399 (Medium) &mdash; Evaluate Division (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0406-queue-reconstruction-by-height">Leetcode &numero; 406 (Medium) &mdash; Queue Reconstruction by Height (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0417-pacific-island-water-flow">Leetcode &numero; 417 (Medium) &mdash; Pacific Island Water Flow (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0433-minimum-genetic-mutation">Leetcode &numero; 433 (Medium) &mdash; Minimum Genetic Mutation (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0437-path-sum-iii">Leetcode &numero; 437 (Medium) &mdash; Path Sum III (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0450-delete-node-in-a-bst">Leetcode &numero; 450 (Medium) &mdash; Delete Node in a BST (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0452-minimum-number-of-arrows-to-burst-balloons">Leetcode &numero; 452 (Medium) &mdash; Minimum number of arrows to burst balloons (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0498-diagonal-traverse">Leetcode &numero; 498 (Medium) &mdash; Diagonal Traverse (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0523-continuous-subarray-sum">Leetcode &numero; 523 (Medium) &mdash; Continuous Subarray Sum (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0525-contiguous-array">Leetcode &numero; 525 (Medium) &mdash; Contiguous Array (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0542-01-matrix">Leetcode &numero; 542 (Medium) &mdash; 1 Matrix (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0547-number-of-provinces">Leetcode &numero; 547 (Medium) &mdash; Number of Provinces (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0560-subarray-sum-equals-k">Leetcode &numero; 560 (Medium) &mdash; Subarray Sum Equals K (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0649-dota2-senate">Leetcode &numero; 649 (Medium) &mdash; Dota2 Senate (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0670-maximum-swap">Leetcode &numero; 670 (Medium) &mdash; Maximum Swap (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0684-redundant-connection">Leetcode &numero; 684 (Medium) &mdash; Redundant Connection (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0695-max-area-of-island">Leetcode &numero; 695 (Medium) &mdash; Max Area of Island (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0735-asteroid-collision">Leetcode &numero; 735 (Medium) &mdash; Asteroid Collision (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0739-daily-temperatures">Leetcode &numero; 739 (Medium) &mdash; Daily Temperature (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0763-partition-labels">Leetcode &numero; 763 (Medium) &mdash; Partition Labels (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0791-custom-sort-string">Leetcode &numero; 791 (Medium) &mdash; Custom Sort String (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0797-all-paths-from-source-to-target">Leetcode &numero; 797 (Medium) &mdash; All Paths from Source to Target (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0802-find-eventual-safe-states">Leetcode &numero; 802 (Medium) &mdash; Find Eventual Safe States (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0841-keys-and-rooms">Leetcode &numero; 841 (Medium) &mdash; Keys &amp; Rooms (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0875-koko-eating-bananas">Leetcode &numero; 875 (Medium) &mdash; Koko eating bananas (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0907-sum-of-subarray-minimums">Leetcode &numero; 907 (Medium) &mdash; Sum of Subarray Minimums (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0930-binary-subarrays-with-sum">Leetcode &numero; 930 (Medium) &mdash; Binary Subarrays With Sum (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0973-k-closest-points-to-origin">Leetcode &numero; 973 (Medium) &mdash; K closest points to origin (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0974-subarray-sums-divisible-by-k">Leetcode &numero; 974 (Medium) &mdash; Subarray Sums Divisible by K (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0986-interval-list-intersections">Leetcode &numero; 986 (Medium) &mdash; Interval List Intersections (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0994-rotting-oranges">Leetcode &numero; 994 (Medium) &mdash; Rotting Oranges (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/1004-max-consecutive-ones-iii">Leetcode &numero; 1004 (Medium) &mdash; Max Consecutive Ones III (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/1091-shortest-path-in-binary-matrix">Leetcode &numero; 1091 (Medium) &mdash; Shortest Path in Binary Matrix (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/1161-maximum-level-sum-of-binary-tree">Leetcode &numero; 1161 (Medium) &mdash; Maximum Level Sum of Binary Tree (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/1248-count-number-of-nice-subarrays">Leetcode &numero; 1248 (Medium) &mdash; Count Number of Nice Subarrays (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/1249-minimum-remove-to-make-valid-parentheses">Leetcode &numero; 1249 (Medium) &mdash; Minimum Remove to Make Valide Parentheses (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/1372-longest-zigzag-path-in-a-binary-tree">Leetcode &numero; 1372 (Medium) &mdash; Longest ZigZag Path in a Binary Tree (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/1448-count-good-nodes-in-binary-tree">Leetcode &numero; 1448 (Medium) &mdash; Count Good Nodes in Binary Tree (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/1456-maximum-number-of-vowels-in-a-subtring-of-given-length">Leetcode &numero; 1456 (Medium) &mdash; Maximum Number of Vowels in a Substring of Given Length (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/1466-reorder-routes-to-make-all-paths-lead-to-the-city-zero">Leetcode &numero; 1466 (Medium) &mdash; Re-order routes to make all paths lead to the city zero (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/1493-longest-subarray-of-1s-after-deleting-one-element">Leetcode &numero; 1493 (Medium) &mdash; Longest Subarray of 1's after Deleting One Element (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/1570-dot-product-of-two-sparse-vectors">Leetcode &numero; 1570 (Medium) &mdash; Dot Product of Two Sparse Vectors (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/1584-min-cost-to-connect-all-points">Leetcode &numero; 1584 (Medium) &mdash; Min Cost to Connect All Points (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/1650-lowest-common-ancestor-of-a-binary-tree-iii">Leetcode &numero; 1650 (Medium) &mdash; Lowest Common Ancestor of a Binary Tree III (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/1657-determine-if-two-strings-are-close">Leetcode &numero; 1657 (Medium) &mdash; Determine if two strings are close (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/1679-max-number-of-k-sum-pairs">Leetcode &numero; 1679 (Medium) &mdash; Max Numbef of K-Sum Pairs(C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/1762-buildings-with-an-ocean-view">Leetcode &numero; 1762 (Medium) &mdash; Buildings with an Ocean View (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/1926-nearest-exit-from-entrance-in-maze">Leetcode &numero; 1926 (Medium) &mdash; Nearest Exit From Entrance In Maze (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/2095-delete-the-middle-node-of-a-linked-list">Leetcode &numero; 2095 (Medium) &mdash; Delete the Middle Node of a Linked List (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/2104-sum-of-subarray-ranges">Leetcode &numero; 2104 (Medium) &mdash; Sum of Subarray Ranges (Obj-C)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/2130-maximum-twin-sum-of-a-linked-list">Leetcode &numero; 2130 (Medium) &mdash; Maximum Twin Sum of a Linked List (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/2300-successful-pairs-of-spells-and-potions">Leetcode &numero; 2300 (Medium) &mdash; Successful Pairs of Spells and Potions (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/2336-smallest-number-in-infinite-set">Leetcode &numero; 2336 (Medium) &mdash; Smallets Number in an Infinite Set (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/2352-equal-row-and-column-pairs">Leetcode &numero; 2352 (Medium) &mdash; Equal Row and Column Pairs (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/3294-convert-doubly-linked-list-to-array-ii">Leetcode &numero; 3294 (Medium) &mdash; Convert Doubly Linked List To Array II (C++)</a>  

#### Hard


<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0023-merge-k-sorted-lists">Leetcode &numero; 23 (Hard) &mdash; Merge K Sorted Lists (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0025-reverse-nodes-in-k-group">Leetcode &numero; 25 (Hard) &mdash; Reverse Nodes in K Group (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0068-text-justification">Leetcode &numero; 68 (Hard) &mdash; Text Justification (C++11,C++17)</a>.  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0076-minimum-window-substring">Leetcode &numero; 76 (Hard) &mdash; Minimum Window Substring (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0084-largest-rectangle-in-histogram">Leetcode &numero; 84 (Hard) &mdash; Largest Rectangle in Histogram (C++11)   
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0124-binary-tree-maximum-path-sum">Leetcode &numero; 124 (Hard) &mdash; Binary Tree Maximum Path Sum (C++)</a>.  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0127-word-ladder">Leetcode &numero; 127 (Hard) &mdash; Word Ladder (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0329-longest-increasing-path-in-a-matrix">Leetcode &numero; 329 (Hard) &mdash; Longest Increasing Path in a Matrix (C++)</a>.  
<a href="https://github.com/aeu/legible-algorithms/tree/master/leetcode/0987-vertical-order-traversal-of-a-binary-tree">Leetcode &numero; 987 (Hard) &mdash; Vertical Order Traversal of a Binary Tree (C++)</a>  


### Beyond Cracking The Coding Interview
Solutions to problems from the book.  Organized by category/chapter.

#### CH 27 &mdash; Two Pointers
<a href="https://github.com/aeu/legible-algorithms/tree/master/bctci/two-pointers/array-intersection">27.3 &mdash; Array Intersection (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/bctci/two-pointers/palindromic-sentence">27.4 &mdash; Palindromic Sentence (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/bctci/two-pointers/smaller-prefixes">27.2 &mdash; Smaller Prefixes (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/bctci/two-pointers/reverse-case-match">27.5 &mdash; Reverse Case Match (C++)</a>  

#### CH 28 &mdash; Grids &amp; Matrices

<a href="https://github.com/aeu/legible-algorithms/tree/master/bctci/grids-and-matrices/spiral-order">28.3 &mdash; Spiral Order (C++)</a>  

#### CH 32 &mdash; Stacks &amp; Queues

<a href="https://github.com/aeu/legible-algorithms/tree/master/bctci/stacks-and-queues/compress-array">32.1 &mdash; Compress Array (C++)</a>  
<a href="https://github.com/aeu/legible-algorithms/tree/master/bctci/stacks-and-queues/custom-brackets">32.7 &mdash; Custom Brackets (C++)</a>  

#### CH 36 &mdash; Graphs

<a href="https://github.com/aeu/legible-algorithms/tree/master/bctci/graphs/graph-path">36.2 Graph Path (C++)</a>  

