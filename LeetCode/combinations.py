#!/usr/bin/python

class Solution:
    # @return a list of lists of integers
    def dfs(self, n, k, st, dep, c, ans):
      if dep == k:
        ans.append(c)
        return
      if st > n:
        return 
      
      self.dfs(n, k, st+1, dep, c, ans)

      tmp_c = []
      tmp_c.extend(c)
      tmp_c.append(st)
      self.dfs(n, k, st+1, dep+1, tmp_c, ans)
    
    def combine(self, n, k):
      if n == 0 or k == 0:
        return []
      ans = []
      c = []
      self.dfs(n, k, 1, 0, c, ans)
      return ans
