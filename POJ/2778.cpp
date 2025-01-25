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
using namespace std;
#define dump(x) cerr <<  __LINE__ << " : "<< #x << "  =  " << (x) <<endl
#define FR(i,a,b) for(int i=(a);i<(b);++i)//[a,b)
#define CLR(a,x) memset(a,x,sizeof(a)) //0:0, -1:-1, INF:0x3f, -INF:0x80
#define MP(A,B) make_pair(A,B)
#define PB(A) push_back(A)
#define PAU system("pause")
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(n) (n^(n-1))&n
#define fin freopen(".in","r",stdin)
#define fout freopen(".out","w",stdout)
//ifstream fin("");
//ofstream fout("");
#define LL long long

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN= 100 + 5;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 4;

struct Matrix {
  int m[MAXN][MAXN];
  int n;

  Matrix() {}

  Matrix(int _n): n(_n) {
    CLR(m, 0);
  }

  Matrix operator*(Matrix &b) const {
    Matrix res(n);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        for (int k = 0; k < n; ++k) {
          int tmp = (LL)m[i][k] * b.m[k][j] % 100000;
          res.m[i][j] = (res.m[i][j] + tmp) % 100000;
        }
      }
    return res;
  }
};

struct Trie {
  int next[MAXN][CHILD_NUM], fail[MAXN], end[MAXN];
  int root, size;
  
  int newNode() {
    CLR(next[size], -1);
    end[size] = 0;
    return size++;
  }
  
  int init() {
    size = 0;
    root = newNode();
    return 0;
  }

  int insert(char *s) {
    int cur = root;
    while (*s) {
      int t;
      if (*s == 'A') t = 0;
      else if (*s == 'T') t = 1;
      else if (*s == 'C') t = 2;
      else if (*s == 'G') t = 3;
      if (next[cur][t] == -1) next[cur][t] = newNode();
      cur = next[cur][t];
      ++s;
    }
    end[cur] = 1;
    return 0;
  }
  
  int build() {
    queue<int> q;
    fail[root] = root;
    for (int i = 0; i < CHILD_NUM; ++i)
      if (next[root][i] == -1) {
        next[root][i] = root;
      } else {
        fail[next[root][i]] = root;
        q.push(next[root][i]);
      }

    while (!q.empty()) {
      int cur = q.front(); q.pop();
      end[cur] |= end[fail[cur]];
      for (int i = 0; i < CHILD_NUM; ++i)
        if (next[cur][i] == -1) {
          next[cur][i] = next[fail[cur]][i];
        } else {
          fail[next[cur][i]] = next[fail[cur]][i];
          q.push(next[cur][i]);
        }
    }
    return 0;
  }
  
  Matrix work() {
    Matrix res(size);
    for (int i = 0; i < size; ++i)
      for (int j = 0; j < CHILD_NUM; ++j)
        if (!end[next[i][j]]) {
          ++res.m[i][next[i][j]];
        }
    return res;
  }

};
Trie ac;

int pow(Matrix &a, int n) {
  Matrix res(a.n);
  for (int i = 0; i < res.n; ++i)
    res.m[i][i] = 1;
  Matrix tmp = a;
  while (n) {
    if (n & 1) res = res * tmp;
    tmp = tmp * tmp;
    n >>= 1;
  }
  
  int ans = 0;
  for (int i = 0; i < res.n; ++i)
    ans = (ans + res.m[0][i]) % 100000;
  return ans;
}


int main() {
  //fin; fout;
  int m, n;
  while (~scanf("%d%d", &m, &n)) {
    ac.init();
    for (int i = 0; i < m; ++i) {
      char s[15];
      scanf("%s", s);
      ac.insert(s);
    }
    ac.build();
    
    Matrix a = ac.work();
    printf("%d\n", pow(a, n));
  }
  return 0;
}
