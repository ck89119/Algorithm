#!/usr/bin/python

class Solution:
    # @return a boolean
    def isValid(self, s):
      stack = []
      for i in range(0, len(s)):
        if s[i] == '(' or s[i] == '[' or s[i] == '{':
          stack.append(s[i])
          continue
        if s[i] == ')':
          if len(stack) >= 1 and stack[-1] == '(':
            stack.pop(-1)
            continue
          else:
            return False
        if s[i] == ']':
          if len(stack) >= 1 and stack[-1] == '[':
            stack.pop(-1)
            continue
          else:
            return False
        if s[i] == '}':
          if len(stack) >= 1 and stack[-1] == '{':
            stack.pop(-1)
            continue
          else:
            return False
      if stack == []: return True
      else: return False

s = Solution()
print s.isValid('([{}]){[]})')
