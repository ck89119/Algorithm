#!/usr/bin/python

class Solution:
    # @param candidates, a list of integers
    # @param target, integer
    # @return a list of lists of integers
    def dfs(self, candidates, target, k, s, sum, ans):
      if k >= len(candidates):
        if sum == target:
          ans.append(s)
        return
      
      i = 0
      while sum + candidates[k] * i <= target:
        tmp_s = []
        tmp_s.extend(s)
        for j in range(0, i):
          tmp_s.append(candidates[k])
        tmp_sum = sum + candidates[k] * i
        self.dfs(candidates, target, k+1, tmp_s, tmp_sum, ans)
        i += 1

    def combinationSum(self, candidates, target):
      if len(candidates) == 0: return []
      candidates.sort()
      candidates.reverse()
      ans = []
      s = []
      self.dfs(candidates, target, 0, s, 0, ans)
      for i in range(0, len(ans)):
        ans[i].reverse()
      return ans
