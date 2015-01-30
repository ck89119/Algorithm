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
#define fin freopen("C-large.in","r",stdin)
#define fout freopen("C-large.out","w",stdout)
//ifstream fin("");
//ofstream fout("");
#define LL long long
#define ULL unsigned long long

template <class T> void out(T A[],int n){for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
template <class T> void out (vector<T> A,int n=-1){if(n==-1) n=A.size();for (int i=0;i<n;i++) cout<<A[i]<<" ";cout<<endl;}
const int MAXN=99999;
const int MAXM=9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

int button[10];
int n;
int ans;

int check(int x) {
  while (x) {
    if (button[x%10] == 0) return 0;
    x /= 10;
  }
  return 1;
}

int num(int x) {
  int cnt = 0;
  if (x == 0) return 1;
  while (x) {
    x /= 10;
    cnt++;
  }
  return cnt;
}

int dfs(int nn, int begin, int cnt) {
  if (nn == 1) {
    ans = min(ans, cnt);
    return 0;
  }

  for (int i = begin; i * i <= nn; ++i)
    if (nn % i == 0 && check(i)) {
      dfs(nn / i, i, cnt+num(i)+1);
    }
  if (check(nn)) 
    dfs(1, nn, cnt+num(nn)+1);
  return 0;
}

int main() {
  fin; fout;
  int t; 
  cin >> t;
  for (int ncase = 1; ncase <= t; ++ncase) {
    for (int i = 0; i < 10; ++i) 
      cin >> button[i];
    cin >> n;
    ans = INF;
    if (n == 1 && button[n]) ans = 2;
    else dfs(n, 2, 0);
    if (ans != INF) 
      printf("Case #%d: %d\n", ncase, ans);
    else 
      printf("Case #%d: Impossible\n", ncase);
  }
  return 0;
}
