#!/usr/bin/python

class Solution:
    # @param height, a list of integer
    # @return an integer
    def largestRectangleArea(self, height):
      n = len(height)
      smallest = [[9999 for j in range(n)] for i in range(n)]
      for i in range(n):
        smallest[i][i] = height[i]
        for j in range(i+1, n):
          smallest[i][j] = min(height[j], smallest[i][j-1])

      ans = 0
      for i in range(n):
        for j in range(i, n):
          ans = max(ans, (j-i+1)*smallest[i][j])
      return ans


