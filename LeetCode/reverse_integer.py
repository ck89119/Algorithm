#!/usr/bin/python

class Solution:
  # @return an integer
  def reverse(self, x):
    op = 1
    if x < 0:
      op = -1
      x *= -1
    
    t = 0
    while x != 0:
      d = x % 10
      x /= 10
      t = t * 10 + d
    return op * t
