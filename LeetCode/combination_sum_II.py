#!/usr/bin/python

class Solution:
    # @param candidates, a list of integers
    # @param target, integer
    # @return a list of lists of integers
    def dfs(self, candidates, target, sum, k, set):
      if sum == target:
        if not set in self.ans:
          self.ans.append(set)
          return
      if sum > target: return
      if k >= len(candidates): return 

      self.dfs(candidates, target, sum, k+1, set)
      tmp_set = []
      tmp_set.extend(set)
      tmp_set.append(candidates[k])
      self.dfs(candidates, target, sum+candidates[k], k+1, tmp_set)
    
    
    def combinationSum2(self, candidates, target):
      if len(candidates) == 0: return []
      candidates.sort()
      candidates.reverse()
      self.ans = []
      self.dfs(candidates, target, 0, 0, [])
      for i in range(0, len(self.ans)):
        self.ans[i].reverse()
      return self.ans

s = Solution()
print s.combinationSum2([1,1,2,5,6,7,10], 8)
