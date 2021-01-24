#!/usr/bin/python

class Solution:
    # @param matrix, a list of lists of integers
    # @return a list of integers
    def dfs(self, matrix, x, y, m, n):
      if m <= 0 or n <= 0:
        return
      if m == 1:
        for j in range(y, y+n):
          self.ans.append(matrix[x][j])
        return
      if n == 1:
        for i in range(x, x+m):
          self.ans.append(matrix[i][y])
        return

      i = x
      j = y
      while j < y + n:
        self.ans.append(matrix[i][j])
        j += 1
      i = x + 1
      j = y + n - 1
      while i < x + m:
        self.ans.append(matrix[i][j])
        i += 1
      i = x + m - 1
      j = y + n - 2
      while j >= y:
        self.ans.append(matrix[i][j])
        j -= 1
      i = x + m - 2
      j = y
      while i > x:
        self.ans.append(matrix[i][j])
        i -= 1
      self.dfs(matrix, x+1, y+1, m-2, n-2)

    
    def spiralOrder(self, matrix):
      m = len(matrix)
      if m == 0: return []
      n = len(matrix[0])
      if n == 0: return []
      self.ans = []
      self.dfs(matrix, 0, 0, m, n)
      return self.ans

ss = Solution()
matrix = [[1],[2],[3]]
print ss.spiralOrder(matrix)
