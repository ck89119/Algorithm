#!/usr/bin/python

class Solution:
    # @param A, a list of integers
    # @param target, an integer to be searched
    # @return a list of length 2, [index1, index2]
    def binary_search(self, A, target, l, r):
      if l > r: return -1
      mid = (l + r) / 2
      if A[mid] == target and (mid == l or A[mid-1] != target):
        return mid

      if A[mid] >= target:
        ans = self.binary_search(A, target, l, mid-1)
      if A[mid] < target:
        ans = self.binary_search(A, target, mid+1, r)
      return ans

    def binary_search2(self, A, target, l, r):
      if l > r: return -1
      mid = (l + r) / 2
      if A[mid] == target and (mid == r or A[mid+1] != target):
        return mid

      if A[mid] > target:
        ans = self.binary_search2(A, target, l, mid-1)
      if A[mid] <= target:
        ans = self.binary_search2(A, target, mid+1, r)
      return ans

    def searchRange(self, A, target):
      ans1 = self.binary_search(A, target, 0, len(A)-1)
      ans2 = self.binary_search2(A, target, 0, len(A)-1)
      return [ans1, ans2]

sln = Solution()
print sln.searchRange([1,2,2,2,3], 2)
