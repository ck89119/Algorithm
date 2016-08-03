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

#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) << endl
#define clr(a, x) memset(a, x, sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
#define X first 
#define Y second
typedef long long ll;
typedef pair<int, int> pii;

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out(vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}

const int N = 1000 + 5;
const int M = 1000 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1000000007;

class bit_2D {
 public:
  bit_2D(int row, int col): row_(row), col_(col) { clr(c_, 0); }
  int update(int x, int y, int delta);
  int sum(int x, int y);
  int sum(int x1, int y1, int x2, int y2);

 private:
  int c_[N][M];
  int row_, col_;

};

int bit_2D::sum(int x, int y) {
  int result;
  for (int i = x; i <= row_; i += lowbit(i))
    for (int j = y; j <= col_;  j += lowbit(j))
      result += c_[i][j];
  return result;
}

int bit_2D::update(int x, int y, int delta) {
  for (int i = x; i > 0; i -= lowbit(i))
    for (int j = y; j > 0; j -= lowbit(j))
      c_[i][j] += delta;
  return 0;
}

int bit_2D::sum(int x1, int y1, int x2, int y2) {
  return sum(x2, y2) - sum(x1-1, y2) - sum(x2, y1-1) + sum(x1-1, y1-1);
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);
#endif
  int x;
  scanf("%d", &x);
  while (x--) {
    int n, t;
    scanf("%d%d", &n, &t);
    bit_2D bit(n, n);
    for (int i = 0; i < t; ++i) {
      char op;
      getchar();
      scanf("%c", &op);
      if (op == 'C') {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        bit.update(x2, y2, 1);
        bit.update(x1-1, y2, 1);
        bit.update(x2, y1-1, 1);
        bit.update(x1-1, y1-1, 1);
      } else {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", bit.sum(x, y) & 1);
      } 
    }
    printf("\n");
  }
  return 0;
}
