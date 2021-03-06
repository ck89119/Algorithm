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
const int N = 500 + 5;
const int M = 500 + 5;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
//const int MOD = 1000000007;

int n, m;
LL MOD;
LL f[N][N];
int nn, mm;

int init() {
  int s[N];
  CLR(s, 0);
  cin >> n >> m >> MOD;
  for (int i = 0; i < m; ++i) {
    string str;
    cin >> str;
    for (int j = 0; j < str.size(); ++j)
      s[j] += str[j] - '0';
  }
  nn = mm = 0;
  for (int i = 0; i < n; ++i)
    if (s[i] == 0) ++mm;
    else if (s[i] == 1) ++nn;
  nn /= 2;
  return 0;
}

LL add(LL a, LL b) {
  a = (a + b) % MOD;
  return a;
}

LL mul(LL a, LL b) {
  a = (a * b) % MOD;
  return a;
}

LL nC2(int n) {
  return (LL)n * (n - 1) / 2 % MOD;
}

int dp() {
  CLR(f, 0);
  f[0][0] = 1;
  for (int i = 1; i <= nn + mm; ++i)
    f[i][0] = mul(f[i-1][0], nC2(2 * i));
  f[0][1] = 0;
  for (int i = 1; i <= nn + mm; ++i)
    f[i][1] = add(f[i-1][1] * nC2(2 * i), f[i][0] * 2 * i) % MOD;
  for (int l = 2; l <= mm + nn; ++l) {
    for (int i = l - 2; i > 0; --i) {
      int j = l - i;
      f[i][j] = add(f[i][j], mul(f[i-1][j], nC2(2 * i)));
      f[i][j] = add(f[i][j], mul(f[i+1][j-2], nC2(j)));
      f[i][j] = add(f[i][j], mul(f[i][j-1], (i + i) * j));
    }
    f[0][l] = mul(f[1][l-2], nC2(l));
  }
  return 0;
}

int main() {
  #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  #endif
  
  init();
  dp();
  //for (int i = 0; i <= mm + nn; ++i) out(f[i], mm + nn + 1);
  cout << f[nn][mm] << endl;
  return 0;
}
