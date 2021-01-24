#!/usr/bin/python

class Solution:
    # @return an integer
    def pat(self, s, t):
      if t == '': return 1
      if len(s) < len(t): return 0
      sum = 0
      for i in range(0, len(s)):
        if s[i] == t[0]:
          sum += self.pat(s[i+1:], t[1:])
      return sum
    
    def numDistinct(self, S, T):
      return self.pat(S, T)

sln = Solution()
print sln.pat('rabbbit', 'rabbit')
