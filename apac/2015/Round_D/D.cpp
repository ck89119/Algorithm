/*
ID: ck89119
PROG:
LANG: C++
*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl
#define CLR(a,x) memset(a,x,sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define PAU system("pause")
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int N = 99999;
const int M = 9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int in_board(int x, int y) {
  if (x >= 0 && x < 8 && y >= 0 && y < 8) return 1;
  else return 0;
}

struct Node {
  char c;
  int x, y;
};
vector<Node> v;
char maze[64][64];
int n;

int main() {
  #ifndef ONLINE_JUDGE
    freopen("D-large.in", "r", stdin);
    freopen("D-large.out", "w", stdout);
  #endif
  int T;
  cin >> T;
  for (int ncase = 1; ncase <= T; ++ncase) {
    v.clear();
    for (int i = 0; i < 8; ++i)
      for (int j = 0; j < 8; ++j) maze[i][j] = '.';

    Node t;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      string s;
      cin >> s;
      t.x = s[0] - 'A';
      t.y = s[1] - '1';
      t.c = s[3];
      maze[t.x][t.y] = t.c;
      v.PB(t);
    }


    int ans = 0;
    for (int i = 0; i < v.size(); ++i) {
      int x = v[i].x;
      int y = v[i].y;
      if (v[i].c == 'K') {
        for (int d = 0; d < 8; ++d) {
          int tx = x + dx[d];
          int ty = y + dy[d];
          if (!in_board(tx, ty)) continue;
          if (maze[tx][ty] != '.') ++ans;
        }          
      } else if (v[i].c == 'Q') {
        for (int d = 0; d < 8; ++d) {
          int tx, ty;
          int flag = 0;
          for (int l = 1; l <= 8; ++l) {
            tx = x + l * dx[d];
            ty = y + l * dy[d];
            if (!in_board(tx, ty)) continue;
            if (maze[tx][ty] != '.') { flag = 1; break; }
          }
          if (flag) ++ans;
        }          
      } else if (v[i].c == 'R') {
        for (int d = 0; d < 8; d += 2) {
          int tx, ty;
          int flag = 0;
          for (int l = 1; l <= 8; ++l) {
            tx = x + l * dx[d];
            ty = y + l * dy[d];
            if (!in_board(tx, ty)) continue;
            if (maze[tx][ty] != '.') { flag = 1; break; }
          }
          if (flag) ++ans;
        }          
      } else if (v[i].c == 'B') {
        for (int d = 1; d < 8; d += 2) {
          int tx, ty;
          int flag = 0;
          for (int l = 1; l <= 8; ++l) {
            tx = x + l * dx[d];
            ty = y + l * dy[d];
            if (!in_board(tx, ty)) continue;
            if (maze[tx][ty] != '.') { flag = 1; break; }
          }
          if (flag) ++ans;
        }          
      } else if (v[i].c == 'N') {
        int ndx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
        int ndy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
        for (int d = 0; d < 8; ++d) {
          int tx, ty;
          tx = x + ndx[d];
          ty = y + ndy[d];
          if (!in_board(tx, ty)) continue;
          if (maze[tx][ty] != '.') ++ans;
        }
      } else if (v[i].c == 'P') {
        int tx, ty;
        tx = x + 1;
        ty = y + 1;
        if (in_board(tx, ty) && maze[tx][ty] != '.') ++ans;
        tx = x + 1;
        ty = y - 1;
        if (in_board(tx, ty) && maze[tx][ty] != '.') ++ans;
      }  
    } 

    cout << "Case #" << ncase << ": " << ans << endl;
  }
  return 0;
}
