#!/usr/bin/python

class Solution:
    # @param s, a string
    # @return a boolean
    def isPalindrome(self, s):
      if s == '': return True
      i = 0
      j = len(s) - 1
      while i < j:
        while i < j and not s[i].isalpha() and not s[i].isdigit():
          i += 1
        while i < j and not s[j].isalpha() and not s[j].isdigit():
          j -= 1
        if s[i].isalpha() and s[j].isdigit(): return False
        if s[i].isdigit() and s[j].isalpha(): return False
        if s[i].isdigit() and s[j].isdigit() and s[i] != s[j]: return False
        if s[i].isalpha() and s[j].isalpha():
          if s[i] != s[j] and s[i] != s[j].lower() and s[i].lower() != s[j]:
            return False
        i += 1
        j -= 1
      return True
