#!/usr/bin/python

class Solution:
    # @param s, a string
    # @return a list of lists of string

    def isPalindrome(self, s, l, r):
      if self.ok[l][r] != -1:
        return self.ok[l][r]
      
      if r - l <= 0:
        self.ok[l][r] = 1
        return self.ok[l][r]
      
      if s[l] != s[r]:
        self.ok[l][r] = 0
      else:
        self.ok[l][r] = self.isPalindrome(s, l+1, r-1)
      
      return self.ok[l][r]

    def dfs(self, s, cut, k, cur):
      if k == cut:
        if self.isPalindrome(s, cur, len(s)-1) == 1:
          return True
        else:
          return False

      i = len(s) - cur
      while i > 0:
        if self.isPalindrome(s, cur, cur+i-1) == 1:
          if self.dfs(s, cut, k+1, cur+i):
            return True
        i -= 1
      return False
      
    def minCut(self, s):
      self.ok = [[-1 for j in range(len(s))] for i in range(len(s))]
      i = 0
      while True:
        if self.dfs(s, i, 0, 0):
          return i
        i += 1

ss = Solution()
s = 'aabc'
print ss.minCut(s)
      
