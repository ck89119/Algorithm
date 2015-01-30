#!/usr/bin/python

class Solution:
  # @return an integer
  def atoi(self, str):
    i = 0
    while i < len(str) and str[i] == ' ':
      i += 1
    if i >= len(str):
      return 0

    op = 1
    if str[i] == '+':
      op = 1
      i += 1
    elif str[i] == '-':
      op = -1
      i += 1
    
    if str[i] < '0' or str[i] > '9':
      return 0

    t = 0
    max = 2 ** 31
    while i < len(str) and str[i] >= '0' and str[i] <= '9':
      t = t * 10 + int(str[i]) - int('0')
      i += 1
      if op == 1 and t >= max:
        t = max - 1
        break
      if op == -1 and t > max:
        t = max
        break
    return op * t
