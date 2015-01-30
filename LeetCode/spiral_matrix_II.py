#!/usr/bin/python

class Solution:
    # @return a list of lists of integer
    def generateMatrix(self, n):
      ans = []
      for i in range(0, n):
        tmp = []
        for j in range(0, n):
          tmp.append(0)
        ans.append(tmp)
      count = 1
      k = 0
      while count <= n * n:
        for j in range(k, n-k):
          ans[k][j] = count
          count += 1

        for i in range(k+1, n-k):
          ans[i][n-k-1] = count
          count += 1

        j = n - k - 2
        while j >= k:
          ans[n-k-1][j] = count
          j -= 1
          count += 1

        i = n - k - 2
        while i >= k + 1:
          ans[i][k] = count
          i -= 1
          count += 1
        
        k += 1

      return ans

s = Solution()
print s.generateMatrix(4)

