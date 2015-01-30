#!/usr/bin/python

class Solution:
    # @param digits, a list of integer digits
    # @return a list of integer digits
    def plusOne(self, digits):
      if len(digits) == 0:
        digits.append(1)
        return digits
      i = len(digits) - 1
      carry = 1
      while i >= 0:
        digits[i] += carry
        carry = digits[i] / 10
        digits[i] %= 10
        i -= 1
      if carry == 1:
        ans = [1]
        ans.extend(digits)
        return ans
      else:
        return digits
