#!/usr/bin/python

class Solution:
    # @return a list of lists of integers
    def generate(self, numRows):
      if numRows == 0: return []
      f = []
      f.append(1)
      ans = []
      ans.append(f)
      for i in range(1, numRows):
        f = []
        f.append(1)
        for j in range(1, i):
          f.append(ans[i-1][j]+ans[i-1][j-1])
        f.append(1)
        ans.append(f)
      return ans
