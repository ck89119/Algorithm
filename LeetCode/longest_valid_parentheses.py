#!/usr/bin/python

class Solution:
    # @param s, a string
    # @return an integer
    def search(self, s, l, r):
      if self.f[l][r] != -1:
        return self.f[l][r]
      if r - l < 0:
        self.f[l][r] = 1
        return 1
      
      self.f[l][r] = 0
      if s[l] == '(' and s[r] == ')':
        self.f[l][r] = self.search(s, l+1, r-1)
        if self.f[l][r] == 1:
          return self.f[l][r]

      length = 2
      while l + length - 1 < r:
        if self.search(s, l, l+length-1) == 1 and self.search(s, l+length, r) == 1:
          self.f[l][r] = 1
          return self.f[l][r]
        length += 2
      return self.f[l][r]
    
    def longestValidParentheses(self, s):
      n = len(s)
      self.f = [[-1 for j in range(n)] for i in range(n)]
      l = 0
      r = n+1
      while l+2 < r:
        mid = (l + r) / 2
        if mid % 2 == 1: mid += 1
        i = 0
        flag = False
        while i + mid -1 < n:
          if self.search(s, i, i+mid-1) == 1:
            flag = True
            break
          i += 1
        if flag:
          l = mid
        else:
          r = mid
      return l

ss = Solution()
s = '((()))((((((()))))((())(()())(()((()()(()()))((())((((()))(()())))))())))()())((()()))((((()()()()()((()())))(())((()(()((()))()()()))()(())()))))))()(()))((()()()()())(()()()))(())((())())'
print ss.longestValidParentheses(s)
