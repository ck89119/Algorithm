#!/usr/bin/python

class Solution:
    # @param A, a list of integers
    # @return a boolean
    def dfs(self, A, n, cur):
      if self.ok[cur] != -1: return self.ok[cur]
      i = A[cur]
      ans = 0
      while i > 0 and ans == 0:
        if cur + i < n:
          if self.dfs(A, n, cur+i) == 1:
            ans = 1
        i -= 1
      self.ok[cur] = ans
      return self.ok[cur]

    def canJump(self, A):
      n = len(A)
      if n == 0: return True
      self.ok = [-1 for i in range(n)]
      self.ok[n-1] = 1
      self.dfs(A, n, 0)
      if self.ok[0] == 1:
        return True
      else:
        return False

