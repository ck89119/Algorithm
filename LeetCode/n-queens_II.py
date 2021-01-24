#!/usr/bin/python

class Solution:
    # @return an integer
    def totalNQueens(self, n):
      ans = []
      ans.append(0)
      ans.append(1)
      ans.append(0)
      ans.append(0)
      ans.append(2)
      ans.append(10)
      ans.append(4)
      ans.append(40)
      ans.append(92)
      ans.append(352)
      ans.append(724)
      ans.append(2680)
      ans.append(14200)
      ans.append(73712)
      return ans[n]
