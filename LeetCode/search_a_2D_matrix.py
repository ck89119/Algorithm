#!/usr/bin/python

class Solution:
    # @param matrix, a list of lists of integers
    # @param target, an integer
    # @return a boolean
    def searchMatrix(self, matrix, target):
      if len(matrix) == 0: return False
      n = len(matrix)
      m = len(matrix[0])
      l = 0
      r = n - 1
      flag = -1
      while l <= r:
        mid = (l+r) / 2
        if matrix[mid][0] == target:
          flag = mid
          break
        if matrix[mid][0] > target:
          r = mid - 1
        if matrix[mid][0] < target:
          l = mid + 1
      if flag != -1: return True
      i = l - 1
      if i < 0: return False
      
      l = 0
      r = m - 1
      flag = -1
      while l <= r:
        mid = (l+r) / 2
        if matrix[i][mid] == target:
          flag = mid
          break
        if matrix[i][mid] > target:
          r = mid - 1
        if matrix[i][mid] < target:
          l = mid + 1
      if flag != -1: return True
      return False


ss = Solution()
matrix = [[1]]
target = 2
print ss.searchMatrix(matrix, target)
