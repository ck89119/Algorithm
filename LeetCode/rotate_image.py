#!/usr/bin/python

class Solution:
    # @param matrix, a list of lists of integers
    # @return a list of lists of integers
    def rotate(self, matrix):
      n = len(matrix)
      if n <= 1: return matrix
      ans = [[0 for j in range(n)] for i in range(n)]
      for i in range(n):
        for j in range(n):
          ans[j][n-1-i] = matrix[i][j]
      return ans

ss = Solution()
matrix = [[1,2,3], [4,5,6],[7,8,9]]
print ss.rotate(matrix)
