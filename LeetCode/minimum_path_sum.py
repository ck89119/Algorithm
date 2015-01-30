#!/usr/bin/python

class Solution:
    # @param grid, a list of lists of integers
    # @return an integer
    def minPathSum(self, grid):
      if len(grid) == 0: return 0
      n = len(grid)
      m = len(grid[0])
      for i in range(0, n):
        for j in range(0, m):
          if i == 0 and j == 0: continue
          d = 9999999
          if i - 1 >= 0:
            d = min(d, grid[i-1][j])
          if j - 1 >= 0:
            d = min(d, grid[i][j-1])
          grid[i][j] += d
      return grid[n-1][m-1]
