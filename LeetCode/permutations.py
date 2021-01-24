#!/usr/bin/python

class Solution:
    # @param num, a list of integer
    # @return a list of lists of integers
    def dfs(self, p, n):
      if len(p) == n:
        self.per.append(p)
        return
    
      for i in range(0, n):
        j = 0
        while j < len(p) and i != p[j]:
          j += 1
        if j == len(p):
          tmp = []
          tmp.extend(p)
          tmp.append(i)
          self.dfs(tmp, n)

    def permute(self, num):
      self.per = []
      self.dfs([], len(num))
      self.ans = []
      for i in range(0, len(self.per)):
        tmp = []
        for j in range(0, len(self.per[i])):
          tmp.append(num[self.per[i][j]])
        self.ans.append(tmp)
      return self.ans
