#!/usr/bin/python

class Solution:
    # @return a list of integers
    def grayCode(self, n):
      if n == 0: return [0]
      ans = []
      ans.append(0)
      ans.append(1)
      i = 2 
      while i < n+1:
        base = 2 ** (i-1)
        j = base - 1
        while j >= 0:
          ans.append(base+ans[j])
          j -= 1
        i += 1
      return ans
