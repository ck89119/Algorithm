#!/usr/bin/python

class Solution:
    # @param s, a string
    # @return a list of lists of string

    def isPalindrome(self, s):
      if len(s) == 1 or len(s) == 0: return True
      if s[0] != s[-1]: return False
      else: return self.isPalindrome(s[1:-1])
    
    def dfs(self, s, p, ans):
      if s == "":
        ans.append(p)
        return 
      
      for i in range(1, len(s)+1):
        if self.isPalindrome(s[0:i]):
          p_tmp = []
          p_tmp.extend(p)
          p_tmp.append(s[0:i])
          s_tmp = s[i:]
          self.dfs(s_tmp, p_tmp, ans)

    def partition(self, s):
      ans = []
      p = []
      self.dfs(s, p, ans)
      return ans

sln = Solution()
s = "abcdcba"
print sln.partition(s)

