#!/usr/bin/python

class Solution:
    # @param obstacleGrid, a list of lists of integers
    # @return an integer
    def uniquePathsWithObstacles(self, obstacleGrid):
      n = len(obstacleGrid)
      m = len(obstacleGrid[0])
      if n == 0: return 1
      path = []
      for i in range(0, n+1):
        tmp = []
        for j in range(0, m+1):
          tmp.append(0)
        path.append(tmp)

      if obstacleGrid[0][0] == 1:
        return 0
      path[1][1] = 1
      
      for i in range(1, n+1):
        for j in range(1, m+1):
          if not(i == 1 and j == 1) and obstacleGrid[i-1][j-1] != 1:
            path[i][j] = path[i-1][j] + path[i][j-1]
      return path[n][m]

sln = Solution()
sln.uniquePathsWithObstacles([[0], [1]])
