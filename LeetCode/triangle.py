#!/usr/bin/python

class Solution:
    # @param triangle, a list of lists of integers
    # @return an integer
    def minimumTotal(self, triangle):
      if len(triangle) == 1: return triangle[0][0]  
      i =  len(triangle) - 2
      while i >= 0:
        j = 0;
        while j <= i:
          triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1])
          j += 1
        i -= 1
      return triangle[0][0]
