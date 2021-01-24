#!/usr/bin/python

class Solution:
    # @return a string
    def getPermutation(self, n, k):
      fac = [1]
      for i in range(1, n):
        fac.append(fac[-1]*i)
      small = [0]
      for i in range(1, n+1):
        small.append(i)
      s = ''
      k -= 1
      i = n-1
      while (i >= 0):
        a = k / fac[i]
        s += str(small[a]+1)
        small.remove(small[a])
        k %= fac[i]
        i -= 1
      return s

sln = Solution()
print sln.getPermutation(3, 3)
