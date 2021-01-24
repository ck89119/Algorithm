#!/usr/bin/python

class Solution:
    # @param s, a string
    # @return a string
    def reverseWords(self, s):
      words = s.split()
      ans = ''
      for word in words:
        ans = ' ' + word + ans
      return ans[1:]
