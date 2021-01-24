#!/usr/bin/python

class Solution:
    # @param num, a list of integer
    # @return an integer
    def longestConsecutive(self, num):
      mini = 999999
      maxi = -mini
      n = len(num)
      for i in range(n):
        mini = min(mini, num[i])
        maxi = max(maxi, num[i])

      index = [0] * (maxi - mini + 1)
      for i in range(n):
        index[num[i]-mini] = 1
      i = 0
      ans = 0
      while i < maxi - mini + 1:
        if index[i] == 1:
          tmp = 1
          while i + 1 < maxi -mini + 1 and index[i+1] == 1:
            tmp += 1
            i += 1
          ans = max(ans, tmp)
        i += 1
      return ans

s = Solution()
num = [100, 4, 200, 1, 3, 2]
print s.longestConsecutive(num)
