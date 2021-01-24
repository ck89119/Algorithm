#!/usr/bin/python

class Solution:
    # @param ratings, a list of integer
    # @return an integer
    def candy(self, ratings):
      n = len(ratings)
      ans = [0 for i in range(n)]
      i = 0
      while i < n:
        if i - 1 < 0 or ratings[i-1] >= ratings[i]:
          ans[i] = max(ans[i], 1)
        else:
          ans[i] = max(ans[i], ans[i-1]+1)
        i += 1

      i = n-1
      while i >= 0:
        if i + 1 >= n or ratings[i+1] >= ratings[i]:
          ans[i] = max(ans[i], 1)
        else:
          ans[i] = max(ans[i], ans[i+1]+1)
        i -= 1

      sum = 0;
      for i in range(n):
        sum += ans[i]
      return sum

ss = Solution()
ratings = [1,3,2,1,2,1]
print ss.candy(ratings)
