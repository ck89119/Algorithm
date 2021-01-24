#!/usr/bin/python

class Solution:
    # @param s, a string
    # @param dict, a set of string
    # @return a boolean
    def check(self, s, dict, index, vis):
      if index == len(s): return 1
      if vis[index] != -1: return vis[index]
      ans = 0
      for word in dict:
        l = len(word)
        if s[index:index+l] == word and self.check(s, dict, index+l, vis) == 1:
          ans = 1
          break
      vis[index] = ans
      return vis[index]

    def wordBreak(self, s, dict):
        if len(dict) == 0: return False
        vis = []
        for i in range(0, len(s)):
          vis.append(-1)
        if self.check(s, dict, 0, vis) == 1: return True
        else: return False
