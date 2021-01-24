#!/usr/bin/python

class Solution:
    # @param n, an integer
    # @return an integer
    def climbStairs(self, n):
      if n < 2: return 1
      f = []
      f.append(1)
      f.append(1)
      for i in range(2, n+1):
        ans = f[-1] + f[-2]
        f.append(ans)
      return f[n]
