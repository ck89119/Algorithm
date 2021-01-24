#!/usr/bin/python

class Solution:
    # @param A, a list of integer
    # @return an integer
#    def singleNumber(self, A):
#      A.sort()
#      i = 0
#      while i < len(A):
#        if i + 1 < len(A) and A[i] == A[i+1]:
#          i += 3
#        else:
#          break
#      return A[i]
    def singleNumber(self, A):
      n = (len(A) - 1) / 3
      c = A[0]
      for i in range(1, len(A)):
        c = ~(c | A[i])
      for i in range(0, len(A)):
        t = ~(c | A[i])
        if t == 0:
          return A[i]
