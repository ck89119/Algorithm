#!/usr/bin/python

class Solution:
    # @param haystack, a string
    # @param needle, a string
    # @return a string or None
    def strStr(self, haystack, needle):
      index = haystack.find(needle)
      if index == -1: return None
      else: return haystack[index:]
