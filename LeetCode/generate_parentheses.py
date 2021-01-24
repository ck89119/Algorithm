#!/usr/bin/python

class Solution:
    # @param an integer
    # @return a list of string
    def dfs(self, stack, left, k, n, string):
      if k == n + n:
        self.ans.append(string)
        return
      
      if left > 0:
        tmp_str = string + '('
        self.dfs(stack+1, left-1, k+1, n, tmp_str)

      if stack > 0:
        tmp_str = string + ')'
        self.dfs(stack-1, left, k+1, n, tmp_str)
  

    def generateParenthesis(self, n):
      self.ans = []
      self.dfs(0, n, 0, n, '')
      return self.ans

s = Solution()
print s.generateParenthesis(3)
