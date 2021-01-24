#!/usr/bin/python

class Solution:
    # @param num, a list of integer
    # @return a list of lists of integers
    def dfs(self, num, p):
      if len(p) == len(num):
        self.ans.append(p)
        return 
      
      for i in range(0, len(num)):
        if (i == 0 or num[i] != num[i-1]):
          c1 = 0
          c2 = 0
          for j in range(0, len(num)):
            if num[j] == num[i]: c1 += 1
          for j in range(0, len(p)):
            if p[j] == num[i]: c2 += 1
          if c1 > c2:
            tmp = []
            tmp.extend(p)
            tmp.append(num[i])
            self.dfs(num, tmp)
    
    def permuteUnique(self, num):
      num.sort()
      self.ans = []
      self.dfs(num, [])
      return self.ans

sln = Solution()
print sln.permuteUnique([1,3,1])

