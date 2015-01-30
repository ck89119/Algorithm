#!/usr/bin/python

class Solution:
    # @param S, a list of integer
    # @return a list of lists of integer
    def dfs(self, S, k, set, ans):
      if k >= len(S):
        ans.append(set)
        return
      
      self.dfs(S, k+1, set, ans)

      tmp_set = []
      tmp_set.extend(set)
      tmp_set.append(S[k])
      self.dfs(S, k+1, tmp_set, ans)

    def subsets(self, S):
      if len(S) == 0: return []
      ans= []
      set = []
      self.dfs(S, 0, set, ans)
      for i in range(0, len(ans)):
        ans[i].sort()
      return ans

