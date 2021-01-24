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
const int N = 105;
const int M = 9999999;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double EPS=1e-11;
const int CHILD_NUM = 26;
const int MOD = 1000000007;

int n, k;
int a[N];
vector<PII> ans;

int find_max() {
  int v = -INF;
  int index;
  for (int i = 1; i <= n; ++i)
    if (a[i] > v) {
      v = a[i];
      index = i;
    }
  return index;
}

int find_min() {
  int v = INF;
  int index;
  for (int i = 1; i <= n; ++i)
    if (a[i] < v) {
      v = a[i];
      index = i;
    }
  return index;
}

int main() {
  //#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
  //#endif
  
  int sum = 0;
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    sum += a[i];
  }

  int cnt = 0;
  int mi = sum % n ? 1 : 0;
  while (cnt < k) {
    int i = find_max();
    int j = find_min();
    if (a[i] - a[j] == mi) break;
    --a[i]; ++a[j];
    ans.PB(MP(i, j));
    ++cnt;
  }
  printf("%d %d\n", a[find_max()] - a[find_min()], cnt);
  for (int i = 0; i < cnt; ++i)
    cout << ans[i].first << ' ' << ans[i].second << endl;
  return 0;
}
