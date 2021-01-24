#!/usr/bin/python

class Solution:
    # @param A, a list of integers
    # @return an integer
    def trap(self, A):
      if len(A) == 0: return 0
      maxl = []
      maxl.append(A[0])
      for i in range(1, len(A)):
        maxl.append(max(maxl[-1], A[i]))

      maxr = []
      for i in range(0, len(A)):
        maxr.append(0)
      maxr[-1] = A[-1]
      i = len(A) - 2
      while i >= 0:
        maxr[i] = max(maxr[i+1], A[i])
        i -= 1

      s1 = 0
      s2 = 0
      for i in range(0, len(A)):
        s1 += A[i]
        s2 += min(maxl[i], maxr[i])
      return s2 - s1
