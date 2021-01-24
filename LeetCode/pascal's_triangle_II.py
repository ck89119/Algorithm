#!/usr/bin/python

class Solution:
    # @return a list of integers
    def getRow(self, rowIndex):
      ans = [1]
      i = 0
      while i < rowIndex:
        ans.append(1)
        j = len(ans) - 2
        while j > 0:
          ans[j] += ans[j-1]
          j -= 1
        i += 1
      return ans
