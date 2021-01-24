#!/usr/bin/python

class Solution:
    # @return a boolean
    def isPalindrome(self, x):
      if x < 0: return False
      dig = []
      while x != 0:
        dig.append(x%10)
        x /= 10
      i = 0
      j = len(dig) - 1
      while i < j:
        if dig[i] != dig[j]: return False
        i += 1
        j -= 1
      return True
