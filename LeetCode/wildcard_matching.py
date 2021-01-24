#!/usr/bin/python
import re
class Solution:
    # @return a boolean
    def isMatch(self, s, p):
      p = p.replace('?', '.')
      p = p.replace('*', '.*')
      print p
      reg = '^'
      reg += p
      reg += '$'
      match = re.search(reg, s)
      if match:
        return True
      else:
        return False

ss = Solution()
s = 'aaaabaaaabbbbaabbbaabbaababbabbaaaababaaabbbbbbaabbbabababbaaabaabaaaaaabbaabbbbaababbababaabbbaababbbba'
p = '*****b*aba***babaa*bbaba***a*aaba*b*aa**a*b**ba***a*a*'
print ss.isMatch(s, p)
