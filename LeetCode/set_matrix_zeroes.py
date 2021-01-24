#!/usr/bin/python

class Solution:
    # @param matrix, a list of lists of integers
    # RETURN NOTHING, MODIFY matrix IN PLACE.
    def setZeroes(self, matrix):
      if matrix == []: return []
      n = len(matrix)
      m = len(matrix[0])
      locx = [False] * n
      locy = [False] * m
      for i in range(0, n):
        for j in range(0, m):
          if matrix[i][j] == 0:
            locx[i] = True
            locy[j] = True
      
      for i in range(0, n):
        if locx[i]:
          for j in range(0, m):
            matrix[i][j] = 0
      for j in range(0, m):
        if locy[j]:
          for i in range(0, n):
            matrix[i][j] = 0


sln = Solution()
sln.setZeroes([[1]])
