#!/usr/bin/python

class Solution:
    # @param x, an integer
    # @return an integer
    def sqrt(self, x):
      l = 0
      r = x
      while l <= r:
        mid = (l + r) / 2
        sqr = mid * mid
        if sqr == x: return mid
        if sqr < x: l = mid + 1
        if sqr > x: r = mid - 1
        
      return l - 1
