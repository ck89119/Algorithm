#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

using namespace std;

int main(int argc, char **argv)
{
  freopen("A-large.in", "r", stdin);
  freopen("A-large.out", "w", stdout);

  int num_case;
  cin >> num_case;

  for (int i = 0; i < num_case; ++i) {
    int size;
    cin >> size;
    vector<vector<int>> maze(size, vector<int>(size, 0));
    vector<vector<int>> count(size, vector<int>(size, 1));

    for (int m = 0; m < size; ++m) {
      for (int n = 0; n < size; ++n) {
        cin >> maze[m][n];
      }
    }

    int max_room = 0;
    int max_move = 0;

    for (int m = 0; m < size; ++m) {
      for (int n = 0; n < size; ++n) {
        int current_row = m;
        int current_col = n;
        int counter = 1;
        while (true) {
          int next_row = current_row + 1;
          int next_col = current_col;
          if (next_row != size && maze[next_row][next_col] == maze[current_row][current_col] + 1) {
            current_row++;
            ++counter;
            continue;
          }
          next_row = current_row - 1;
          if (next_row >= 0 && maze[next_row][next_col] == maze[current_row][current_col] + 1) {
            --current_row;
            ++counter;
            continue;
          }
          next_row = current_row;
          next_col = current_col + 1;
          if (next_col != size && maze[next_row][next_col] == maze[current_row][current_col] + 1) {
            ++current_col;
            ++counter;
            continue;
          }
          next_col = current_col - 1;
          if (next_col >= 0 && maze[next_row][next_col] == maze[current_row][current_col] + 1) {
            --current_col;
            ++counter;
            continue;
          }
          break;
        }
        count[m][n] = counter;
        if (counter > max_move) {
          max_move = counter;
          max_room = maze[m][n];
        } else if (counter == max_move) {
          max_room = std::min(maze[m][n], max_room);
        }
      }
    }

    cout << "Case #" << i + 1 << ": " << max_room << ' ' << max_move << endl;
  }

  return 0;
}
