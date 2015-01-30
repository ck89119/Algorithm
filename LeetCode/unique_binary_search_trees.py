#!/usr/bin/python

class Solution:
    # @return an integer
    def numTrees(self, n):
      f = []
      f.append(1)
      i = 1;
      while i <= n:
        sum = 0
        j = 0
        while j < i:
          sum += f[j] * f[i-1-j]
          j += 1
        f.append(sum)
        i += 1
      return f[n]
        
