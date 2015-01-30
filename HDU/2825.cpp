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
const int CHILD_NUM = 26;
const int MOD = 20090717;

int n, m, k;
int dp[2][MAXN][1<<10];

//struct Matrix {
  //int n;
  //int mat[MAXN][MAXN];

  //Matrix() {}
  
  //Matrix(int _n): n(_n) {
    //CLR(mat, 0);
  //}

  //Matrix operator*(const Matrix &a) const {
    //Matrix ans(n);
    //for (int i = 0; i < n; ++i)
      //for (int j = 0; j < n; ++j)
        //for (int k = 0; k < n; ++k)
          //ans.mat[i][j] = (ans.mat[i][j] + mat[i][k] * a.mat[k][j]) % MOD;
    //return ans;
  //}
//};

int hw(int n) {
  int ans = 0;
  while (n) {
    if (n & 1) ++ans;
    n >>= 1;
  }
  return ans;
}

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

  int insert(char s[], int len, int id) {
    int cur = root;
    for (int i = 0; i < len; ++i) {
      if (next[cur][s[i]-'a'] == -1) next[cur][s[i]-'a'] = newNode();
      cur = next[cur][s[i]-'a'];
    }
    end[cur] = (1 << id);
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
      A
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

  int work() {
    int g = 0;
    CLR(dp[0], 0);
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; ++i) {
      g ^= 1; CLR(dp[g], 0);
      for (int j = 0; j < size; ++j)
        for (int k = 0; k < (1<<m); ++k)
          if (dp[g^1][j][k]) {
            for (int l = 0; l < CHILD_NUM; ++l) {
              int v = next[j][l];
              int u = k | end[v];
              dp[g][v][u] += dp[g^1][j][k];
              if (dp[g][v][u] >= MOD) dp[g][v][u] -= MOD;
            }
          }
    }
    int ans = 0;
    for (int j = 0; j < (1<<m); ++j)
      if (hw(j) >= k) {
        for (int i = 0; i < size; ++i) {
          ans += dp[g][i][j];
          if (ans >= MOD) ans -= MOD;
        }
      }
    return ans;
  }
};
Trie ac;

//int pow_m(const Matrix &a, int n) {
  //Matrix t = a;
  //for (int i = 1; i <= n; ++i) {
    //int ans = 0;
    //for (int j = 0; j < t.n; ++j) ans = (ans + t.mat[0][j]) % MOD;
    //dp[i][0] = ans;
    //t = t * a;
  //}
  //return 0;
//}


//     dp[i][j] = sigma{ dp[i-len[k]][j ^ (1<<k)] | j & (1<<k) != 0}

int main() {
  //fin; fout;
  while (scanf("%d%d%d", &n, &m, &k), n | m | k) {
    char s[15];
    ac.init();   
    for (int i = 0; i < m; ++i) {
      scanf("%s", s);
      ac.insert(s, strlen(s), i);
    }
    ac.build();
    printf("%d\n", ac.work());

  }
  return 0;
}
