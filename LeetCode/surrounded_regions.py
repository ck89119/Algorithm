#!/usr/bin/python

class Solution:
    # @param board, a 9x9 2D array
    # Capture all regions by modifying the input board in-place.
    # Do not return any value.
    dx = [0, 1, 0, -1]
    dy = [1, 0, -1, 0]
    def inboard(self, nx, ny, x, y):
      if x >= 0 and x < nx and y >= 0 and y < ny: return True
      else: return False

    def dfs(self, board, x, y):
      res = False
      for i in range(0, 4):
        tx = x + self.dx[i]
        ty = y + self.dy[i]
        if not self.inboard(len(board), len(board[0]), tx, ty):
          return True
        else:
          if not self.vis[tx][ty] and board[tx][ty] == 'O':
            self.vis[tx][ty] = True
            res = (res or self.dfs(board, tx, ty))
            self.vis[tx][ty] = False
            if res: return True
      return False
    
    def dfs1(self, board, x, y):
      for i in range(0, 4):
        tx = x + self.dx[i]
        ty = y + self.dy[i]
        if self.inboard(len(board), len(board[0]), tx, ty) and board[tx][ty] == 'O':
          board[tx][ty] = 'X'
          self.dfs1(board, tx, ty)

    def solve(self, board):
      self.vis = []
      for i in range(0, len(board)):
        tmp = []
        for j in range(0, len(board[0])):
          tmp.append(False)
        self.vis.append(tmp)
      for i in range(0, len(board)):
        for j in range(0, len(board[0])):
          if board[i][j] == 'O':
            self.vis[i][j] = True
            if not self.dfs(board, i, j):
              print i, j
              board[i][j] = 'X'
              self.dfs1(board, i, j)
            self.vis[i][j] = False

sln = Solution()
board = ["XXX", "XOX", "XXX"]
sln.solve(board)
print board
