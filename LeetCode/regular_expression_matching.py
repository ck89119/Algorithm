#!/usr/bin/python

class Solution:
    # @return a boolean
    def isMatch(self, s, p):
      reg = '^'
      reg += p
      reg += '$'
      match = re.search(reg, s)
      if match:
        return True
      else:
        return False
