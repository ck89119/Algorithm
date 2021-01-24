#!/usr/bin/python

class Solution:
    # @param s, a string
    # @return an integer
    def lengthOfLastWord(self, s):
      if len(s) == 0: return 0
      words = s.split()
      if len(words) == 0:
        return 0
      else:
        return len(words[-1])
