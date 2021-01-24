#!/usr/bin/python

import re

class Solution:
    # @param s, a string
    # @return a boolean
    def isNumber(self, s):
      reg = "^[-+]?(\d+\.?|\.\d+)\d*(e[-+]?\d+)?$"
      s = s.strip()
      if s == '': return False
      match = re.search(reg, s)
      if match: return True
      else: return False

s = Solution()
str = '1e9'
print s.isNumber(str)
