#!/usr/bin/python

class Solution:
    # @param path, a string
    # @return a string
    def simplifyPath(self, path):
      foo = path.split('/')
      stack = []
      for item in foo:
        if item == '.' or item == '': continue
        elif item == '..':
          if len(stack) != 0: 
            stack.pop(-1)
        else:
          stack.append(item)
      if len(stack) == 0:
        stack.append('')
      res = ''
      for item in stack:
        res += '/' + item
      return res

ss = Solution()
path = '/'
print ss.simplifyPath(path)
