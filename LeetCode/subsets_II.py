#!/usr/bin/python

class Solution:
    # @param num, a list of integer
    # @return a list of lists of integer
    def subsetsWithDup(self, S):
      n = len(S)
      S.sort()
      ans = []
      for i in range(0, 1 << n):
        tmp = []
        for j in range(0, n):
          if i & (1 << j) != 0:
            tmp.append(S[j])
        if not tmp in ans:
          ans.append(tmp)
      return ans

ss = Solution()
S = [1,2,3]
print ss.subsetsWithDup(S)
