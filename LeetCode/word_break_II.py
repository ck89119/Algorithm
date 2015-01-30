#!/usr/bin/python

class Solution:
    # @param s, a string
    # @param dict, a set of string
    # @return a boolean
    def check(self, s, dict, index, vis, word_arr):
      if index == len(s):
        self.ans.append(' '.join(word_arr))
        return 1
      if vis[index] == 0: return vis[index]

      ans = 0
      for word in dict:
        l = len(word)
        if s[index:index+l] == word:
          word_arr.append(word)
          if self.check(s, dict, index+l, vis, word_arr) == 1:
            ans = 1
          word_arr.pop(-1)
      vis[index] = ans
      return vis[index]

    def wordBreak(self, s, dict):
        if len(dict) == 0: return []
        self.ans = []
        vis = []
        for i in range(0, len(s)):
          vis.append(-1)
        self.check(s, dict, 0, vis, [])
        return self.ans

ss = Solution()
s = 'catsanddog'
dict = {"cat", "cats", "and", "sand", "dog"}
print ss.wordBreak(s, dict)
