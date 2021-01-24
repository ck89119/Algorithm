#!/usr/bin/python

class Solution:
    # @param board, a 9x9 2D array
    # @return a boolean
    def isValidSudoku(self, board):
      i = 0
      while i < 9:
        record = []
        j = 0
        while j <= 9:
          record.append(0)
          j += 1
        j = 0
        while j < 9:
          if board[i][j] != '.':
            record[int(board[i][j])] += 1
          j += 1
        j = 1
        while j <= 9:
          if record[j] > 1: return False
          j += 1
        i += 1
      
      i = 0
      while i < 9:
        record = []
        j = 0
        while j <= 9:
          record.append(False)
          j += 1
        j = 0
        while j < 9:
          if board[j][i] != '.':
            record[int(board[j][i])] += 1
          j += 1
        j = 1
        while j <= 9:
          if record[j] > 1: return False
          j += 1
        i += 1

      i = 0
      while i < 9:
        j = 0
        while j < 9:
          record = []
          for k in range(0, 10):
            record.append(0)
          for ii in range(i, i+3):
            for jj in range(j, j+3):
              if board[ii][jj] != '.':
                record[int(board[ii][jj])] += 1
          for k in range(1, 10):
            if record[k] > 1: return False
          j += 3
        i += 3
      return True
