#!/usr/bin/python

class Solution:
    # @param    A       a list of integers
    # @param    elem    an integer, value need to be removed
    # @return an integer
    def removeElement(self, A, elem):
        length = len(A)
        i = 0
        while i < length:
          if A[i] == elem:
            tmp = A[i]
            A[i] = A[length-1]
            A[length-1] = tmp
            length -= 1
            i -= 1
          i += 1
        return length
