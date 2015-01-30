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
#define ULL unsigned long long 

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=30 + 5;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

struct Matrix {
  int n;
  ULL m[MAXN][MAXN];
  
  Matrix() {}

  Matrix(int _n): n(_n) {
    CLR(m, 0);
  }
  
  Matrix operator*(const Matrix &a) const {
    Matrix res(n);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        for (int k = 0; k < n; ++k) {
          res.m[i][j] += m[i][k] * a.m[k][j];
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
      if (next[cur][*s-'a'] == -1) next[cur][*s-'a'] = newNode();
      cur = next[cur][*s-'a'];
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
    Matrix a(size+1);
    for (int i = 0; i < size; ++i)
      for (int j = 0; j < CHILD_NUM; ++j)
        if (!end[next[i][j]]) ++a.m[i][next[i][j]];

    for (int i = 0; i < size+1; ++i)
      a.m[i][size] = 1;
    return a;
  }

};

Trie ac;

Matrix pow_m(Matrix &a, int n) {
  Matrix tmp = a;
  Matrix res(a.n);
  for (int i = 0; i < a.n; ++i) 
    res.m[i][i] = 1;
  
  while (n) {
    if (n & 1) res = res * tmp;
    tmp = tmp * tmp;
    n >>= 1;
  }
  return res;
}

ULL pow(ULL a, int n) {
  ULL tmp = a;
  ULL res = 1;
  while (n) {
    if (n & 1) res = res * tmp;
    tmp = tmp * tmp;
    n >>= 1;
  }
  return res;
}



int main() {
  //fin; fout;
  int n, l;
  while (scanf("%d%d", &n, &l) != EOF) {
    ac.init();
    for (int i = 0; i < n; ++i) {
      char s[10];
      scanf("%s", s);
      ac.insert(s);
    }
    ac.build();
    Matrix a = ac.work();
    a = pow_m(a, l);
    
    Matrix b(2);
    b.m[0][0] = 26; b.m[0][1] = 1;
    b.m[1][0] = 0; b.m[1][1] = 1;
    b = pow_m(b, l);

    ULL ans = b.m[0][0] + b.m[0][1];
    //dump(ans);
    for (int i = 0; i < a.n; ++i)
      ans -= a.m[0][i];
    cout << ans << endl;
  }
  
  return 0;
}
