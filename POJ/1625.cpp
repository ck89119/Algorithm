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
const int CHILD_NUM = 55;
const int MOD = 1000000007;

map<char, int> mp;
int n, m, p;

struct BigInt {
  int s[1005];
  int len;

  BigInt() {
    len = 1;
    CLR(s, 0);
  }

  int operator=(int n) {
    CLR(s, 0);
    if (n == 0) {
      len = 1;
      return 0;
    }

    len = 0;
    while (n) {
      s[len++] = n % 10;
      n /= 10;
    }
    return 0;
  }

  BigInt operator+(const BigInt &a) {
    BigInt ans;
    ans.len = max(len, a.len);
    for (int i = 0; i < ans.len; ++i)
      ans.s[i] = s[i] + a.s[i];
    for (int i = 0; i < ans.len; ++i)
      if (ans.s[i] >= 10) {
        ans.s[i+1] += 1;
        ans.s[i] -= 10;
      }
    if (ans.s[ans.len] > 0) ++ans.len;
    return ans;
  }

  BigInt operator*(int n) {
    BigInt ans;
    if (n == 0) {
      ans = 0;
      return ans;
    }
    ans.len = len;
    for (int i = 0; i < ans.len; ++i)
      ans.s[i] = s[i] * n;
    for (int i = 0; i < ans.len; ++i)
      if (ans.s[i] >= 10) {
        ans.s[i+1] += ans.s[i] / 10;
        ans.s[i] %= 10;
      }
    if (ans.s[ans.len] > 0) ++ans.len;
    return ans;
  }

  friend ostream &operator<<(ostream &os, const BigInt &a) {
    for (int i = a.len - 1; i >= 0; --i)
      os << a.s[i];
    return os;
  }
};


struct Matrix {
  int n;
  int m[MAXN][MAXN];
  
  Matrix() {}
  
  Matrix(int _n): n(_n) {
    CLR(m, 0);
  }
  
  Matrix operator*(const Matrix &b) const {
    Matrix ans(n);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        for (int k = 0; k < n; ++k)
          ans.m[i][j] += m[i][k] * b.m[k][j];
    return ans;
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
  
  int insert(char s[], int len) {
    int cur = root;
    for (int i = 0; i < len; ++i) {
      int v = mp[s[i]];
      if (next[cur][v] == -1) next[cur][v] = newNode();
      cur = next[cur][v];
    }
    end[cur] = 1;
    return 0;
  }

  int build() {
    queue<int> q;
    fail[root] = root;
    for (int i = 0; i < n; ++i)
      if (next[root][i] == -1) {
        next[root][i] = root;
      } else {
        fail[next[root][i]] = root;
        q.push(next[root][i]);
      }
     
    while (!q.empty()) {
      int cur = q.front(); q.pop();
      if (end[fail[cur]]) end[cur] = 1;
      for (int i = 0; i < n; ++i) {
        if (next[cur][i] == -1) {
          next[cur][i] = next[fail[cur]][i];
        } else {
          fail[next[cur][i]] = next[fail[cur]][i];
          q.push(next[cur][i]);
        }  
      }
    }
    return 0;
  }
  
  Matrix work() {
    Matrix ans(size);
    for (int i = 0; i < size; ++i)
      for (int j = 0; j < n; ++j) {
        //dump(i); dump(j); dump(next[i][j]);
        if (!end[next[i][j]]) {
          ++ans.m[i][next[i][j]];
        }
      }
    return ans;
  }
};
Trie ac;
BigInt dp[2][MAXN];
char s[55];

int main() {
  scanf("%d%d%d", &n, &m, &p);
  ac.init();
  gets(s); gets(s);
  mp.clear();
  for (int i = 0; i < n; ++i)
    mp[s[i]] = i;
  for (int i = 0; i < p; ++i) {
    gets(s);
    ac.insert(s, strlen(s));
  }
  ac.build();
  Matrix a = ac.work();
/*  for (int i = 0; i < a.n; ++i) {*/
    //for (int j = 0; j < a.n; ++j)
      //cout << a.m[i][j] << ' ';
    //cout << endl;
  /*}*/

  int g = 0;
  for (int i = 0; i < a.n; ++i) dp[0][i] = 1;
  for (int i = 0; i < m; ++i) {
    g ^= 1;
    for (int ii = 0; ii < a.n; ++ii) dp[g][ii] = 0;
    for (int ii = 0; ii < a.n; ++ii)
      for (int jj = 0; jj < a.n; ++jj)
        dp[g][ii] = dp[g][ii] + dp[g^1][jj] * a.m[ii][jj];
    //for (int ii = 0; ii < a.n; ++ii) cout << dp[g][ii] << ' '; cout << endl;
  }

  //BigInt ans;
  //ans = 0;
  //for (int i = 0; i < a.n; ++i)
    //ans = ans + dp[g][i];
  cout << dp[g][0] << endl;

  return 0;
}
