# Leetcode No. 25.  Reverse Nodes in k-Group

Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

## Example 1:
![reverse_ex1](https://user-images.githubusercontent.com/2225377/184763334-bf77541d-33cd-468e-b10e-ce01d4ad323d.jpeg)

Input: head = [1,2,3,4,5], k = 2

Output: [2,1,4,3,5]


## Example 2:
![reverse_ex2](https://user-images.githubusercontent.com/2225377/184763412-7378bd7f-f459-4a80-94c6-1988653de684.jpeg)

Input: head = [1,2,3,4,5], k = 3

Output: [3,2,1,4,5]

## Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000
 

Follow-up: Can you solve the problem in O(1) extra memory space?

## Output

make &>/dev/null; ./rnikg

Reverse Nodes in k-Group

[1,2,3,4,5]

[2,1,4,3,5]

[1,2,3,4,5]

[3,2,1,4,5]




## Notes
This is fairly straightforward, mainly you need to understand how linked lists work, and it teaches a bit about memory management.  There is one edge case you have to look out for, which is if the nodes in the list being swapped are directly following each other.  If they are, then you can end up in an endless loop ( A->next is A) which will make your program fail.

