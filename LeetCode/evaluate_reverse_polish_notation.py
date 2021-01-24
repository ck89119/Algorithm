#!/usr/bin/python

class Solution:
    # @param tokens, a list of string
    # @return an integer
    def evalRPN(self, tokens):
      stack = []
      for token in tokens:
        if token == '+' or token == '-' or token == '*' or token == '/':
          a = int(stack.pop())
          b = int(stack.pop())
          if token == '+': c = b + a
          if token == '-': c = b - a
          if token == '*': c = b * a
          if token == '/': 
            op = 1
            if (a < 0): 
              op *= -1
              a *= -1
            if (b < 0):
              op *= -1
              b *= -1
            c = b / a
            c *= op
          stack.append(str(c))
        else:
          stack.append(token)
      return int(stack.pop())
