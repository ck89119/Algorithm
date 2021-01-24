#!/usr/bin/python

class Solution:
    # @param a list of integers
    # @return an integer
    def seek(self, A, j, flag):
      loc = j
      while loc < len(A) and A[loc] == flag: 
        loc += 1
      return loc
    
    def removeDuplicates(self, A):
      if len(A) == 0: return 0
      flag = A[0] - 1
      for i in range(0, len(A)-1):
        if A[i] == A[i+1]: A[i] = flag
      i = 0
      j = 0
      while j < len(A):
        j = self.seek(A, j, flag)
        if j < len(A):
          A[i] = A[j]
          i += 1
          j += 1

      return i

