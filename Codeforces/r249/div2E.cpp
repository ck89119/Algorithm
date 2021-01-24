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
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CLR(a,x) memset(a,x,sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define PAU system("pause")
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) x & (-x)
#define fin freopen(".in","r",stdin)
#define fout freopen(".out","w",stdout)
//ifstream fin("");
//ofstream fout("");
#define LL long long
#define ULL unsigned long long

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN= 1000 + 5;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

int n, m;
int x[MAXN][MAXN];

int rotate() {
  int tx[MAXN][MAXN];
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      tx[j][i] = x[i][j];
  swap(n, m);
  for (int i = n; i >= 1; --i)
    for (int j = 1; j <= m; ++j)
      x[i][j] = tx[n+1-i][j];
  return 0;
}

int r(int x) {
  if (x & 1) return 1;
  else return 2;
}

int add(vector<int> &vec, int x) {
  if (x == 0) return 0;
  for (int i = 0; i < vec.size(); ++i)
    if (x == vec[i]) return 0;
  vec.push_back(x);
  return 0;
}

int firstNotUse(vector<int> &A, vector<int> &B) {
  for (int i = 1; i <= 4; ++i) {
    int in_a, in_b;
    in_a = in_b = 0;
    for (int j = 0; j < A.size(); ++j)
      if (i == A[j]) in_a = 1;
    for (int j = 0; j < B.size(); ++j)
      if (i == B[j]) in_b = 1;
    if (!in_a && !in_b) return i;
  }
  return 0;
}

int haveCommon(vector<int> &A, vector<int> &B) {
  for (int i = 1; i <= 4; ++i) {
    int in_a, in_b;
    in_a = in_b = 0;
    for (int j = 0; j < A.size(); ++j)
      if (i == A[j]) in_a = 1;
    for (int j = 0; j < B.size(); ++j)
      if (i == B[j]) in_b = 1;
    if (in_a && in_b) return 1;
  }
  return 0;
}

int solve() {
  int b[MAXN][MAXN];
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      b[i][j] = x[i][j];
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (b[i][j] != 0) {
        if (b[r(i)][j] == 0) {
          b[r(i)][j] = b[i][j];
        } else if (b[r(i)][j] != b[i][j])
          return 0;
      }
  //dump("###1$$$");
  vector<int> A, B;
  for (int i = 1; i <= 2; ++i)
    for (int j = 1; j <= m; ++j)
      if (j & 1) add(A, b[i][j]);
      else add(B, b[i][j]);
  
  if (A.size() > 2 || B.size() > 2 || haveCommon(A, B)) return 0;

  while (A.size() < 2) A.push_back(firstNotUse(A, B));
  while (B.size() < 2) B.push_back(firstNotUse(A, B));
  
  for (int j = 1; j <= m; ++j)
    if (b[1][j] == b[2][j] && b[1][j] != 0) return 0;
  //dump("###2$$$");

  for (int j = 1; j <= m; ++j) {
    if (j & 1) {
      if (b[1][j] != 0) {
        b[2][j] = A[0] + A[1] - b[1][j];
      } else if (b[2][j] != 0) {
        b[1][j] = A[0] + A[1] - b[2][j];
      } else {
        b[1][j] = A[0];
        b[2][j] = A[1];
      }
    } else {
      if (b[1][j] != 0) {
        b[2][j] = B[0] + B[1] - b[1][j];
      } else if (b[2][j] != 0) {
        b[1][j] = B[0] + B[1] - b[2][j];
      } else {
        b[1][j] = B[0];
        b[2][j] = B[1];
      }
    }
  }
  
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      x[i][j] = b[r(i)][j];

  return 1;
}

int print() {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j)
      cout << x[i][j];
    cout << endl; 
  }
  return 0;
}

int main() {
  //fin; fout;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < m; ++j)
      x[i+1][j+1] = s[j] - '0';
  }

  if (solve()) {
    print();
    return 0;
  } else {
    rotate();
    if (solve()) {
      rotate();
      rotate();
      rotate();
      print();
      return 0;
    }
  }
  cout << 0 << endl;
  return 0;
}
