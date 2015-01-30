#!/usr/bin/python

class Solution:
    # @param A, a list of integers
    # @return an integer
    def firstMissingPositive(self, A):
      A.sort()
      n = len(A)
      i = 0
      while i < n and A[i] <= 0:
        i += 1
      miss = 1
      while i < n:
        if i != 0 and i < n and A[i] == A[i-1]:
          i += 1
          continue
        if A[i] != miss: break
        miss += 1
        i += 1
      return miss

ss = Solution()
A = [0,1,1,2,2]
print ss.firstMissingPositive(A)
