#!/usr/bin/python

class Solution:
    # @param A a list of integers
    # @return nothing, sort in place
    def sortColors(self, A):
      count = [0 for i in range(3)]
      for i in range(len(A)):
        count[A[i]] += 1
      k = 0
      for i in range(3):
        while count[i] > 0:
          A[k] = i
          k += 1
          count[i] -= 1

