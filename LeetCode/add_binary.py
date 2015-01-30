#!/usr/bin/python

class Solution:
    # @param a, a string
    # @param b, a string
    # @return a string
    def b_to_d(self, s):
      i = 0
      ans = 0
      while i < len(s):
        ans = ans * 2 + int(s[i]);
        i += 1
      return ans
    
    def d_to_b(self, n):
      if n == 0: return '0'
      s = ''
      while n != 0:
        if n % 2 == 1:
          s = '1' + s
        else:
          s = '0' + s
        n /= 2
      return s

    def addBinary(self, a, b):
      na = self.b_to_d(a)
      print na
      nb = self.b_to_d(b)
      print nb
      return self.d_to_b(na+nb)

sln = Solution()
a = '1010'
b = '1011'
print sln.addBinary(a, b)
