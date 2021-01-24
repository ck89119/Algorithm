#!/usr/bin/python

class Solution:
    # @return a list of lists of string
    def init(self, n):
      self.ans = []
      self.vis1 = [False] * n
      self.vis2 = [False] * (n + n)
      self.vis3 = [False] * (n + n)

    def dfs(self, n, cur, board):
      if cur >= n:
        self.ans.append(board)
        return
      
      for i in range(0, n):
        if not self.vis1[i] and not self.vis2[cur+i] and not self.vis3[cur-i+n]:
          self.vis1[i] = True
          self.vis2[cur+i] = True
          self.vis3[cur-i+n] = True
          s = '.' * i
          s += 'Q'
          s += '.' * (n-1-i)
          tmp_board = []
          tmp_board.extend(board)
          tmp_board.append(s)
          self.dfs(n, cur+1, tmp_board)
          self.vis1[i] = False
          self.vis2[cur+i] = False
          self.vis3[cur-i+n] = False


    def solveNQueens(self, n):
      self.init(n)
      self.dfs(n, 0, [])
      print len(self.ans)
      return self.ans

ss = Solution()
for i in range(1, 21):
  ss.solveNQueens(i)
