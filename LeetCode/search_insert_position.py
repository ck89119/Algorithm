#!/usr/bin/python

class Solution:
    # @param A, a list of integers
    # @param target, an integer to be inserted
    # @return integer
    def searchInsert(self, A, target):
      index = 0
      while index < len(A) and A[index] < target:
        index += 1
      return index
