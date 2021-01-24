class Solution:
    # @param A a list of integers
    # @return an integer
    def removeDuplicates(self, A):
      if len(A) <= 2: return len(A)
      i = 0
      while i < len(A):
        print A
        print i
        if i + 2 < len(A):
          if A[i+2] == A[i]:
            del A[i+2]
            i -= 1
        i += 1
      return len(A)

sln = Solution()
A = [1,1,1,1]
print sln.removeDuplicates(A)
print A
        
