#!/usr/bin/python

class Solution:
    # @return an integer
    def uniquePaths(self, m, n):
      ans = []
      row = []
      for i in range(0, n):
        row.append(1)
      ans.append(row)
      for i in range(1, m):
        row = [1]
        ans.append(row)
      for i in range(1, m):
        for j in range(1, n):
          p = ans[i][j-1] + ans[i-1][j]
          ans[i].append(p)
      return ans[m-1][n-1]

