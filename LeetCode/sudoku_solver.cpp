#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    char ans[9][9];
    int row_ok[9][9];
    int col_ok[9][9];

    int check_block(vector<vector<char> > &board, int row, int col, char ch) {
      int i, j;
      int x = row / 3;
      int y = col / 3;
      for (i = 3*x; i < 3*x+3; ++i)
        for (j = 3*y; j < 3*y+3; ++j)
          if (board[i][j] == ch) return 0;
      return 1;
    }
    
    int dfs(vector<vector<char> > &board, int row, int col) {
      if (row >= 9) {
        int i, j;
        for (i = 0; i < 9; ++i)
          for (j = 0; j < 9; ++j)
            ans[i][j] = board[i][j];
        return 0;
      }
      char ch;
      if (board[row][col] != '.')
        dfs(board, row+(col+1)/9, (col+1)%9);
      else {
        for (ch = '1'; ch <= '9'; ++ch) {
          int t = ch - '1';
          if (row_ok[row][t] == 0 && col_ok[col][t] == 0 && check_block(board, row, col, ch)) {
            board[row][col] = ch;
            row_ok[row][t] = 1;
            col_ok[col][t] = 1;
            dfs(board, row+(col+1)/9, (col+1)%9);
            col_ok[col][t] = 0;
            row_ok[row][t] = 0;
            board[row][col] = '.';
          }
        }
      }
    }
     
    void solveSudoku(vector<vector<char> > &board) {
      int i, j;
      memset(row_ok, 0, sizeof(row_ok));
      memset(col_ok, 0, sizeof(col_ok));
      for (i = 0; i < 9; ++i)
        for (j = 0; j < 9; ++j)
          if (board[i][j] != '.') {
            int t = board[i][j] - '1';
            row_ok[i][t] = 1;
            col_ok[j][t] = 1;
          }

      dfs(board, 0, 0);
      for (i = 0; i < 9; ++i)
        for (j = 0; j < 9; ++j)
          board[i][j] = ans[i][j];
    }
};
