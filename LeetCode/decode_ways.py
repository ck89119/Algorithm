#!/usr/bin/python

class Solution:
    # @param s, a string
    # @return an integer
    def numDecodings(self, s):
      if len(s) == 0: return 0
      if s[0] == '0': return 0
      ans = []
      ans.append(1)
      ans.append(1)
      i = 1
      while i < len(s):
        tmp = 0
        if s[i] != '0':
          tmp += ans[-1]
        if s[i-1] == '1' or s[i-1] == '2' and s[i] <= '6':
          tmp += ans[-2]
        ans.append(tmp)
        i += 1
      return ans[len(s)]
