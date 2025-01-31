## Leetcode #0174 Dungeon Game

## Description:

The demons had captured the princess and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of m x n rooms laid out in a 2D grid. Our valiant knight was initially positioned in the top-left room and must fight his way through dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons (represented by negative integers), so the knight loses health upon entering these rooms; other rooms are either empty (represented as 0) or contain magic orbs that increase the knight's health (represented by positive integers).

To reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

Return the knight's minimum initial health so that he can rescue the princess.

Note that any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.

 

### Example 1:


      Input: dungeon = [[-2,-3,3],[-5,-10,1],[10,30,-5]]
      Output: 7
      Explanation: The initial health of the knight must be at least 7 if he follows the optimal path: RIGHT-> RIGHT -> DOWN -> DOWN.


### Example 2:

      Input: dungeon = [[0]]
      Output: 1
 

### Constraints:

      m == dungeon.length
      n == dungeon[i].length
      1 <= m, n <= 200
      -1000 <= dungeon[i][j] <= 1000


### Solution

So this problem can be solved in two ways, either as a tree search problem or a permutations problem.  I went with permutations because it's easier.  For a nxn dungeon, the path to the exit is n-1 right and n-1 down.  So for a 3x3 dungeon it would be (for example) RRRDDD.   If you generate all the permutations of those movements (RDRRDD, DDDRRR,...) then you have all possible paths, then you can calculate the health and solve the problem.

There is one thing I ran into which was that I had extra permutations for sequential moves.  For example if I had RRDD, I would get RDRD and RDRD which would look the same except they are actually different as in each case the Rs would be positions.  (As in R0D0R1D1, R1D1R0D0, R1D0R2D1,... )  I considered using a set (or similar) data structure to store the paths which would remove those duplicates, except then it would OLogn for the insert vs. the traversal which would linear.  A future optimization would be to use that data structure if the traversal was very slow. 

### Output

      alfonso@maraval 0174-dungeon-game % ./dungeon_game 
      Given the following dungeon:
      [-2, -3, 3]
      [-5, -10, 1]
      [10, 30, -5]
      Minimum initial health to traverse the dungeon is 7
      Given the following dungeon:
      [0]
      Minimum initial health to traverse the dungeon is 1



