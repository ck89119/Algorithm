#!/usr/bin/python

class Solution:
    # @return a string
    def search(self, s, l, r):
      if self.f[l][r] != -1:
        return self.f[l][r]
      if r - l <= 0:
        self.f[l][r] = 1
        return self.f[l][r]

      if s[l] != s[r]:
        self.f[l][r] = 0
      else:
        self.f[l][r] = self.search(s, l+1, r-1)
      return self.f[l][r]
    
    def longestPalindrome(self, s):
      n = len(s)
      self.f = [[-1 for j in range(n)] for i in range(n)]
      if self.search(s, 0, n-1) == 1:
        return s
      l = 1
      r = n
      while l+1 < r:
        maxlen = (l + r) / 2
        i = 0
        flag = False
        while i + maxlen - 1 < n:
          if self.search(s, i, i+maxlen-1) == 1:
            flag = True
            break
          i += 1
        if flag:
          l = maxlen
        else:
          r = maxlen
      i = 0
      while i + l - 1 < n:
        if self.f[i][i+l-1] == 1:
          return s[i:i+l]
        i += 1

ss = Solution()
s = 'aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabcaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa'
print ss.longestPalindrome(s)
