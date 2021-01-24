#!/usr/bin/python

class Solution:
    # @param num, a list of integer
    # @return a list of integer
    def nextPermutation(self, num):
      if len(num) <= 1: return num
      
      i = len(num) - 1
      while i >= 1 and num[i] <= num[i-1]:
        i -= 1
      if i < 1:
        num.reverse()
        return num
      
      j = len(num) - 1
      while num[j] <= num[i-1]: j -= 1
      tmp = num[j]
      num[j] = num[i-1]
      num[i-1] = tmp

      tmp = num[0:i]
      tmp1 = num[i:]
      tmp1.sort()
      tmp.extend(tmp1)
      return tmp

sol = Solution()
print sol.nextPermutation([1,5,1])
