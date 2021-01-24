#!/usr/bin/python

class Solution:
    # @param board, a list of lists of 1 length string
    # @param word, a string
    # @return a boolean
    dx = [0, 1, 0, -1]
    dy = [1, 0, -1, 0]

    def in_board(self, x, y, board):
      if x >= 0 and x < len(board) and y >= 0 and y < len(board[0]):
        return True
      else:
        return False

    def dfs(self, board, word, k, x, y, vis):
      if k >= len(word): return True
      for d in range(0, 4):
        tx = x + self.dx[d]
        ty = y + self.dy[d]
        if self.in_board(tx, ty, board) and not vis[tx][ty] and board[tx][ty] == word[k]:
          vis[tx][ty] = True
          if self.dfs(board, word, k+1, tx, ty, vis):
            return True
          vis[tx][ty] = False
      return False
      
    
    def exist(self, board, word):
      vis = []
      for i in range(0, len(board)):
        tmp = []
        for j in range(0, len(board[0])):
          tmp.append(False)
        vis.append(tmp)
      for i in range(0, len(board)):
        for j in range(0, len(board[0])):
          if board[i][j] == word[0]:
            vis[i][j] = True
            if self.dfs(board, word, 1, i, j, vis):
              return True
            vis[i][j] = False
      return False

s = Solution()
board = ["bbbbba","ccccca","ddddda","eeeeea","ffffff","gggggg"]
word = "aaaa"
print s.exist(board, word)
