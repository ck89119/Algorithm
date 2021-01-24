#!/usr/bin/python

class Solution:
    # @param num1, a string
    # @param num2, a string
    # @return a string
    def multiply(self, num1, num2):
      n1 = len(num1)
      n2 = len(num2)
      a = []
      for i in range(0, n1):
        a.append(int(num1[n1-1-i]))
      b = []
      for i in range(0, n2):
        b.append(int(num2[n2-1-i]))
      c = [0] * (n1+n2-1)
      
      for i in range(0, n1):
        for j in range(0, n2):
          c[i+j] += a[i] * b[j]
      
      carry = 0
      for k in range(0, len(c)):
        c[k] += carry
        carry = c[k] / 10
        c[k] %= 10
      if carry > 0:
        c.append(carry)
      
      k = len(c) - 1
      while k >= 0 and c[k] == 0:
        k -= 1
      if k < 0: return '0'

      ans = ''
      while k >= 0:
        ans += str(c[k])
        k -= 1

      return ans
